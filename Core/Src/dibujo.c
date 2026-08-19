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
#include "potenciometro.h"
#include <stdlib.h>
#include <string.h>
#include "lcd.h"
#include "frame_buffer.h"

Dibujo_t* dibujoCrear(void) {
	Dibujo_t* dibujo = (Dibujo_t*)malloc(sizeof(Dibujo_t));
	if (dibujo == NULL) {
		printf("Error al crear tablero");
		return NULL;
	}
	dibujo->matriz = matrizCrear();
	if (dibujo->matriz == NULL) {
		printf("Error al crear tablero");
		free(dibujo);
		return NULL;
	}

	dibujo->colorAnterior = (Casillero_t*)malloc(sizeof(Casillero_t));
		if (dibujo->colorAnterior == NULL) {

			matrizBorrar(dibujo->matriz);
			free(dibujo);
			return NULL;
		}

	dibujo->indiceFil = 16;
	dibujo->indiceCol = 16;
	dibujo->tamPincel = 1;

	matrizGetCasillero(dibujo->matriz, 0, 0, dibujo->colorAnterior);
	matrizLlenar(dibujo->matriz, 0, 0, 0);
	return dibujo;
}

void dibujoBorrar(Dibujo_t* dibujo) {
	if (dibujo == NULL) {
		return;
	}
	if (dibujo->matriz != NULL){
		matrizBorrar(dibujo->matriz);
	}

	if (dibujo->colorAnterior != NULL){
			free(dibujo->colorAnterior);
	}

	free(dibujo);
}

void dibujoAvanzar(Dibujo_t* dibujo, BotonEvento_t input){
	dibujoPintar(dibujo, dibujo->colorAnterior->r, dibujo->colorAnterior->g, dibujo->colorAnterior->b);
		switch (input) {
		case BOTON_IZQUIERDA:
			if (dibujo->indiceCol / dibujo->tamPincel > 0){
				dibujo->indiceCol -= dibujo->tamPincel;
			} else {
				dibujo->indiceCol = MATRIZ_COLUMNAS - dibujo->tamPincel;
			}
			break;
		case BOTON_ABAJO:
			if ((dibujo->indiceFil / dibujo->tamPincel) < ((MATRIZ_FILAS - 1) / dibujo->tamPincel)){
				dibujo->indiceFil += dibujo->tamPincel;
			} else {
				dibujo->indiceFil = 0;
			}
			break;
		case BOTON_DERECHA:
			if ((dibujo->indiceCol / dibujo->tamPincel) < ((MATRIZ_COLUMNAS - 1) / dibujo->tamPincel)){
				dibujo->indiceCol += dibujo->tamPincel;
			} else {
				dibujo->indiceCol = 0;
			}
			break;
		case BOTON_ARRIBA:
			if (dibujo->indiceFil / dibujo->tamPincel > 0){
				dibujo->indiceFil -= dibujo->tamPincel;
			} else {
				dibujo->indiceFil = MATRIZ_FILAS - dibujo->tamPincel;
			}
			break;


		default:
			//printf("Error al moverse en la matriz \n");
			return;
		}

	matrizGetCasillero(dibujo->matriz, dibujo->indiceFil, dibujo->indiceCol, dibujo->colorAnterior);

	//Pinta el cursor
	if(dibujo->matriz != NULL){
		dibujoPintar(dibujo, 250, 0, 0);

	}

	// StandBy
	/*
	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;

	leer_potenciometros(&r, &g, &b);
	matrizGetCasillero(dibujo->matriz, dibujo->indiceFil, dibujo->indiceCol, dibujo->colorAnterior);
	dibujoPintar(dibujo, r, g, b);
	*/
}

void dibujoReiniciar(Dibujo_t* dibujo) {
	if (dibujo == NULL || dibujo->matriz == NULL) return;
		matrizLlenar(dibujo->matriz, 0, 0, 0); // Apago todas las leds de la matriz
        frameBufferUpdateAll(dibujo->matriz);
		dibujo->indiceCol = 0;
		dibujo->indiceFil = 0;
		if (dibujo->colorAnterior != NULL) {
			dibujo->colorAnterior->r = 0;
			dibujo->colorAnterior->g = 0;
			dibujo->colorAnterior->b = 0;
		}
	}

void dibujoPintar(Dibujo_t* dibujo, uint8_t red, uint8_t green, uint8_t blue) {
	if (dibujo == NULL || dibujo->matriz == NULL) return;
		uint8_t base_fil = (dibujo->indiceFil/dibujo->tamPincel) * dibujo->tamPincel;
		uint8_t base_col = (dibujo->indiceCol/dibujo->tamPincel) * dibujo->tamPincel;
		for (uint8_t i = 0; i < dibujo->tamPincel; i++) {
		    for(uint8_t j = 0; j < dibujo->tamPincel; j++) {
		        matrizSetCasillero(dibujo->matriz, base_fil + i, base_col + j, red, green, blue);
		    }
		}
        frameBufferUpdateAll(dibujo->matriz);

	}



