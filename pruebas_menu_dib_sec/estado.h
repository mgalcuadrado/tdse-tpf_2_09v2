/*
 * estado.h
 *
 * Módulo orquestador: reemplaza a los `while(1)` anidados de
 * menuPrincipalMain / menuDibujoMain / menuSecuenciaMain por una
 * única máquina de estados que se "tickea" una vez por vuelta del
 * loop principal, sin bloquear nunca la CPU.
 *
 *      Author: Bauti (migración no bloqueante)
*/

#ifndef ESTADO_H
#define ESTADO_H

#include "boton.h"

typedef enum {
    ESTADO_MENU_PRINCIPAL = 0,
    ESTADO_MENU_DIBUJO,
    ESTADO_DIBUJANDO,
    ESTADO_CAMBIANDO_PINCEL,
    ESTADO_MENU_SECUENCIA,
    ESTADO_COMPLETANDO_SECUENCIA
} EstadoSistema_t;

// Llamar una sola vez al arrancar, después de los inits de HAL/periféricos
void sistemaInit(void);

// Llamar una vez por vuelta del loop principal, con el evento leído por botonLeer()
void sistemaTick(BotonEvento_t input);



// Usada por los módulos de menú para pedir una transición de pantalla
void sistemaCambiarEstado(EstadoSistema_t nuevo_estado);

// Getter de solo lectura: útil para debug y para tests automatizados.
EstadoSistema_t sistemaObtenerEstado(void);

#endif
