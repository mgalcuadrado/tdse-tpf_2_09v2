#ifndef SECUENCIA_H
#define SECUENCIA_H

#include "matriz.h"
#include <stdbool.h>

#define CANT_ELEMENTOS 16 // 32 x 32 dado un pincel de 8 x 8 = 4 x 4 casilleros
#define TAM_PINCEL_SECUENCIA 8
#define DIM_SECUENCIA 4 // 4 x 4 la matriz de secuencia

//Cambiar casillero

typedef struct Secuencia_t {
        uint8_t lista_sec[2][CANT_ELEMENTOS];
        uint8_t indice_sec;
} Secuencia_t;


Secuencia_t* crearSecuencia(void);
void insertar_elemento(Secuencia_t* sec, uint8_t color, Matriz_t* matriz, uint8_t fil, uint8_t col);
void print_secuencia(Secuencia_t* sec);
void vaciar_secuencia(Secuencia_t* sec);
bool secuencia_completa(Secuencia_t* sec);
void secuenciaBorrar(Secuencia_t* sec);
#endif
