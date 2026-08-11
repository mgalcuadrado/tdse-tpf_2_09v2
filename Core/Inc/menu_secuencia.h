/*
 * menu_secuencia.h
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
*/

#ifndef MENU_SECUENCIA_H
#define MENU_SECUENCIA_H

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include "secuencia.h"
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "boton.h"

#define MAX_CARACTERES_MENSAJE 50

void menuSecuenciaEntrar(void);

void menuSecuenciaTick(BotonEvento_t input);

void menuSecuenciaCompletarTick(BotonEvento_t input);

void menuSecuenciaMostrar(char seleccion[3], int indice_seleccion);

void menuSecuenciaOpcionElegida(int indice_seleccion);

#endif
