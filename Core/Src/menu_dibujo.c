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

static Dibujo_t* dibujo_actual = NULL;
static char seleccion[6] = {'*', ' ', ' ', ' ', ' '}; // 5 opciones + \n
static int indice_seleccion = 0;

void menuDibujoEntrar(void) {
    // El dibujo se crea una sola vez (la primera vez que se entra al menú)
    // y se mantiene vivo mientras se navega entre Dibujar/Cambiar Pincel/etc.
    if (dibujo_actual == NULL) {
        dibujo_actual = dibujoCrear();
        if (dibujo_actual == NULL) {
            //printf("Error al crear dibujo \n");
            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            return;
        }
        frameBufferUpdate(dibujo_actual->matriz);
    }

    indice_seleccion = 0;
    seleccion[0] = '*';
    lcdBorrar();
    menuDibujoMostrar(seleccion, indice_seleccion);
}

void menuDibujoMostrar(char seleccion[6], int indice_seleccion) {
    char mensaje1[MAX_CARACTERES_MENSAJE];
    char mensaje2[MAX_CARACTERES_MENSAJE];
    char mensaje3[MAX_CARACTERES_MENSAJE];

    if (indice_seleccion < 3) {
        snprintf(mensaje1, sizeof(mensaje1), "(%c) Dibujar", seleccion[0]);
        snprintf(mensaje2, sizeof(mensaje2), "(%c) Nuevo Dibujo", seleccion[1]);
        snprintf(mensaje3, sizeof(mensaje3), "(%c) Guardar Dibujo", seleccion[2]);

        lcdSetearCursor(0, 0);
        lcdPrint(mensaje1);

        lcdSetearCursor(0, 1);
        lcdPrint(mensaje2);

        lcdSetearCursor(0, 2);
        lcdPrint(mensaje3);

    } else if (2 < indice_seleccion && indice_seleccion < 5) {
        snprintf(mensaje1, sizeof(mensaje1), "(%c) Cargar Dibujo", seleccion[3]);
        snprintf(mensaje2, sizeof(mensaje2), "(%c) Cambiar Pincel", seleccion[4]);

        lcdSetearCursor(0, 0);
        lcdPrint(mensaje1);

        lcdSetearCursor(0, 1);
        lcdPrint(mensaje2);
    } else {
        printf("Error en el Display/MenuDibujo \n");
    }
}

void menuDibujoOpcionElegida(int indice_seleccion) {
    switch (indice_seleccion) {
        case 0: // Dibujar
        	lcdBorrar();
			lcdSetearCursor(0, 0);
			lcdPrint("Dibujando...");
            sistemaCambiarEstado(ESTADO_DIBUJANDO);
            break;
        case 1: // Nuevo Dibujo
            lcdBorrar();
            lcdSetearCursor(0, 0);
			lcdPrint("Estas seguro?");

			lcdSetearCursor(0, 1);
			lcdPrint("Aceptar");

			lcdSetearCursor(0, 2);
			lcdPrint("Atras");
			sistemaCambiarEstado(ESTADO_LIMPIAR_DIBUJO);
            break;
        case 2: // Guardar Dibujo
        	lcdBorrar();
			lcdSetearCursor(0, 0);
			lcdPrint("Guardando...");
            memEscribirMatriz(0x0000, dibujo_actual->matriz); // 0x000 Placeholder
            frameBufferUpdate(dibujo_actual->matriz);
            break;
        case 3: // Cargar Dibujo
        	lcdBorrar();
			lcdSetearCursor(0, 0);
			lcdPrint("Cargando...");
            memLeerMatriz(0x0000, dibujo_actual->matriz); // 0x000 Placeholder
            frameBufferUpdate(dibujo_actual->matriz);
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
            lcdBorrar();
            menuDibujoMostrar(seleccion, indice_seleccion);
            break;
        case BOTON_ARRIBA:
            seleccion[indice_seleccion] = ' ';
            indice_seleccion = (indice_seleccion <= 0) ? 4 : indice_seleccion - 1;
            seleccion[indice_seleccion] = '*';
            lcdBorrar();
            menuDibujoMostrar(seleccion, indice_seleccion);
            break;
        case BOTON_ACEPTAR:
            menuDibujoOpcionElegida(indice_seleccion);
            break;
        case BOTON_ATRAS:
            dibujoBorrar(dibujo_actual);
            dibujo_actual = NULL;
            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            break;
        default:
            break;
    }
}

void menuDibujoLimpiandoTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ACEPTAR:
        	dibujoReiniciar(dibujo_actual);
        	frameBufferUpdate(dibujo_actual->matriz);
        	sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
            break;
        case BOTON_ATRAS:
            sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
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
            dibujoAvanzar(dibujo_actual, input);
            break;
        case BOTON_ACEPTAR:
            // Lectura de potes para obtener valores R, G y B
            // dibujoPintar(dibujo_actual, r, g, b);
            // frameBufferUpdate(dibujo_actual->matriz);
            break;
        case BOTON_ATRAS:
            sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
            lcdBorrar();
            menuDibujoMostrar(seleccion, indice_seleccion); // reimprime el menú al volver
            break;
        default:
            break;
    }
}

void menuDibujoCambiarPincelTick(BotonEvento_t input) {
    if (dibujoCambiarPincelTick(dibujo_actual, input)) {
        sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
        lcdBorrar();
        menuDibujoMostrar(seleccion, indice_seleccion);
    }
}
