/*
 * mocks/frame_buffer.h
 *
 * MOCK para tests de escritorio: solo cuenta cuántas veces se pidió
 * refrescar el frame buffer, no dibuja nada de verdad.
*/

#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

#include "matriz.h"

void frameBufferUpdate(Matriz_t* matriz);

extern int frameBufferUpdate_llamadas;

#endif
