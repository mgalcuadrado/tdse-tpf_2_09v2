/*
 * menu_principal.c
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
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "menu_dibujo.h"
#include "menu_secuencia.h"

#define MAX_CARACTERES_MENSAJE 50

void menuPrincipalMain (void);
void menuPrincipalPrint(char seleccion[3], int indice_seleccion);
#endif

