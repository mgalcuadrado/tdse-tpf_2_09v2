/*
 * mocks/matriz.h
 *
 * MOCK para tests de escritorio. No es tu matriz.h real (que no fue
 * compartido en esta conversación) -- es un reemplazo mínimo con la
 * misma interfaz, para poder compilar y correr dibujo.c/secuencia.c
 * fuera de la placa.
 *
 * IMPORTANTE: si tu matriz.h real define MATRIZ_FILAS/MATRIZ_COLUMNAS
 * con otros valores, o Matriz_t con otros campos, actualizá acá para
 * que coincida (los tests no dependen de la estructura interna, solo
 * de fil/col/tam_pincel, así que debería ser un cambio directo).
*/

#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdint.h>

#define MATRIZ_FILAS 32
#define MATRIZ_COLUMNAS 32

typedef struct {
    uint8_t red[MATRIZ_FILAS][MATRIZ_COLUMNAS];
    uint8_t green[MATRIZ_FILAS][MATRIZ_COLUMNAS];
    uint8_t blue[MATRIZ_FILAS][MATRIZ_COLUMNAS];
} Matriz_t;

Matriz_t* matrizCrear(void);
void matrizBorrar(Matriz_t* matriz);
void matrizLlenar(Matriz_t* matriz, uint8_t red, uint8_t green, uint8_t blue);
void matrizSetCasillero(Matriz_t* matriz, uint8_t fil, uint8_t col, uint8_t red, uint8_t green, uint8_t blue);

// --- Utilidades del mock, solo para inspeccionar desde los tests ---
extern int matrizCrear_llamadas;
extern int matrizLlenar_llamadas;
extern int matrizSetCasillero_llamadas;

#endif
