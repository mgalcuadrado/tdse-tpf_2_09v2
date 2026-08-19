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
static int indiceSeleccion = 0;
static int brillo = 25;

void menuPrincipalEntrar(void) {
    indiceSeleccion = 0; //A medida que aumenta, va a la opcion mas abajo en el display.
    seleccion[0] = '*';
    seleccion[1] = ' ';
    //hub75SetBrightness(brillo);
    menuPrincipalPrint(seleccion, indiceSeleccion);
}

void menuPrincipalTick(BotonEvento_t input) {
    switch (input) {
    	case BOTON_ABAJO:
			seleccion[indiceSeleccion] = ' ';
			indiceSeleccion = (indiceSeleccion >= 2) ? 0 : indiceSeleccion + 1;
			seleccion[indiceSeleccion] = '*';

			menuPrincipalPrint(seleccion, indiceSeleccion);
			break;
		case BOTON_ARRIBA:
			seleccion[indiceSeleccion] = ' ';
			indiceSeleccion = (indiceSeleccion <= 0) ? 2 : indiceSeleccion - 1;
			seleccion[indiceSeleccion] = '*';

			menuPrincipalPrint(seleccion, indiceSeleccion);
            break;
        case BOTON_ACEPTAR:
        	seleccion[indiceSeleccion] = ' ';
            menuPrincipalOpcionElegida(indiceSeleccion);
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
	lcdVaciarBuffer();
	lcdBufferearLinea(0, "Cambiando Brillo");

	char mensaje1[LCD_COLUMNAS];
	snprintf(mensaje1, sizeof(mensaje1), "BrilloAct. = %d", brillo);
	lcdBufferearLinea(1, mensaje1);
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

    char mensaje0[LCD_COLUMNAS];
    char mensaje1[LCD_COLUMNAS];
    char mensaje2[LCD_COLUMNAS];
    char mensaje3[LCD_COLUMNAS];
    snprintf(mensaje0, sizeof(mensaje0), "  UBA en Accion ");
    snprintf(mensaje1, sizeof(mensaje1), "(%c) Modo Dibujo", seleccion[0]);
    snprintf(mensaje2, sizeof(mensaje2), "(%c) Modo Secuencia", seleccion[1]);
    snprintf(mensaje3, sizeof(mensaje3), "(%c) Cambiar Brillo", seleccion[2]);

    lcdBufferearLinea(0, mensaje0);
    lcdBufferearLinea(1, mensaje1);
    lcdBufferearLinea(2, mensaje2);
    lcdBufferearLinea(3, mensaje3);
}
