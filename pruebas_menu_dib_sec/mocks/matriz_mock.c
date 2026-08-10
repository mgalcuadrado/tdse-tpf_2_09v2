/*
 * mocks/matriz_mock.c
 *
 * Implementación falsa pero funcional (guarda los colores en memoria
 * de verdad) para poder verificar en los tests qué celdas se pintaron.
*/

#include "matriz.h"
#include <stdlib.h>
#include <string.h>

int matrizCrear_llamadas = 0;
int matrizLlenar_llamadas = 0;
int matrizSetCasillero_llamadas = 0;

Matriz_t* matrizCrear(void) {
    matrizCrear_llamadas++;
    Matriz_t* m = (Matriz_t*)malloc(sizeof(Matriz_t));
    if (m != NULL) {
        memset(m, 0, sizeof(Matriz_t));
    }
    return m;
}

void matrizBorrar(Matriz_t* matriz) {
    if (matriz != NULL) {
        free(matriz);
    }
}

void matrizLlenar(Matriz_t* matriz, uint8_t red, uint8_t green, uint8_t blue) {
    matrizLlenar_llamadas++;
    if (matriz == NULL) return;
    for (int f = 0; f < MATRIZ_FILAS; f++) {
        for (int c = 0; c < MATRIZ_COLUMNAS; c++) {
            matriz->red[f][c] = red;
            matriz->green[f][c] = green;
            matriz->blue[f][c] = blue;
        }
    }
}

void matrizSetCasillero(Matriz_t* matriz, uint8_t fil, uint8_t col, uint8_t red, uint8_t green, uint8_t blue) {
    matrizSetCasillero_llamadas++;
    if (matriz == NULL || fil >= MATRIZ_FILAS || col >= MATRIZ_COLUMNAS) return;
    matriz->red[fil][col] = red;
    matriz->green[fil][col] = green;
    matriz->blue[fil][col] = blue;
}
