#ifndef SECUENCIA_H
#define SECUENCIA_H

#include <matriz.h>
#include <stdbool.h>

#define CANT_ELEMENTOS 25 // 32 x 32 dado un pincel de 8 x 8 = 5 x 5 casilleros

typedef struct {
        Casillero_t lista_sec[2][MAX_ELEMENTOS];
        uint8_t indice_sec;
} Secuencia_t;


Secuencia_t* crearSecuencia();
void insertar_elemento(Secuencia_t* sec, uint8_t red, uint8_t green, uint8_t blue, Matriz_t* matriz, uint8_t fil, uint8_t col);
void vaciar_secuencia(Secuencia_t* sec);
bool secuencia_completa(Secuencia_t* sec);
void secuenciaBorrar(Secuencia_t* sec);
#endif