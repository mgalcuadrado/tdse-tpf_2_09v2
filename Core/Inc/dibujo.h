/*
 * menu.c
 *
 * Created on: Ago 3, 2026
 *      Author: Bauti
*/
#ifndef DIBUJO_H
#define DIBUJO_H


#include <stdio.h>
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "boton.h"
#include "lcd.h"

typedef struct  {
        Matriz_t* matriz;
        uint8_t indice_fil;
        uint8_t indice_col;
        uint8_t tam_pincel;
} Dibujo_t;


Dibujo_t* crearDibujo();
void dibujoBorrar(Dibujo_t* dibujo);
void dibujoAvanzar(Dibujo_t* dibujo, BotonEvento_t input);
void dibujoReiniciar(Dibujo_t* dibujo);
void dibujoPintar(Dibujo_t* dibujo, uint8_t red, uint8_t green, uint8_t blue);
void dibujoCambiarPincel(Dibujo_t* dibujo);
#endif
