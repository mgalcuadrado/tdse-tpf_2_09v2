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

static Secuencia_t* secuencia_actual = NULL;
static Matriz_t* matriz_actual = NULL;
static char seleccion[3] = {'*', ' '};
static int indice_seleccion = 0;

// --- Pantalla "mostrar secuencia" ---
#define TIEMPO_MOSTRAR_SECCION_MS 3000

static uint8_t indice_mostrando = 0;
static uint32_t tiempo_ultima_seccion = 0;
static bool mostrando_iniciado = false;

// --- Estado de error al completar la secuencia ---
static bool secuencia_fallo = false;
static uint32_t tiempo_fallo = 0;

void menuSecuenciaEntrar(void) {
    if (secuencia_actual == NULL) {
        secuencia_actual = secuenciaCrear();
        if (secuencia_actual == NULL) {

            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            return;
        }
    }
    if (matriz_actual == NULL) {
        matriz_actual = matrizCrear();
        if (matriz_actual == NULL) {

            secuenciaBorrar(secuencia_actual);
            secuencia_actual = NULL;
            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            return;
        }
    }

    indice_seleccion = 0;
    seleccion[0] = '*';
    seleccion[1] = ' ';
    lcdBorrar();
    menuSecuenciaPrint(seleccion, indice_seleccion);
}

void menuSecuenciaPrint(char seleccion[3], int indice_seleccion) {
    char mensaje1[MAX_CARACTERES_MENSAJE];
    char mensaje2[MAX_CARACTERES_MENSAJE];

    snprintf(mensaje1, sizeof(mensaje1), "(%c) Jugar Secuencia", seleccion[0]);
    snprintf(mensaje2, sizeof(mensaje2), "(%c) Borrar Secuencia", seleccion[1]);

    lcdSetearCursor(0, 0);
    lcdPrint(mensaje1);

    lcdSetearCursor(0, 1);
    lcdPrint(mensaje2);
}

void menuSecuenciaOpcionElegida(int indice_seleccion) {
    switch (indice_seleccion) {
        case 0: // Jugar Secuencia -> primero se muestra la secuencia objetivo
        	secuenciaVaciar(secuencia_actual); // Empiezo el intento sin nada pintado por el usuario
        	menuSecuenciaMostrarEntrar();
            sistemaCambiarEstado(ESTADO_MOSTRANDO_SECUENCIA);
            break;
        case 1: // Limpiar Secuencia
        	lcdBorrar();
			lcdSetearCursor(0, 0);
			lcdPrint("Estas seguro?");
			lcdSetearCursor(0, 1);
			lcdPrint("Aceptar");
			lcdSetearCursor(0, 2);
			lcdPrint("Atras");
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
            seleccion[indice_seleccion] = ' ';
            indice_seleccion = (indice_seleccion == 1) ? 0 : 1;
            seleccion[indice_seleccion] = '*';
            lcdBorrar();
            menuSecuenciaPrint(seleccion, indice_seleccion);
            break;
        case BOTON_ACEPTAR:
        	seleccion[indice_seleccion] = ' ';
            menuSecuenciaOpcionElegida(indice_seleccion);
            break;
        case BOTON_ATRAS:
        	seleccion[indice_seleccion] = ' ';
            secuenciaBorrar(secuencia_actual);
            matrizBorrar(matriz_actual);
            secuencia_actual = NULL;
            matriz_actual = NULL;
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
    indice_mostrando = 0;
    mostrando_iniciado = false;

    lcdBorrar();
    lcdSetearCursor(0, 0);
    lcdPrint("Memoriza la");
    lcdSetearCursor(0, 1);
    lcdPrint("Secuencia");

    matrizLlenar(matriz_actual, 0, 0, 0);
    frameBufferUpdateAll(matriz_actual);
}

// Tick no bloqueante: usa HAL_GetTick() (mismo patrón de debounce que ya se usaba en
// menuSecuenciaCompletarTick) para ir pintando de azul, una por una, las secciones de
// lista_sec[0] que están "encendidas", con ~3s de por medio. No usa HAL_Delay ya que
// esta función se llama repetidamente desde el loop principal / dispatcher de estados.
void menuSecuenciaMostrarTick(void) {

    uint32_t ahora = HAL_GetTick();

    if (!mostrando_iniciado) { //Primera seccion de la secuencia a completar
        uint8_t objetivo = secuencia_actual->lista_sec[0][indice_mostrando];
        if (objetivo != 0) {
            secuenciaPintarSeccion(matriz_actual, indice_mostrando, 0, 0, 255); // AZUL
            frameBufferUpdateAll(matriz_actual);
        }
        tiempo_ultima_seccion = ahora;
        mostrando_iniciado = true;
        return;
    }

    if ((ahora - tiempo_ultima_seccion) < TIEMPO_MOSTRAR_SECCION_MS) {
        return; // Todavia no pasaron los 3 segundos de esta sección
    }

    // Apago la sección anterior antes de mostrar la siguiente
    secuenciaPintarSeccion(matriz_actual, indice_mostrando, 0, 0, 0);
    indice_mostrando++;

    if (indice_mostrando >= CANT_ELEMENTOS) {
        // Terminé de mostrar toda la secuencia: arranca el turno del usuario
        matrizLlenar(matriz_actual, 0, 0, 0);
        secuencia_actual->indice_sec = 0;
        secuenciaPintarSeccion(matriz_actual, 0, 250, 0, 0); // cursor inicial
        frameBufferUpdateAll(matriz_actual);

        lcdBorrar();
        lcdSetearCursor(0, 0);
        lcdPrint("Repeti Secuencia");
        lcdSetearCursor(0, 2);
        lcdPrint("Presione atras");
        lcdSetearCursor(0, 3);
        lcdPrint("Para salir");

        sistemaCambiarEstado(ESTADO_COMPLETANDO_SECUENCIA);
        return;
    }

    uint8_t objetivo = secuencia_actual->lista_sec[0][indice_mostrando];
    if (objetivo != 0) {
        secuenciaPintarSeccion(matriz_actual, indice_mostrando, 0, 0, 255); // AZUL
    }
    frameBufferUpdateAll(matriz_actual);
    tiempo_ultima_seccion = ahora;
}

void menuSecuenciaCompletarTick(BotonEvento_t input) {

	// La matriz ya se pintó toda de rojo al detectar el error (ver caso BOTON_ACEPTAR).
	// Espero un ratito para que el usuario vea el rojo y reinicio el intento mostrando
	// la secuencia objetivo de nuevo, igual que hace el caso de éxito más abajo.
	if (secuencia_fallo) {
		if ((HAL_GetTick() - tiempo_fallo) > DEBOUNCE_MS * 40) {
			secuencia_fallo = false;
			secuenciaVaciar(secuencia_actual);
			menuSecuenciaMostrarEntrar();
			sistemaCambiarEstado(ESTADO_MOSTRANDO_SECUENCIA);
		}
		return;
	}

	if (secuenciaCompleta(secuencia_actual)) {
    	lcdBorrar();
        lcdSetearCursor(0, 0);
        lcdPrint("Secuencia Completa :)");
		lcdSetearCursor(0, 1);
		lcdPrint("Toca un boton");
        static uint32_t ultimoTiempo = 0;
        if ((HAL_GetTick() - ultimoTiempo) > DEBOUNCE_MS * 40) {
			sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
		} else {
			ultimoTiempo = HAL_GetTick();
			return;
		}
    }

	switch (input) {
        case BOTON_ARRIBA:
        case BOTON_ABAJO:
        case BOTON_IZQUIERDA:
        case BOTON_DERECHA:
            secuenciaAvanzar(secuencia_actual, input, matriz_actual);
            break;
        case BOTON_ACEPTAR: {
            uint8_t idx = secuencia_actual->indice_sec;
            uint8_t fil = (idx / DIM_SECUENCIA) * TAM_PINCEL_SECUENCIA;
            uint8_t col = (idx % DIM_SECUENCIA) * TAM_PINCEL_SECUENCIA;
            uint8_t objetivo = secuencia_actual->lista_sec[0][idx];

            if (secuenciaElementoActual(secuencia_actual) != 0) {
                // Esta sección ya estaba pintada correctamente (verde); no hago nada más.
                break;
            }

            if (objetivo != 0) {
                // Acierto: marco la sección como resuelta y la pinto de verde
                secuenciaInsertarElemento(secuencia_actual, 255, matriz_actual, fil, col);
                frameBufferUpdateAll(matriz_actual);

                secuenciaPintarSeccion(matriz_actual, idx, 0, 255, 0); // VERDE
                frameBufferUpdateAll(matriz_actual);

                // Redibujo el cursor porque a veces se tapa
                for (uint8_t i = 0; i < TAM_PINCEL_SECUENCIA; i++) {
                    for (uint8_t j = 0; j < TAM_PINCEL_SECUENCIA; j++) {
                        matrizSetCasillero(matriz_actual, fil + i, col + j, 250, 0, 0);
                    }
                }
                frameBufferUpdateAll(matriz_actual);
            } else {
                // Error: el usuario pintó una sección que no correspondía a la secuencia
                matrizLlenar(matriz_actual, 255, 0, 0); // Toda la matriz ROJA
                frameBufferUpdateAll(matriz_actual);

                lcdBorrar();
                lcdSetearCursor(0, 0);
                lcdPrint("Error! :(");
                lcdSetearCursor(0, 1);
                lcdPrint("Reintentando...");

                secuencia_fallo = true;
                tiempo_fallo = HAL_GetTick();
            }
            break;
        }
        case BOTON_ATRAS:
            sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
            lcdBorrar();
            menuSecuenciaPrint(seleccion, indice_seleccion); // reimprime el menú al volver
            return;
        default:
            break;
    }


}

Matriz_t* menuSecuenciaObtenerMatriz(void) {
    return matriz_actual;
}



void menuSecuenciaLimpiandoTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ACEPTAR:
        	matrizLlenar(matriz_actual, 0, 0, 0);
			frameBufferUpdateAll(matriz_actual);
			secuenciaVaciar(secuencia_actual);

			sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);

            break;
        case BOTON_ATRAS:
        	sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
            break;
        default:
            break;
    }
}
