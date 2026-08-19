/*
 * menu_secuencia.c
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
 *
*/

#include <stdio.h>
#include "matriz.h"
#include "secuencia.h"
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "boton.h"
#include "menu_secuencia.h"
#include "estado.h"

static Secuencia_t* secuenciaActual = NULL;
static Matriz_t* matrizActual = NULL;
static char seleccion[3] = {'*', ' '};
static int indiceSeleccion = 0;

// Pantalla "mostrar secuencia"
#define TIEMPO_MOSTRAR_SECCION_MS 1000 //Originalmente 2000

static uint8_t indiceMostrando = 0;
static uint32_t tiempoUltimaSeccion = 0;
static bool mostrandoIniciado = false;

// Estado de error al completar la secuencia
static bool secuenciaFallo = false;
static uint32_t tiempoFallo = 0;

// Estado de victoria al completar la secuencia
static bool secuenciaVictoria = false;
static uint32_t tiempoVictoria = 0;

// Orden en que el usuario debe pintar las secciones
// Cuenta cuántas secciones "encendidas" (listaSec[0][pos] != 0) ya pintó el
// usuario correctamente, en el mismo orden en que se mostraron (de menor a mayor
// índice). Se reinicia en cada intento nuevo, dentro de menuSecuenciaMostrarEntrar.
static uint8_t ordenContador = 0;

// Devuelve la posición (0..CANT_ELEMENTOS-1) de la próxima sección encendida que el
// usuario debe pintar,
static uint8_t menuSecuenciaPosicionEsperada(uint8_t contador) {
    uint8_t encontrados = 0;
    for (uint8_t pos = 0; pos < CANT_ELEMENTOS; pos++) {
        if (secuenciaActual->listaSec[0][pos] != 0) {
            if (encontrados == contador) {
                return pos;
            }
            encontrados++;
        }
    }
    return CANT_ELEMENTOS; // No debería ocurrir: ya se habría completado la secuencia antes
}

void menuSecuenciaEntrar(void) {
    if (secuenciaActual == NULL) {
        secuenciaActual = secuenciaCrear();
        if (secuenciaActual == NULL) {

        	sistemaCambiarOperacion(ESTADO_FALLA);
            return;
        }
    }
    if (matrizActual == NULL) {
        matrizActual = matrizCrear();
        if (matrizActual == NULL) {

            secuenciaBorrar(secuenciaActual);
            secuenciaActual = NULL;
            sistemaCambiarOperacion(ESTADO_FALLA);
            return;
        }
    }

    indiceSeleccion = 0;
    seleccion[0] = '*';
    seleccion[1] = ' ';
    menuSecuenciaPrint(seleccion, indiceSeleccion);
}

void menuSecuenciaPrint(char seleccion[3], int indice_seleccion) {
	lcdVaciarBuffer();

    char mensaje0[LCD_COLUMNAS];
    char mensaje1[LCD_COLUMNAS];

    snprintf(mensaje0, sizeof(mensaje0), "(%c) Jugar Sec.", seleccion[0]);
    snprintf(mensaje1, sizeof(mensaje1), "(%c) Borrar Sec,", seleccion[1]);

    lcdBufferearLinea(0, mensaje0);
    lcdBufferearLinea(1, mensaje1);

}

void menuSecuenciaOpcionElegida(int indice_seleccion) {
    switch (indice_seleccion) {
        case 0: // Jugar Secuencia -> primero se muestra la secuencia objetivo
        	secuenciaVaciar(secuenciaActual); // Empiezo el intento sin nada pintado por el usuario
            sistemaCambiarEstado(ESTADO_MOSTRANDO_SECUENCIA);
            break;
        case 1: // Limpiar Secuencia
        	lcdVaciarBuffer();

			lcdBufferearLinea(0, "Estas seguro?");
			lcdBufferearLinea(1, "-> Aceptar");
			lcdBufferearLinea(2, "-> Atras");
			sistemaCambiarEstado(ESTADO_LIMPIAR_SECUENCIA);
            break;
        default:
            break;
    }
}

void menuSecuenciaTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ABAJO:
        case BOTON_ARRIBA:
            seleccion[indiceSeleccion] = ' ';
            indiceSeleccion = (indiceSeleccion == 1) ? 0 : 1;
            seleccion[indiceSeleccion] = '*';

            menuSecuenciaPrint(seleccion, indiceSeleccion);
            break;
        case BOTON_ACEPTAR:
        	seleccion[indiceSeleccion] = ' ';
            menuSecuenciaOpcionElegida(indiceSeleccion);
            break;
        case BOTON_ATRAS:
            secuenciaBorrar(secuenciaActual);
            matrizLlenar(matrizActual, 0, 0, 0);
            matrizBorrar(matrizActual);
            secuenciaActual = NULL;
            matrizActual = NULL;
            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            break;
        default:
            break;
    }
}

// Prepara la pantalla de mostrado: limpia la matriz y reinicia el índice de sección.
// La primera sección se pinta recién en el primer llamado a menuSecuenciaMostrarTick,
// para no depender de HAL_GetTick() antes de cambiar de estado.
void menuSecuenciaMostrarEntrar(void) {
    indiceMostrando = 0;
    mostrandoIniciado = false;
    ordenContador = 0;

    lcdVaciarBuffer();
    lcdBufferearLinea(0, "Memoriza la");
    lcdBufferearLinea(1, "Secuencia");

    matrizLlenar(matrizActual, 0, 0, 0);
    frameBufferUpdateAll(matrizActual);
}

// usa HAL_GetTick() (mismo patrón de debounce que ya se usaba en
// menuSecuenciaCompletarTick) para ir pintando de azul, una por una, las secciones de
// listaSec[0] que están "encendidas", con ~2s de por medio.
void menuSecuenciaMostrarTick(void) {

    uint32_t ahora = HAL_GetTick();

    if (!mostrandoIniciado) {
        uint8_t objetivo = secuenciaActual->listaSec[0][indiceMostrando];
        if (objetivo != 0) {
            secuenciaPintarSeccion(matrizActual, indiceMostrando, 0, 0, 255); // AZUL
            frameBufferUpdateAll(matrizActual);
        }
        tiempoUltimaSeccion = ahora;
        mostrandoIniciado = true;
        return;
    }

    if ((ahora - tiempoUltimaSeccion) < TIEMPO_MOSTRAR_SECCION_MS) {
        return; // Todavia no pasaron los ~2 segundos de esta sección
    }

    // Apago la sección anterior antes de mostrar la siguiente
    secuenciaPintarSeccion(matrizActual, indiceMostrando, 0, 0, 0);
    frameBufferUpdateAll(matrizActual);
    indiceMostrando++;

    if (indiceMostrando >= CANT_ELEMENTOS) {
        // Terminé de mostrar toda la secuencia: arranca el turno del usuario
        matrizLlenar(matrizActual, 0, 0, 0);
        secuenciaActual->indiceSec = 0;
        secuenciaPintarSeccion(matrizActual, 0, 250, 0, 0); // cursor inicial
        frameBufferUpdateAll(matrizActual);

        lcdVaciarBuffer();
		lcdBufferearLinea(0, "Repeti Secuencia");
		lcdBufferearLinea(2, "Presione atras");
		lcdBufferearLinea(3, "Para salir");

        sistemaCambiarEstado(ESTADO_COMPLETANDO_SECUENCIA);
        return;
    }

    uint8_t objetivo = secuenciaActual->listaSec[0][indiceMostrando];
    if (objetivo != 0) {
        secuenciaPintarSeccion(matrizActual, indiceMostrando, 0, 0, 255); // AZUL
        frameBufferUpdateAll(matrizActual);
        tiempoUltimaSeccion = ahora;
    }

}

void menuSecuenciaCompletarTick(BotonEvento_t input) {

	// La matriz ya se pintó toda de rojo al detectar el error (ver caso BOTON_ACEPTAR).
	// Espero un ratito para que el usuario vea el rojo y reinicio el intento mostrando
	// la secuencia objetivo de nuevo, igual que hace el caso de éxito más abajo.
	if (secuenciaFallo) {
		if ((HAL_GetTick() - tiempoFallo) > DEBOUNCE_MS * 40) {
			secuenciaFallo = false;
			secuenciaVaciar(secuenciaActual);
			menuSecuenciaMostrarEntrar();
			sistemaCambiarEstado(ESTADO_MOSTRANDO_SECUENCIA);
		}
		return;
	}

	if (secuenciaCompleta(secuenciaActual)) {
		if (!secuenciaVictoria){
			secuenciaVictoria = true;
			tiempoVictoria = HAL_GetTick();
			lcdVaciarBuffer();
			lcdBufferearLinea(0, "Secuencia Completa :)");
			lcdBufferearLinea(1, "Toca un boton");
			matrizLlenar(matrizActual, 0, 255, 0); // Toda la matriz VERDE
			frameBufferUpdateAll(matrizActual);
		}

        if ((HAL_GetTick() - tiempoVictoria) > DEBOUNCE_MS * 40) {
			matrizLlenar(matrizActual, 0, 0, 0);
        	sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
        	return;
		} else {
			tiempoVictoria = HAL_GetTick();
			return;
		}
    }

	switch (input) {
        case BOTON_ARRIBA:
        case BOTON_ABAJO:
        case BOTON_IZQUIERDA:
        case BOTON_DERECHA:
            secuenciaAvanzar(secuenciaActual, input, matrizActual);
            if (matrizActual != NULL) {
				secuenciaPintarSeccion(matrizActual, secuenciaActual->indiceSec, 250, 0, 0); //Cursor
				frameBufferUpdateAll(matrizActual);
			}
            menuSecuenciaCompletandoPrint(input);
            break;
        case BOTON_ACEPTAR: {
            uint8_t idx = secuenciaActual->indiceSec;
            uint8_t fil = (idx / DIM_SECUENCIA) * TAM_PINCEL_SECUENCIA;
            uint8_t col = (idx % DIM_SECUENCIA) * TAM_PINCEL_SECUENCIA;
            uint8_t esperado = menuSecuenciaPosicionEsperada(ordenContador);

            if (idx == esperado) {
                // Acierto Y en el orden correcto: marco la sección y la pinto de verde
                secuenciaInsertarElemento(secuenciaActual, 255, matrizActual, fil, col);
                secuenciaPintarSeccion(matrizActual, idx, 0, 255, 0); // VERDE
                ordenContador++;

                /* Redibujo el cursor porque a veces se tapa
                for (uint8_t i = 0; i < TAM_PINCEL_SECUENCIA; i++) {
                    for (uint8_t j = 0; j < TAM_PINCEL_SECUENCIA; j++) {
                        matrizSetCasillero(matriz_actual, fil + i, col + j, 250, 0, 0);
                    }
                }*/
                frameBufferUpdateAll(matrizActual);
            } else {
                // Error: sección equivocada o fuera del orden mostrado
                matrizLlenar(matrizActual, 255, 0, 0); // Toda la matriz ROJA
                frameBufferUpdateAll(matrizActual);

                lcdVaciarBuffer();
				lcdBufferearLinea(0, "Error! :(");
				lcdBufferearLinea(1, "Reintentando...");

                secuenciaFallo = true;
                tiempoFallo = HAL_GetTick();
            }
            break;
        }
        case BOTON_ATRAS:
            sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
            lcdBorrar();
            menuSecuenciaPrint(seleccion, indiceSeleccion); // reimprime el menú al volver
            return;
        default:
            break;
    }


}

Matriz_t* menuSecuenciaObtenerMatriz(void) {
    return matrizActual;
}

void menuSecuenciaCompletandoPrint(BotonEvento_t input) {
	lcdVaciarBuffer();
	lcdBufferearLinea(0, "Repeti Secuencia");
	lcdBufferearLinea(2, "Presione atras");
	lcdBufferearLinea(3, "Para salir");

	switch (input) {
	case BOTON_ARRIBA:
		lcdBufferearLinea(1, "-> Arriba");
		break;
	case BOTON_ABAJO:
		lcdBufferearLinea(1, "-> Abajo");
		break;
	case BOTON_DERECHA:
		lcdBufferearLinea(1, "-> Derecha");
		break;
	case BOTON_IZQUIERDA:
		lcdBufferearLinea(1, "-> Izquierda");
		break;
	default:
		break;
	}
}


void menuSecuenciaLimpiandoTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ACEPTAR:
        	matrizLlenar(matrizActual, 0, 0, 0);
			frameBufferUpdateAll(matrizActual);
			secuenciaVaciar(secuenciaActual);

			sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);

            break;
        case BOTON_ATRAS:
        	sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
            break;
        default:
            break;
    }
}
