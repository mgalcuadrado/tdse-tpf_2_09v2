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
        uint8_t indice_fil;
        uint8_t indice_col;
        uint8_t tam_pincel;
        Casillero_t* color_anterior;
} Dibujo_t;

#define MAX_CARACTERES_MENSAJE 50

Dibujo_t* dibujoCrear();
void dibujoBorrar(Dibujo_t* dibujo);
void dibujoAvanzar(Dibujo_t* dibujo, BotonEvento_t input);
void dibujoReiniciar(Dibujo_t* dibujo);
void dibujoPintar(Dibujo_t* dibujo, uint8_t red, uint8_t green, uint8_t blue);

// Reemplaza a dibujoCambiarPincel(Dibujo_t*): procesa UN evento y vuelve.
// Devuelve true cuando el usuario terminó de elegir pincel (ACEPTAR o ATRAS),
// momento en el que quien la llama debe volver al menú anterior.
bool dibujoCambiarPincelTick(Dibujo_t* dibujo, BotonEvento_t input);

#endif
