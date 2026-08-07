/*
 * menu.c
 *
 * Created on: Ago 3, 2026
 *      Author: Bauti
*/
#ifndef TABLERO_H
#define TABLERO_H


#include <stdio.h>
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct  {
        Matriz_t* matriz;
        uint8_t indice_fil;
        uint8_t indice_col;
        uint8_t tam_pincel;
} Tablero_t;


Tablero_t* crearTablero();
void tableroBorrar(Tablero_t* tablero);
void tableroAvanzar(Tablero_t* tablero, uint8_t direcc);
void tableroReiniciar(Tablero_t* tablero);
void tableroPintar(Tablero_t* tablero, uint8_t fil, uint8_t col, uint8_t red, uint8_t green, uint8_t blue);
void tableroCambiarPincel(Tablero_t* tablero, int decision);
void tableroElementoActual(Tablero_t* tablero, Casillero_t* salida);
#endif
