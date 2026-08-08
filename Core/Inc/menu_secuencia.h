/*
 * menu_secuencia.c
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
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "boton.h"
#include "menu_principal.h"

#define MAX_CARACTERES_MENSAJE 50

BotonEvento_t menuSecuenciaSeleccion(char seleccion[3], int indice_seleccion);

void menuSecuenciaInteraccion (BotonEvento_t input, char seleccion[3], int* indice_seleccion, Secuencia_t* secuencia, Matriz_t* matriz);

void menuSecuenciaOpcionElegida (int indice_seleccion, Secuencia_t* secuencia, Matriz_t* matriz);

void menuSecuenciaCompletar(Secuencia_t* secuencia, Matriz_t* matriz);

void menuSecuenciaMain (void);
#endif

