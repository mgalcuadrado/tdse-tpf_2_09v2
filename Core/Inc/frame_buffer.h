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

#define BUFFER_FILAS 2
#define BUFFER_COLUMNAS 256

extern volatile uint32_t framebuffer[BUFFER_FILAS][BUFFER_COLUMNAS];



// frameBufferInit crea una trama de datos para la pantalla en negro (todo apagado)
void frameBufferInit(void);
void frameBufferUpdateCasilla(Matriz_t*, int, int);
//void frameBufferUpdateAll(Matriz_t *);
void testBarridoCompleto(Matriz_t *);
void testBarridoBuffer(void);
#endif