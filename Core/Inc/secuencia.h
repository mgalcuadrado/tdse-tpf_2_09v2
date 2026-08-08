#ifndef SECUENCIA_H
#define SECUENCIA_H

#include "matriz.h"
#include <stdbool.h>
#include "boton.h"


#define CANT_ELEMENTOS 16 // 32 x 32 dado un pincel de 8 x 8 = 4 x 4 casilleros
#define TAM_PINCEL_SECUENCIA 8
#define DIM_SECUENCIA 4 // 4 x 4 la matriz de secuencia

//Cambiar casillero

typedef struct Secuencia_t {
        uint8_t lista_sec[2][CANT_ELEMENTOS];
        uint8_t indice_sec;
} Secuencia_t;


Secuencia_t* crearSecuencia(void);
void insertarElemento(Secuencia_t* sec, uint8_t color, Matriz_t* matriz, uint8_t fil, uint8_t col);
uint8_t elementoActualSecuencia(Secuencia_t* sec);
void avanzarSecuencia(Secuencia_t* sec, BotonEvento_t input);
void printSecuencia(Secuencia_t* sec);
void vaciarSecuencia(Secuencia_t* sec);
bool secuenciaCompleta(Secuencia_t* sec);
void secuenciaBorrar(Secuencia_t* sec);
#endif
