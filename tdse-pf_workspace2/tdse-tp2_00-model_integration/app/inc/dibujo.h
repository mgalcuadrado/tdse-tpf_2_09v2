/*
 * dibujo.h
 *
 * Created on: Ago 3, 2026
 *      Author: Bauti
 *
*/
#ifndef DIBUJO_H
#define DIBUJO_H


#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "boton.h"
#include "lcd.h"
#include "frame_buffer.h"

typedef struct  {
        Matriz_t* matriz;
        uint8_t indiceFil;
        uint8_t indiceCol;
        uint8_t tamPincel;
        Casillero_t* colorAnterior;
} Dibujo_t;



Dibujo_t* dibujoCrear();
void dibujoBorrar(Dibujo_t* dibujo);
void dibujoAvanzar(Dibujo_t* dibujo, BotonEvento_t input);
void dibujoReiniciar(Dibujo_t* dibujo);
void dibujoPintar(Dibujo_t* dibujo, uint8_t red, uint8_t green, uint8_t blue);


#endif
