/*
 * secuencia.c
 *
 * Created on: Jul 26, 2026
 *      Author: Bauti
*/


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


Secuencia_t* secuenciaCrear(void);
void secuenciaInsertarElemento(Secuencia_t* sec, uint8_t color, Matriz_t* matriz, uint8_t fil, uint8_t col);
uint8_t secuenciaElementoActual(Secuencia_t* sec);
void secuenciaAvanzar(Secuencia_t* sec, BotonEvento_t input,  Matriz_t* matriz);
void secuenciaPrint(Secuencia_t* sec);
void secuenciaVaciar(Secuencia_t* sec);
bool secuenciaCompleta(Secuencia_t* sec);
void secuenciaBorrar(Secuencia_t* sec);

// Pinta una sección (bloque de TAM_PINCEL_SECUENCIA x TAM_PINCEL_SECUENCIA) dado su
// índice (0..CANT_ELEMENTOS-1) con el color RGB indicado. Se expone para poder usarla
// tanto para el cursor como para mostrar la secuencia objetivo y marcar aciertos/errores
// desde otros módulos (por ej. menu_secuencia).
void secuenciaPintarSeccion(Matriz_t* matriz, uint8_t pos, uint8_t r, uint8_t g, uint8_t b);

#endif
