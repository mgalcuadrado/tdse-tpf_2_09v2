/*
 * menu_dibujo.c
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
 * Migrado a no bloqueante: Ago 2026
*/

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "dibujo.h"
#include "boton.h"
#include "menu_dibujo.h"
#include "estado.h"
#include "potenciometro.h"

static Dibujo_t* dibujoActual = NULL;
static char seleccion[6] = {'*', ' ', ' ', ' ', ' '}; // 5 opciones + \n
static int indiceSeleccion = 0;
static bool pincelCambiado = false;

static bool memoriaEnProceso = false;
static uint32_t tiempoMemoria = 0;

#define TIEMPO_MOSTRAR_SECCION_MS 1000 //300ms para guardar

void menuDibujoEntrar(void) {
    // El dibujo se crea una sola vez (la primera vez que se entra al menú)
    // y se mantiene vivo mientras se navega entre Dibujar/Cambiar Pincel/etc.
    if (dibujoActual == NULL) {
        dibujoActual = dibujoCrear();
        if (dibujoActual == NULL) {
        	sistemaCambiarOperacion(ESTADO_FALLA);
            return;
        }
        frameBufferUpdateAll(dibujoActual->matriz);
    }

    indiceSeleccion = 0;
    seleccion[0] = '*';
    menuDibujoMostrar(seleccion, indiceSeleccion);
}

void menuDibujoMostrar(char seleccion[6], int indice_seleccion) {
	//lcdVaciarBuffer();
    char mensaje0[LCD_COLUMNAS];
    char mensaje1[LCD_COLUMNAS];
    char mensaje2[LCD_COLUMNAS];

    if (indice_seleccion < 3) {
        snprintf(mensaje0, sizeof(mensaje0), "(%c) Dibujar", seleccion[0]);
        snprintf(mensaje1, sizeof(mensaje1), "(%c) Nuevo Dibujo", seleccion[1]);
        snprintf(mensaje2, sizeof(mensaje2), "(%c) Guardar Dibujo", seleccion[2]);

        lcdBufferearLinea(0, mensaje0);
        lcdBufferearLinea(1, mensaje1);
        lcdBufferearLinea(2, mensaje2);
        lcdBufferearLinea(3, " ");


    } else if (2 < indice_seleccion && indice_seleccion < 5) {
        snprintf(mensaje0, sizeof(mensaje0), "(%c) Cargar Dibujo", seleccion[3]);
        snprintf(mensaje1, sizeof(mensaje1), "(%c) Cambiar Pincel", seleccion[4]);

        lcdBufferearLinea(0, mensaje0);
		lcdBufferearLinea(1, mensaje1);
		lcdBufferearLinea(2, " ");
		lcdBufferearLinea(3, " ");
    } else {
    	sistemaCambiarOperacion(ESTADO_FALLA);
    }
}

void menuDibujoOpcionElegida(int indice_seleccion) {
    switch (indice_seleccion) {
        case 0: // Dibujar
        	lcdVaciarBuffer();
			lcdBufferearLinea(0, "Dibujando...");
			lcdBufferearLinea(2, "Presione atras");
			lcdBufferearLinea(3, "para salir");
            sistemaCambiarEstado(ESTADO_DIBUJANDO);
            break;
        case 1: // Nuevo Dibujo (Te manda a pedir confirmacion)
        	lcdVaciarBuffer();
			lcdBufferearLinea(0, "Estas seguro?");
			lcdBufferearLinea(1, "-> Aceptar");
			lcdBufferearLinea(2, "-> Atras");
			sistemaCambiarEstado(ESTADO_LIMPIAR_DIBUJO);
            break;

        case 2: // Guardar Dibujo
        	sistemaCambiarEstado(ESTADO_GUARDANDO_DIBUJO);
        	break;
        case 3: // Cargar Dibujo
            sistemaCambiarEstado(ESTADO_CARGANDO_DIBUJO);
            break;
        case 4: // Cambiar Pincel -> transición de estado
            sistemaCambiarEstado(ESTADO_CAMBIANDO_PINCEL);
            break;
        default:
            break;
    }
}

void menuDibujoTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ABAJO:
            seleccion[indiceSeleccion] = ' ';
            indiceSeleccion = (indiceSeleccion >= 4) ? 0 : indiceSeleccion + 1;
            seleccion[indiceSeleccion] = '*';

            menuDibujoMostrar(seleccion, indiceSeleccion);
            break;
        case BOTON_ARRIBA:
            seleccion[indiceSeleccion] = ' ';
            indiceSeleccion = (indiceSeleccion <= 0) ? 4 : indiceSeleccion - 1;
            seleccion[indiceSeleccion] = '*';

            menuDibujoMostrar(seleccion, indiceSeleccion);
            break;
        case BOTON_ACEPTAR:
        	seleccion[indiceSeleccion] = ' ';
            menuDibujoOpcionElegida(indiceSeleccion);
            break;
        case BOTON_ATRAS:
        	dibujoReiniciar(dibujoActual);
        	seleccion[indiceSeleccion] = ' ';
            dibujoBorrar(dibujoActual);
            dibujoActual = NULL;
            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            break;
        default:
            break;
    }
}

void menuDibujoDibujarTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ARRIBA:
        case BOTON_ABAJO:
        case BOTON_IZQUIERDA:
        case BOTON_DERECHA:
        	dibujoPintar(dibujoActual,dibujoActual->colorAnterior->r, dibujoActual->colorAnterior->g,dibujoActual->colorAnterior->b);
            dibujoAvanzar(dibujoActual, input);

            menuDibujoDibujarPrint(input);
            break;
        case BOTON_ACEPTAR:
            // Lectura de potes para obtener valores R, G y B
            // dibujoPintar(dibujo_actual, r, g, b);
            // frameBufferUpdate(dibujo_actual->matriz);
        	// uint8_t r = 255;
        	// uint8_t g = 0; 	//Serian igualados a potenciometrosLeer();
			// uint8_t b = 0;
			Potenciometros_t valores = obtenerPotenciometros();
        	dibujoActual->colorAnterior->r = valores.r;
			dibujoActual->colorAnterior->g = valores.g;
			dibujoActual->colorAnterior->b = valores.b;
			char mensaje1[LCD_COLUMNAS];
			snprintf(mensaje1, sizeof(mensaje1), "r %d g %d b %d", valores.r, valores.g, valores.b);
			lcdVaciarBuffer();
			lcdBufferearLinea(0, "Patron RGB:");
			lcdBufferearLinea(1, mensaje1);
			// Se redibuja el cursor porque a veces se tapa
			uint8_t baseFil = (dibujoActual->indiceFil/dibujoActual->tamPincel) * dibujoActual->tamPincel;
			uint8_t baseCol = (dibujoActual->indiceCol/dibujoActual->tamPincel) * dibujoActual->tamPincel;
			for (uint8_t i = 0; i < dibujoActual->tamPincel; i++) {
				for(uint8_t j = 0; j < dibujoActual->tamPincel; j++) {
					matrizSetCasillero(dibujoActual->matriz, baseFil + i, baseCol + j, 250, 0, 0);
				}
			}

			frameBufferUpdateAll(dibujoActual->matriz); // Check
            break;
        case BOTON_ATRAS:
            sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
            menuDibujoMostrar(seleccion, indiceSeleccion); // reimprime el menú al volver
            break;
        default:
            break;
    }
}

void menuDibujoDibujarPrint(BotonEvento_t input) {
	lcdVaciarBuffer();
	lcdBufferearLinea(0, "Dibujando...");
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

void menuDibujoGuardando() {
	uint32_t ahora = HAL_GetTick();

	if (memoriaEnProceso){
		if ((ahora - tiempoMemoria) < TIEMPO_MOSTRAR_SECCION_MS && memoriaEnProceso) {
			return; // Todavia no pasaron los ~1 segundos de esta sección
		}
		memoriaEnProceso = false;
		sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
		return;
	}

	if (memEstaOcupada()) {
		lcdVaciarBuffer();
		lcdBufferearLinea(1, "Memoria Ocupada!");
		return;
	} else {
		memoriaEnProceso = true;
		tiempoMemoria = HAL_GetTick();
		lcdVaciarBuffer();
		lcdBufferearLinea(1, "Guardando. . .");
		if (!memBufferearEscrituraMatriz(0x0000, dibujoActual->matriz)) {
			lcdBufferearLinea(2, "Error al Guardar");
			sistemaCambiarOperacion(ESTADO_FALLA);
		} else {
			lcdBufferearLinea(2, "Guardado Exitoso!");
		}
		return;
	}
}

void menuDibujoCargando() {
	uint32_t ahora = HAL_GetTick();

	if (memoriaEnProceso){
		if ((ahora - tiempoMemoria) < TIEMPO_MOSTRAR_SECCION_MS && memoriaEnProceso) {
			return; // Todavia no pasaron los ~1 segundos de esta sección
		}
		memoriaEnProceso = false;
		sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
		return;
	}

	if (memEstaOcupada()) {
		lcdVaciarBuffer();
		lcdBufferearLinea(1, "Memoria Ocupada!");
		return;
	} else {
		memoriaEnProceso = true;
		tiempoMemoria = HAL_GetTick();
		lcdVaciarBuffer();
		lcdBufferearLinea(1, "Cargando...");
		if (memLeerMatriz(0x0000, dibujoActual->matriz) == HAL_OK) {
			frameBufferUpdateAll(dibujoActual->matriz);
			lcdBufferearLinea(2, "Carga Exitosa!");
		} else {
			lcdBufferearLinea(2, "Error al Cargar");
		}
		return;
	}
}


void menuDibujoCambiarPincelTick(BotonEvento_t input) {
	if (dibujoActual == NULL) return;
	if (pincelCambiado) {
		pincelCambiado = false;
		menuDibujoMostrar(seleccion, indiceSeleccion);
		sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
		return;
	}
	switch (input) {
	case BOTON_ARRIBA:
		dibujoActual->tamPincel = dibujoActual->tamPincel * 2;
		break;
	case BOTON_ABAJO:
		dibujoActual->tamPincel = dibujoActual->tamPincel / 2;
		break;
	case BOTON_ACEPTAR:
	case BOTON_ATRAS:
		pincelCambiado = true; // Terminó
		break;
	default:
		break;
	}

	if (dibujoActual->tamPincel > 8){
		dibujoActual->tamPincel = 1;
	} else if (dibujoActual->tamPincel < 1) {
		dibujoActual->tamPincel = 8;
	}

	lcdVaciarBuffer();
	dibujoActual->indiceFil = (dibujoActual->indiceFil / dibujoActual->tamPincel) * dibujoActual->tamPincel;
	dibujoActual->indiceCol = (dibujoActual->indiceCol / dibujoActual->tamPincel) * dibujoActual->tamPincel;

	char mensaje0[LCD_COLUMNAS];
	char mensaje1[LCD_COLUMNAS];
	snprintf(mensaje0, sizeof(mensaje0), "Medida del Pincel:");
	snprintf(mensaje1, sizeof(mensaje1), "%d x %d", dibujoActual->tamPincel, dibujoActual->tamPincel);

	lcdBufferearLinea(0, mensaje0);
	lcdBufferearLinea(1, mensaje1);
}

Matriz_t* menuDibujoObtenerMatriz(void) {
    if (dibujoActual != NULL) {
        return dibujoActual->matriz;
    }
    return NULL;
}

void menuDibujoLimpiandoTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ACEPTAR:
            dibujoReiniciar(dibujoActual);
            frameBufferUpdateAll(dibujoActual->matriz); //Check

            // Vuelvo al menu de dibujo y reimprimo en el lcd
            sistemaCambiarEstado(ESTADO_MENU_DIBUJO);

            menuDibujoMostrar(seleccion, indiceSeleccion);
            break;

        case BOTON_ATRAS:
            // Vuelvo al menu de dibujo pero sin borrar nada
            sistemaCambiarEstado(ESTADO_MENU_DIBUJO);

            menuDibujoMostrar(seleccion, indiceSeleccion);
            break;

        default:
            break;
    }
}
