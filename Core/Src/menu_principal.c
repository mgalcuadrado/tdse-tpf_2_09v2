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

static char seleccion[4] = {'*', ' ',' '};
static int indice_seleccion = 0;
static int brillo = 25;

void menuPrincipalEntrar(void) {
    indice_seleccion = 0; //A medida que aumenta, va a la opcion mas abajo en el display.
    seleccion[0] = '*';
    seleccion[1] = ' ';
    //hub75SetBrightness(brillo);
    lcdBorrar();
    menuPrincipalPrint(seleccion, indice_seleccion);
   //frameBufferColourAll();
}

void menuPrincipalTick(BotonEvento_t input) {
    switch (input) {
    	case BOTON_ABAJO:
			seleccion[indice_seleccion] = ' ';
			indice_seleccion = (indice_seleccion >= 2) ? 0 : indice_seleccion + 1;
			seleccion[indice_seleccion] = '*';
			lcdBorrar();
			menuPrincipalPrint(seleccion, indice_seleccion);
			break;
		case BOTON_ARRIBA:
			seleccion[indice_seleccion] = ' ';
			indice_seleccion = (indice_seleccion <= 0) ? 2 : indice_seleccion - 1;
			seleccion[indice_seleccion] = '*';
			lcdBorrar();
			menuPrincipalPrint(seleccion, indice_seleccion);
            break;
        case BOTON_ACEPTAR:
            menuPrincipalOpcionElegida(indice_seleccion);
            break;
        default:
            break;
    }
}

void menuPrincipalOpcionElegida(int indice_seleccion) {
	switch (indice_seleccion){
	case 0: //MENU_DIBUJO
		sistemaCambiarEstado(ESTADO_MENU_DIBUJO);
		break;
	case 1: //MENU_SECUENCIA
        sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
        break;
	case 2: //CAMBIAR_BRILLO
		sistemaCambiarEstado(ESTADO_CAMBIANDO_BRILLO);
		break;
	default:
		break;
	}
}

void menuPrincipalCambiandoBrilloTick(BotonEvento_t input) {
	lcdBorrar();
	lcdSetearCursor(0, 0);
	lcdPrint("Cambiando Brillo");

	char mensaje1[MAX_CARACTERES_MENSAJE];
	snprintf(mensaje1, sizeof(mensaje1), "BrilloAct. = %d", brillo);
	lcdSetearCursor(0, 1);
	lcdPrint(mensaje1);
	//hub75SetBrightness(brillo);
	switch (input) {
		case BOTON_ABAJO:
			if (brillo > MIN_BRILLO) {
				brillo = brillo /2;
			} else {
				brillo = MAX_BRILLO;
			}
			break;
        case BOTON_ARRIBA:
        	if (brillo < MAX_BRILLO) {
				brillo = brillo *2;
			} else {
				brillo = MIN_BRILLO;
			}
            break;
        case BOTON_ACEPTAR:
        case BOTON_ATRAS:
        	sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            break;
        default:
            break;
	}
}

void menuPrincipalPrint(char seleccion[3], int indice_seleccion) {
    char mensaje1[MAX_CARACTERES_MENSAJE];
    char mensaje2[MAX_CARACTERES_MENSAJE];
    char mensaje3[MAX_CARACTERES_MENSAJE];
    char mensaje4[MAX_CARACTERES_MENSAJE];
    snprintf(mensaje1, sizeof(mensaje1), "  UBA en Accion ");
    snprintf(mensaje2, sizeof(mensaje2), "(%c) Modo Dibujo", seleccion[0]);
    snprintf(mensaje3, sizeof(mensaje3), "(%c) Modo Secuencia", seleccion[1]);
    snprintf(mensaje4, sizeof(mensaje4), "(%c) Cambiar Brillo", seleccion[2]);

    lcdSetearCursor(0, 0);
    lcdPrint(mensaje1);

    lcdSetearCursor(0, 1);
    lcdPrint(mensaje2);

    lcdSetearCursor(0, 2);
    lcdPrint(mensaje3);

    lcdSetearCursor(0, 3);
    lcdPrint(mensaje4);
}
