/*
 * boton.h
 *
 * Created on: Ago 4, 2026
 *      Author: Bauti
*/
#ifndef BOTON_H
#define BOTON_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum  {
        BOTON_NINGUNO = 0,
        BOTON_ARRIBA,
        BOTON_ABAJO,
		BOTON_IZQUIERDA,
		BOTON_DERECHA,
        BOTON_ACEPTAR,
        BOTON_ATRAS
}BotonEvento_t;
// Tiempo mínimo para captar una respuesta
#define DEBOUNCE_MS 50

BotonEvento_t botonLeer(void);
BotonEvento_t botonUltimoEvento(void);
#endif
