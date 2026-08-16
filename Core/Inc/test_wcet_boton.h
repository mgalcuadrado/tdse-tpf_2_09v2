#ifndef TEST_WCET_BOTON_H
#define TEST_WCET_BOTON_H

#include <stdint.h>

/*Prueba de WCET de botonLeer().
Realiza NUM_MEDICIONES_WCET y muestra:
 - mínimo
 - promedio
 - máximo (WCET observado)
Los tiempos se expresan en ciclos de CPU y microsegundos.*/
void testWCETBoton(void);

#endif