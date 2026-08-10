/*
 * mocks/secuencia.h
 *
 * MOCK del header (no tenías secuencia.h en los archivos que me
 * pasaste, solo secuencia.c). La implementación de secuencia.c SÍ es
 * la tuya real, sin modificar -- este header solo declara lo que
 * secuencia.c y menu_secuencia.c necesitan para compilar.
 *
 * IMPORTANTE: si tu secuencia.h real define DIM_SECUENCIA,
 * CANT_ELEMENTOS o TAM_PINCEL_SECUENCIA con otros valores, ajustalos
 * acá para que los tests reflejen tu configuración real.
*/

#ifndef SECUENCIA_H
#define SECUENCIA_H

#include <stdint.h>
#include <stdbool.h>
#include "matriz.h"
#include "boton.h"

#define DIM_SECUENCIA 4
#define CANT_ELEMENTOS (DIM_SECUENCIA * DIM_SECUENCIA)
#define TAM_PINCEL_SECUENCIA 2

typedef struct {
    uint8_t lista_sec[2][CANT_ELEMENTOS];
    uint8_t indice_sec;
} Secuencia_t;

Secuencia_t* secuenciaCrear(void);
void secuenciaInsertarElemento(Secuencia_t* sec, uint8_t color, Matriz_t* matriz, uint8_t fil, uint8_t col);
void secuenciaAvanzar(Secuencia_t* sec, BotonEvento_t input);
uint8_t secuenciaElementoActual(Secuencia_t* sec);
void secuenciaPrint(Secuencia_t* sec);
void secuenciaVaciar(Secuencia_t* sec);
bool secuenciaCompleta(Secuencia_t* sec);
void secuenciaBorrar(Secuencia_t* sec);

#endif
