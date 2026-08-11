/*
 * dibujo.c
 *
 * Created on: Ago 3, 2026
 *      Author: Bauti
 *
*/

#include <stdio.h>
#include "dibujo.h"
#include "matriz.h"
#include "boton.h"
#include <stdlib.h>
#include <string.h>
#include "lcd.h"

Dibujo_t* dibujoCrear(void) {
	Dibujo_t* dibujo = (Dibujo_t*)malloc(sizeof(Dibujo_t));
	if (dibujo == NULL) {
		//printf("Error al crear tablero");
		return NULL;
	}
	dibujo->matriz = matrizCrear();
	if (dibujo->matriz == NULL) {
		//printf("Error al crear tablero");
		free(dibujo);
		return NULL;
	}
	dibujo->indice_fil = 0;
	dibujo->indice_col = 0;
	dibujo->tam_pincel = 1;
	return dibujo;
}

void dibujoBorrar(Dibujo_t* dibujo) {
	if (dibujo == NULL) {
		return;
	}
	if (dibujo->matriz != NULL){
		matrizBorrar(dibujo->matriz);
	}
	free(dibujo);
}

void dibujoAvanzar(Dibujo_t* dibujo, BotonEvento_t input){
	dibujoPintar(dibujo, dibujo->color_anterior->r,dibujo->color_anterior->g,dibujo->color_anterior->b);
	switch (input) {
	case BOTON_IZQUIERDA:
		if (dibujo->indice_col / dibujo->tam_pincel > 0){
			dibujo->indice_col -= dibujo->tam_pincel;
		} else {
			dibujo->indice_col = MATRIZ_COLUMNAS - dibujo->tam_pincel;
		}
		matrizGetCasillero(dibujo->matriz, dibujo->indice_fil, dibujo->indice_col, dibujo->color_anterior);
		dibujoPintar(dibujo, 0, 0, 0);
		break;
	case BOTON_ABAJO:
		if (dibujo->indice_fil / dibujo->tam_pincel > 0){
			dibujo->indice_fil += dibujo->tam_pincel;
		} else {
			dibujo->indice_fil = 0;
		}
		matrizGetCasillero(dibujo->matriz, dibujo->indice_fil, dibujo->indice_col, dibujo->color_anterior);
		dibujoPintar(dibujo, 0, 0, 0);
		break;
	case BOTON_DERECHA:
		if ((dibujo->indice_col/dibujo->tam_pincel) < ((MATRIZ_COLUMNAS - 1)/dibujo->tam_pincel)){
			dibujo->indice_col += dibujo->tam_pincel;
		} else {
			dibujo->indice_col = 0;
		}
		matrizGetCasillero(dibujo->matriz, dibujo->indice_fil, dibujo->indice_col, dibujo->color_anterior);
		dibujoPintar(dibujo, 0, 0, 0);
		break;
	case BOTON_ARRIBA:
		if ((dibujo->indice_fil/dibujo->tam_pincel) < ((MATRIZ_FILAS - 1)/dibujo->tam_pincel)){
			dibujo->indice_fil -= dibujo->tam_pincel;
		} else {
			dibujo->indice_fil = MATRIZ_FILAS - dibujo->tam_pincel;
		}
		matrizGetCasillero(dibujo->matriz, dibujo->indice_fil, dibujo->indice_col, dibujo->color_anterior);
		dibujoPintar(dibujo, 0, 0, 0);
		break;
	default:
		return;
	}
}

void dibujoReiniciar(Dibujo_t* dibujo) {
	matrizLlenar(dibujo->matriz, 0, 0, 0); // Apago todas las LED's de la matriz
	dibujo->indice_col = 0;
	dibujo->indice_fil = 0;
}

// Se puede revisar la dinamica, reduciendo las restricciones.

void dibujoPintar(Dibujo_t* dibujo, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t base_fil = (dibujo->indice_fil/dibujo->tam_pincel) * dibujo->tam_pincel;
	uint8_t base_col = (dibujo->indice_col/dibujo->tam_pincel) * dibujo->tam_pincel;
	for (uint8_t i = 0; i < dibujo->tam_pincel; i++) {
	        for(uint8_t j = 0; j < dibujo->tam_pincel; j++) {
	            matrizSetCasillero(dibujo->matriz, base_fil + i, base_col + j, red, green, blue);
	        }
	}
}

// Antes: dibujoCambiarPincel(dibujo) con un while(1) interno que no soltaba
// la CPU hasta ACEPTAR/ATRAS. Ahora: procesa un solo evento por llamada.
bool dibujoCambiarPincelTick(Dibujo_t* dibujo, BotonEvento_t input) {
	switch (input) {
	case BOTON_ARRIBA:
		dibujo->tam_pincel = dibujo->tam_pincel * 2;
		break;
	case BOTON_ABAJO:
		dibujo->tam_pincel = dibujo->tam_pincel / 2;
		break;
	case BOTON_ACEPTAR:
	case BOTON_ATRAS:
		return true; // Terminó: que el llamador vuelva al menú
	default:
		break;
	}

	if (dibujo->tam_pincel > 8){
		dibujo->tam_pincel = 1;
	} else if (dibujo->tam_pincel < 1) {
		dibujo->tam_pincel = 8;
	}

	dibujo->indice_fil = (dibujo->indice_fil / dibujo->tam_pincel) * dibujo->tam_pincel;
	dibujo->indice_col = (dibujo->indice_col / dibujo->tam_pincel) * dibujo->tam_pincel;

	char mensaje1[MAX_CARACTERES_MENSAJE];
	snprintf(mensaje1, sizeof(mensaje1), "Tamaño de Pincel: (%d x %d)", dibujo->tam_pincel, dibujo->tam_pincel);
	lcdSetearCursor(0, 0);
	lcdPrint(mensaje1);

	return false; // Todavía eligiendo pincel
}
