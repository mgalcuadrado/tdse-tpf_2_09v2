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
    ESTADO_SETUP = 0,
	ESTADO_NORMAL,
    ESTADO_FALLA,
} EstadoOperacion_t;

typedef enum {
    ESTADO_MENU_PRINCIPAL = 0,
	ESTADO_CAMBIANDO_BRILLO,
    ESTADO_MENU_DIBUJO,
	ESTADO_GUARDANDO_DIBUJO,
	ESTADO_CARGANDO_DIBUJO,
	ESTADO_LIMPIAR_DIBUJO,
    ESTADO_DIBUJANDO,
    ESTADO_CAMBIANDO_PINCEL,
    ESTADO_MENU_SECUENCIA,
    ESTADO_COMPLETANDO_SECUENCIA,
	ESTADO_MOSTRANDO_SECUENCIA,
	ESTADO_LIMPIAR_SECUENCIA
} EstadoSistema_t;


void sistemaInit(void);

void sistemaProcesar(void); // Adjunta todas las funciones necesarias para el funcionamiento del menu

void sistemaTick(BotonEvento_t input);// Llamar una vez por vuelta del loop principal, con el evento leído por botonLeer()

void sistemaCambiarOperacion(EstadoOperacion_t nueva_operacion);

void sistemaCambiarEstado(EstadoSistema_t nuevo_estado); // Usada por los módulos de menú para pedir una transición de pantalla

void sistemaTickTiempo(void); // no depende de botones

void sistemaError();

Matriz_t* sistemaObtenerMatrizActiva(void);

#endif
