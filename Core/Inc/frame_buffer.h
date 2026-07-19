/*
 * frame_buffer.h
 *
 *  Created on: Jul 18, 2026
 *      Author: Mechi
 */

#ifndef INC_FRAME_BUFFER_H_
#define INC_FRAME_BUFFER_H_

#include "stdint.h" 
#include "main.h"
#include "matriz.h"

//mgalcuadrado: acá hardcodeé esto en 16x32 para trabajar con solo una matriz
#define BUFFER_FILAS 16/2//MATRIZ_FILAS/2
#define BUFFER_COLUMNAS 32 //MATRIZ_COLUMNAS*2

extern uint32_t framebuffer[BUFFER_FILAS][BUFFER_COLUMNAS];



// frameBufferInit crea una trama de datos para la pantalla en negro (todo apagado)
void frameBufferInit(void);
void frameBufferUpdate(Matriz_t*);

#endif