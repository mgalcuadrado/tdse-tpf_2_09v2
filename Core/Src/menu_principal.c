/*
 * menu_principal.c
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
*/

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include "secuencia.h"
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "boton.h"
#include "menu_principal.h"
#include "estado.h"

static char seleccion[3] = {'*', ' '};
static int indice_seleccion = 0;

void menuPrincipalEntrar(void) {
    indice_seleccion = 0; //A medida que aumenta, va a la opcion mas abajo en el display.
    seleccion[0] = '*';
    seleccion[1] = ' ';
    lcdBorrar();
    menuPrincipalPrint(seleccion, indice_seleccion);
}

void menuPrincipalTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ABAJO:
        case BOTON_ARRIBA:
            seleccion[indice_seleccion] = ' ';
            indice_seleccion = (indice_seleccion == 1) ? 0 : 1; //Como son dos opciones en este menu, es
            //lo mismo si sube o baja. Cambia a la otra opcion
            seleccion[indice_seleccion] = '*';
            lcdBorrar();
            menuPrincipalPrint(seleccion, indice_seleccion);
            break;
        case BOTON_ACEPTAR:
            if (indice_seleccion == 0) {
                sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
            } else {
                sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
            }
            break;
        default:
            break;
    }
}

void menuPrincipalPrint(char seleccion[3], int indice_seleccion) {
    char mensaje1[MAX_CARACTERES_MENSAJE];
    char mensaje2[MAX_CARACTERES_MENSAJE];
    char mensaje3[MAX_CARACTERES_MENSAJE];
    snprintf(mensaje1, sizeof(mensaje1), "  UBA en Accion ");
    snprintf(mensaje2, sizeof(mensaje2), "(%c) Modo Dibujo", seleccion[0]);
    snprintf(mensaje3, sizeof(mensaje3), "(%c) Modo Secuencia", seleccion[1]);

    lcdSetearCursor(0, 0);
    lcdPrint(mensaje1);

    lcdSetearCursor(0, 1);
    lcdPrint(mensaje2);

    lcdSetearCursor(0, 2);
    lcdPrint(mensaje3);
}
