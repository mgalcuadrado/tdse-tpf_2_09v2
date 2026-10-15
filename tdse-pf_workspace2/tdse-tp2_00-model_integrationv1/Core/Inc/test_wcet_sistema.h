#ifndef TEST_WCET_SISTEMA_H
#define TEST_WCET_SISTEMA_H

#include "boton.h"

/*Prueba de WCET de sistemaTick().
Evento de botón utilizado durante la prueba.
NUM_MEDICIONES_WCET  y muestra:
 - mínimo
 - promedio
 - máximo (WCET observado)
Los tiempos se expresan en ciclos de CPU y microsegundos.*/
void testWCETSistema(BotonEvento_t evento);

#endif