#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include "secuencia.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"

void menu_pixelart (void);

void menu_secuencia (void);

char seleccion_pixelart (char seleccion[7], int indice_seleccion);

char seleccion_secuencia(char seleccion[3], int indice_seleccion);

void interaccion_menu_pixelart (char input, char seleccion[7], int indice_seleccion, Matriz_t* matriz);

void interaccion_menu_secuencia (char input, char seleccion[3], int indice_seleccion, Secuencia_t* secuencia);

void opcion_elegida_pixelart (int indice_seleccion, Matriz_t* matriz);

void opcion_elegida_secuencia (int indice_seleccion, Secuencia_t* matriz);

#endif

