#ifndef TEST_WCET_ADC_H
#define TEST_WCET_ADC_H

#include <stdint.h>

/*Prueba de WCET de leer_potenciometros().
Realiza NUM_MEDICIONES_WCET y muestra:
 - mínimo
 - promedio
 - máximo (WCET observado)
Los tiempos se expresan en ciclos de CPU y microsegundos.*/
void testWCETADC(void);

#endif