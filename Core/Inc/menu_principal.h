/*
 * menu_principal.h
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
*/


#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include "secuencia.h"
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "boton.h"

#define MAX_CARACTERES_MENSAJE 20
#define MAX_BRILLO 100
#define MIN_BRILLO 25

void menuPrincipalEntrar(void);

void menuPrincipalTick(BotonEvento_t input);

void menuPrincipalOpcionElegida(int indice_seleccion);

void menuPrincipalCambiandoBrilloTick(BotonEvento_t input);

void menuPrincipalPrint(char seleccion[3], int indice_seleccion);

#endif
