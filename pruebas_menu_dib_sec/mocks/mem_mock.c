#include "mem.h"

int memEscribirMatriz_llamadas = 0;
int memLeerMatriz_llamadas = 0;
uint32_t mem_ultima_direccion = 0;

void memEscribirMatriz(uint32_t direccion, Matriz_t* matriz) {
    (void)matriz;
    memEscribirMatriz_llamadas++;
    mem_ultima_direccion = direccion;
}

void memLeerMatriz(uint32_t direccion, Matriz_t* matriz) {
    (void)matriz;
    memLeerMatriz_llamadas++;
    mem_ultima_direccion = direccion;
}
