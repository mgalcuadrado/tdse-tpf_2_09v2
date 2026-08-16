#ifndef TEST_WCET_HUB75_H
#define TEST_WCET_HUB75_H

#include <stdint.h>

/*Prueba WCET de hub75Refresh().
Se hacen NUM_MEDICIONES_WCET y muestra:
 - mínimo
 - promedio
 - máximo (WCET observado)
Los tiempos se expresan en ciclos de CPU y microsegundos.*/
void testWCETHUB75(void);

#endif 