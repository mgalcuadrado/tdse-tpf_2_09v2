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

void menuSecuenciaEntrar(void);

void menuSecuenciaTick(BotonEvento_t input);

// Prepara e inicializa la pantalla que muestra, sección por sección, la secuencia
// objetivo que el usuario deberá repetir. Debe llamarse una sola vez al entrar
// al estado ESTADO_MOSTRANDO_SECUENCIA.
void menuSecuenciaMostrarEntrar(void);

// Tick no bloqueante de la pantalla de mostrado: cada ~3 segundos (ver
// TIEMPO_MOSTRAR_SECCION_MS) avanza a la siguiente sección y la pinta de azul si
// corresponde. Al terminar de mostrar todas las secciones, pasa automáticamente
// a ESTADO_COMPLETANDO_SECUENCIA. No depende de los botones, pero se mantiene la
// firma BotonEvento_t para llamarla de forma uniforme desde el dispatcher de estados.
void menuSecuenciaMostrarTick(void);

void menuSecuenciaCompletarTick(BotonEvento_t input);

void menuSecuenciaPrint(char seleccion[3], int indice_seleccion);

void menuSecuenciaOpcionElegida(int indice_seleccion);

void menuSecuenciaCompletandoPrint(BotonEvento_t input);

Matriz_t* menuSecuenciaObtenerMatriz(void);

void menuSecuenciaLimpiandoTick(BotonEvento_t input);

#endif
