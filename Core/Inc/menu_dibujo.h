/*
 * menu_dibujo.c
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
*/

#ifndef MENU_DIBUJO_H
#define MENU_DIBUJO_H

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include "secuencia.h"
#include "dibujo.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"

BotonEvento_t seleccionDibujo (char seleccion[6], int indice_seleccion);

void interaccionMenuDibujo (BotonEvento_t input, char seleccion[6], int* indice_seleccion, Dibujo_t* dibujo);

void opcionElegidaDibujo (int indice_seleccion, Dibujo_t* dibujo);

void dibujar(Dibujo_t* dibujo);

void menuDibujo (void);

#endif

