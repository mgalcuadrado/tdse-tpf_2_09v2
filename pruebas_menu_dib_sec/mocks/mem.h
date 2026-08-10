/*
 * mocks/mem.h
 *
 * MOCK para tests de escritorio: no escribe a ninguna memoria externa
 * real, solo cuenta llamadas y guarda la última dirección usada.
*/

#ifndef MEM_H
#define MEM_H

#include <stdint.h>
#include "matriz.h"

void memEscribirMatriz(uint32_t direccion, Matriz_t* matriz);
void memLeerMatriz(uint32_t direccion, Matriz_t* matriz);

extern int memEscribirMatriz_llamadas;
extern int memLeerMatriz_llamadas;
extern uint32_t mem_ultima_direccion;

#endif
