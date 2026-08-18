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

static Dibujo_t* dibujo_actual = NULL;
static char seleccion[6] = {'*', ' ', ' ', ' ', ' '}; // 5 opciones + \n
static int indice_seleccion = 0;
static bool pincel_cambiado = false;

static bool memoria_en_proceso = false;
static uint32_t tiempo_memoria = 0;

#define TIEMPO_MOSTRAR_SECCION_MS 1000 //300ms para guardar

void menuDibujoEntrar(void) {
    // El dibujo se crea una sola vez (la primera vez que se entra al menú)
    // y se mantiene vivo mientras se navega entre Dibujar/Cambiar Pincel/etc.
    if (dibujo_actual == NULL) {
        dibujo_actual = dibujoCrear();
        if (dibujo_actual == NULL) {
        	sistemaCambiarOperacion(ESTADO_FALLA);
            return;
        }
        frameBufferUpdateAll(dibujo_actual->matriz);
    }

    indice_seleccion = 0;
    seleccion[0] = '*';
    menuDibujoMostrar(seleccion, indice_seleccion);
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

        	/* Timer via ticks
			uint32_t ahora = HAL_GetTick();
			if (!memoria_en_proceso){
				tiempo_memoria = HAL_GetTick();
				memoria_en_proceso = true;
				lcdVaciarBuffer();
				lcdBufferearLinea(1, "Cargando...");
			}
			if ((ahora - tiempo_memoria) < TIEMPO_MOSTRAR_SECCION_MS) {
				return; // Todavia no pasaron los ~1 segundos de esta sección
			}
			memoria_en_proceso = false;*/


        case 2: // Guardar Dibujo
            lcdVaciarBuffer();
            if (memEstaOcupada()) {
            	tiempo_memoria = HAL_GetTick();
				memoria_en_proceso = true;
                lcdBufferearLinea(1, "Memoria Ocupada!");
                menuDibujoEntrar();
            } else {
                lcdBufferearLinea(1, "Guardando. . .");
                if (!memBufferearEscrituraMatriz(0x0000, dibujo_actual->matriz)) {
                    lcdBufferearLinea(2, "Error al Guardar");
                    sistemaCambiarOperacion(ESTADO_FALLA);
                }
                menuDibujoEntrar();
            }
            break;

        case 3: // Cargar Dibujo
            lcdVaciarBuffer();
            if (memEstaOcupada()) {
                lcdBufferearLinea(1, "Memoria Ocupada!");
                menuDibujoEntrar();
            } else {
                lcdBufferearLinea(1, "Cargando...");
                if (memLeerMatriz(0x0000, dibujo_actual->matriz) == HAL_OK) {
                    frameBufferUpdateAll(dibujo_actual->matriz);
                    lcdBufferearLinea(2, "Carga Exitosa!");
                } else {
                    lcdBufferearLinea(2, "Error al Cargar");
                    sistemaCambiarOperacion(ESTADO_FALLA);
                }
                menuDibujoEntrar();
            }
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
            seleccion[indice_seleccion] = ' ';
            indice_seleccion = (indice_seleccion >= 4) ? 0 : indice_seleccion + 1;
            seleccion[indice_seleccion] = '*';

            menuDibujoMostrar(seleccion, indice_seleccion);
            break;
        case BOTON_ARRIBA:
            seleccion[indice_seleccion] = ' ';
            indice_seleccion = (indice_seleccion <= 0) ? 4 : indice_seleccion - 1;
            seleccion[indice_seleccion] = '*';

            menuDibujoMostrar(seleccion, indice_seleccion);
            break;
        case BOTON_ACEPTAR:
        	seleccion[indice_seleccion] = ' ';
            menuDibujoOpcionElegida(indice_seleccion);
            break;
        case BOTON_ATRAS:
        	dibujoReiniciar(dibujo_actual);
        	seleccion[indice_seleccion] = ' ';
            dibujoBorrar(dibujo_actual);
            dibujo_actual = NULL;
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
        	dibujoPintar(dibujo_actual,dibujo_actual->color_anterior->r, dibujo_actual->color_anterior->g,dibujo_actual->color_anterior->b);
            dibujoAvanzar(dibujo_actual, input);

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
        	dibujo_actual->color_anterior->r = valores.r;
			dibujo_actual->color_anterior->g = valores.g;
			dibujo_actual->color_anterior->b = valores.b;
			char mensaje1[LCD_COLUMNAS];
			snprintf(mensaje1, sizeof(mensaje1), "r %d g %d b %d", valores.r, valores.g, valores.b);
			lcdVaciarBuffer();
			lcdBufferearLinea(0, "Patron RGB:");
			lcdBufferearLinea(1, mensaje1);
			// Se redibuja el cursor porque a veces se tapa
			uint8_t base_fil = (dibujo_actual->indice_fil/dibujo_actual->tam_pincel) * dibujo_actual->tam_pincel;
			uint8_t base_col = (dibujo_actual->indice_col/dibujo_actual->tam_pincel) * dibujo_actual->tam_pincel;
			for (uint8_t i = 0; i < dibujo_actual->tam_pincel; i++) {
				for(uint8_t j = 0; j < dibujo_actual->tam_pincel; j++) {
					matrizSetCasillero(dibujo_actual->matriz, base_fil + i, base_col + j, 250, 0, 0);
				}
			}

			frameBufferUpdateAll(dibujo_actual->matriz); // Check
            break;
        case BOTON_ATRAS:
            sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
            menuDibujoMostrar(seleccion, indice_seleccion); // reimprime el menú al volver
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

void menuDibujoCambiarPincelTick(BotonEvento_t input) {
	if (dibujo_actual == NULL) return;
	if (pincel_cambiado) {
		pincel_cambiado = false;
		menuDibujoMostrar(seleccion, indice_seleccion);
		sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
		return;
	}
	switch (input) {
	case BOTON_ARRIBA:
		dibujo_actual->tam_pincel = dibujo_actual->tam_pincel * 2;
		break;
	case BOTON_ABAJO:
		dibujo_actual->tam_pincel = dibujo_actual->tam_pincel / 2;
		break;
	case BOTON_ACEPTAR:
	case BOTON_ATRAS:
		pincel_cambiado = true; // Terminó
		break;
	default:
		break;
	}

	if (dibujo_actual->tam_pincel > 8){
		dibujo_actual->tam_pincel = 1;
	} else if (dibujo_actual->tam_pincel < 1) {
		dibujo_actual->tam_pincel = 8;
	}

	lcdVaciarBuffer();
	dibujo_actual->indice_fil = (dibujo_actual->indice_fil / dibujo_actual->tam_pincel) * dibujo_actual->tam_pincel;
	dibujo_actual->indice_col = (dibujo_actual->indice_col / dibujo_actual->tam_pincel) * dibujo_actual->tam_pincel;

	char mensaje0[LCD_COLUMNAS];
	char mensaje1[LCD_COLUMNAS];
	snprintf(mensaje0, sizeof(mensaje0), "Medida del Pincel:");
	snprintf(mensaje1, sizeof(mensaje1), "%d x %d", dibujo_actual->tam_pincel, dibujo_actual->tam_pincel);

	lcdBufferearLinea(0, mensaje0);
	lcdBufferearLinea(1, mensaje1);
}

Matriz_t* menuDibujoObtenerMatriz(void) {
    if (dibujo_actual != NULL) {
        return dibujo_actual->matriz;
    }
    return NULL;
}

void menuDibujoLimpiandoTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ACEPTAR:
            dibujoReiniciar(dibujo_actual);
            frameBufferUpdateAll(dibujo_actual->matriz); //Check

            // Vuelvo al menu de dibujo y reimprimo en el lcd
            sistemaCambiarEstado(ESTADO_MENU_DIBUJO);

            menuDibujoMostrar(seleccion, indice_seleccion);
            break;

        case BOTON_ATRAS:
            // Vuelvo al menu de dibujo pero sin borrar nada
            sistemaCambiarEstado(ESTADO_MENU_DIBUJO);

            menuDibujoMostrar(seleccion, indice_seleccion);
            break;

        default:
            break;
    }
}
