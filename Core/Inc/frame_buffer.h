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
#define BUFFER_FILAS 2//ESCANEO 1/2 DE LAS PANTALLAS P10
#define BUFFER_COLUMNAS 128 //CADA FILA TIENE QUE ESCRIBIR MATRIZ_FILAS/BUFFER_FILAS DE 32 COLUMNAS (2 PIXELES A LA VEZ)

extern uint32_t framebuffer[BUFFER_FILAS][BUFFER_COLUMNAS];



// frameBufferInit crea una trama de datos para la pantalla en negro (todo apagado)
void frameBufferInit(void);
void frameBufferUpdate(Matriz_t*);

#endif