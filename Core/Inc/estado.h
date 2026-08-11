/*
 * estado.h
 *	Created on: Aug 8, 2026
 *      Autor: Bauti
*/

#ifndef ESTADO_H
#define ESTADO_H

#include "boton.h"
#include "matriz.h"

typedef enum {
    ESTADO_MENU_PRINCIPAL = 0,
	ESTADO_CAMBIANDO_BRILLO,
    ESTADO_MENU_DIBUJO,
	ESTADO_LIMPIAR_DIBUJO,
    ESTADO_DIBUJANDO,
    ESTADO_CAMBIANDO_PINCEL,
    ESTADO_MENU_SECUENCIA,
    ESTADO_COMPLETANDO_SECUENCIA,
	ESTADO_LIMPIAR_SECUENCIA
} EstadoSistema_t;

// Llamar una sola vez al arrancar, después de los inits de HAL/periféricos
void sistemaInit(void);

// Llamar una vez por vuelta del loop principal, con el evento leído por botonLeer()
void sistemaTick(BotonEvento_t input);

// Usada por los módulos de menú para pedir una transición de pantalla
void sistemaCambiarEstado(EstadoSistema_t nuevo_estado);

Matriz_t* sistemaObtenerMatrizActiva(void);

#endif
