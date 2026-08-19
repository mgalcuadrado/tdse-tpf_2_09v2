#ifndef TEST_WCET_LCD_H
#define TEST_WCET_LCD_H

#include "boton.h"

/*Prueba de WCET de sistemaTick().
Evento de botón utilizado durante la prueba.
NUM_MEDICIONES_WCET  y muestra:
 - mínimo
 - promedio
 - máximo (WCET observado)
Los tiempos se expresan en ciclos de CPU y microsegundos.*/
void testWCETLCD(void);

#endif
