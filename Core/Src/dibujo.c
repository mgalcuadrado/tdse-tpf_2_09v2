/*
 * dibujo.c
 *
 * Created on: Ago 3, 2026
 *      Author: Bauti
*/

#include <stdio.h>
#include "dibujo.h"
#include "matriz.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

Tablero_t* crearTablero(void) {
	Tablero_t* tablero = (Tablero_t* )malloc(sizeof(Tablero_t));
	if (tablero == NULL) {
		printf("Error al crear tablero");
		return NULL;
	}
	tablero->matriz = matrizCrear();
	if (tablero->matriz == NULL) {
		printf("Error al crear tablero");
		free(tablero);
		return NULL;
	}
	tablero->indice_fil = 0;
	tablero->indice_col = 0;
	tablero->tam_pincel = 1;
	return tablero;
}

void tableroBorrar(Tablero_t* tablero) {
	if (tablero == NULL) {
		return;
	}
	if (tablero->matriz != NULL){
		matrizBorrar(tablero->matriz);
	}
	if (tablero != NULL) {
		free(tablero);
	}
}

void tableroAvanzar(Tablero_t* tablero, uint8_t direcc){
	switch (direcc) {
	case 0: // "a"
		if (tablero->indice_fil / tablero->tam_pincel > 0){
			tablero->indice_fil -= tablero->tam_pincel;
		} else {
			tablero->indice_fil = MATRIZ_FILAS - 1;
		}
	case 1: //"s"
		if (tablero->indice_col / tablero->tam_pincel > 0){
			tablero->indice_col -= tablero->tam_pincel;
		} else {
			tablero->indice_col = MATRIZ_COLUMNAS - 1;
		}
	case 2: //"d"
		if ((tablero->indice_fil/tablero->tam_pincel) < ((MATRIZ_FILAS - 1)/tablero->tam_pincel)){
			tablero->indice_fil += tablero->tam_pincel;
		} else {
			tablero->indice_fil = 0;
		}
	case 3: //"w"
		if ((tablero->indice_col/tablero->tam_pincel) < ((MATRIZ_COLUMNAS - 1)/tablero->tam_pincel)){
			tablero->indice_col += tablero->tam_pincel;
		} else {
			tablero->indice_col = 0;
		}
	}
}
void tableroReiniciar(Tablero_t* tablero) {
	matrizLlenar(tablero->matriz, 0, 0, 0);
	tablero->indice_col = 0;
	tablero->indice_fil = 0;
}

void tableroPintar(Tablero_t* tablero, uint8_t fil, uint8_t col, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t base_fil = (fil/tablero->tam_pincel) * tablero->tam_pincel;
	uint8_t base_col = (col/tablero->tam_pincel) * tablero->tam_pincel;
	for (uint8_t i = 0; i < tablero->tam_pincel; i++) {
	        for(uint8_t j = 0; j < tablero->tam_pincel; j++) {
	            matrizSetCasillero(tablero->matriz, base_fil + i, base_col + j, red, green, blue);
	        }
	}
}

void tableroCambiarPincel(Tablero_t* tablero, int decision) {
	while (1) {
		if (tablero->tam_pincel > 8){
			tablero->tam_pincel = 1;
		} else if (tablero->tam_pincel < 1) {
			tablero->tam_pincel = 8;
		}

		switch (decision){
		case 0://"w"
			tablero->tam_pincel = tablero->tam_pincel;
			continue;
		case 1:  //"s"
			tablero->tam_pincel--;
			continue;
		case 2: //"aceptar"
			return;
		case 3: //"atras"
			return;
		}
	}
}
void tableroElementoActual(Tablero_t* tablero, Casillero_t* salida) {
	matrizGetCasillero(tablero->matriz, tablero->indice_fil, tablero->indice_col, salida);
}
