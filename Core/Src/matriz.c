/*
 * matriz.c
 *
 *  Created on: Jul 17, 2026
 *      Author: Martin
 */


#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

// Creo una matriz de filas x columnas, con los parametros predefinidos como #define
Matriz_t* matrizCrear(void) {
    Matriz_t* nuevaMatriz = (Matriz_t*)malloc(sizeof(Matriz_t));
    if (nuevaMatriz == NULL) {
        printf("Error creando la matriz \r\n");
    }
    return nuevaMatriz;
}


void matrizBorrar(Matriz_t* matrizEntrada) {
    if (matrizEntrada != NULL) {
        free(matrizEntrada);
    }
}

// Modifico un casillero, chequeo si no estoy afuera del limite de la matriz
void matrizSetCasillero(Matriz_t* matrizEntrada, uint8_t fila, uint8_t col, uint8_t r, uint8_t g, uint8_t b) {
    if (matrizEntrada != NULL && fila < MATRIZ_FILAS && col < MATRIZ_COLUMNAS) {
        matrizEntrada->grilla[fila][col].r = r;
        matrizEntrada->grilla[fila][col].g = g;
        matrizEntrada->grilla[fila][col].b = b;
    }else{
    	printf("Fuera de las dimensiones de la matriz \r\n");
    }
}

// Pido un casillero
void matrizGetCasillero(Matriz_t* matrizEntrada, uint8_t fila, uint8_t col, Casillero_t* salida) {
    if (matrizEntrada != NULL && salida != NULL && fila < MATRIZ_FILAS && col < MATRIZ_COLUMNAS) {
        *salida = matrizEntrada->grilla[fila][col];
    }
}

void matrizGetColorCasillero(Matriz_t* matrizEntrada, uint8_t fila, uint8_t col, uint8_t* entradaR, uint8_t* entradaG, uint8_t* entradaB){
    *entradaR = matrizEntrada->grilla[fila][col].r;
    *entradaG = matrizEntrada->grilla[fila][col].g;
    *entradaB = matrizEntrada->grilla[fila][col].b;
}

//Lleno la matriz de un color
void matrizLlenar(Matriz_t* matrizEntrada, uint8_t r, uint8_t g, uint8_t b){

	for(uint8_t y=0;y<MATRIZ_FILAS;y++){
		for(uint8_t x=0;x<MATRIZ_COLUMNAS;x++){
			matrizSetCasillero(matrizEntrada, x,y,r,g,b);
		}
	}
}
