/*
 * menu_dibujo.h
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
 *
*/

#ifndef MENU_DIBUJO_H
#define MENU_DIBUJO_H

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include "secuencia.h"
#include "dibujo.h"
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"

#define MAX_CARACTERES_MENSAJE 50

void menuDibujoEntrar(void);

void menuDibujoTick(BotonEvento_t input);

void menuDibujoDibujarTick(BotonEvento_t input);

void menuDibujoLimpiandoTick(BotonEvento_t input);

void menuDibujoCambiarPincelTick(BotonEvento_t input);

void menuDibujoMostrar(char seleccion[6], int indice_seleccion);

void menuDibujoOpcionElegida(int indice_seleccion);

#endif
