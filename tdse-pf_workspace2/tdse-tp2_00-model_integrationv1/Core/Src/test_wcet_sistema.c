#include "test_wcet_sistema.h"
#include "estado.h"

#include <stdio.h>
#include <stdint.h>

#include "stm32f1xx.h"

#define CPU_FREQ_MHZ          64U
#define NUM_MEDICIONES_WCET  1000U

void testWCETSistema(BotonEvento_t evento) {
    uint32_t mediciones = 0;

    uint32_t wcet = 0;

    uint32_t minimo = 0xFFFFFFFFUL;

    uint64_t suma = 0;

    while (mediciones < NUM_MEDICIONES_WCET) {
        uint32_t inicio;
        uint32_t fin;
        uint32_t ciclos;

        inicio = DWT->CYCCNT;
        sistemaTick(evento);
        fin = DWT->CYCCNT;
        ciclos = fin - inicio;

        //ACTUALIZAR 
        if (ciclos > wcet) {
            wcet = ciclos;
        }
        if (ciclos < minimo) {
            minimo = ciclos;
        }

        suma += ciclos;
        mediciones++;
    }

    //PROMEDIO
    uint32_t promedio = (uint32_t)(suma / mediciones);
    //A MICROSEGUNDOS
    uint32_t wcet_us_x1000 = (wcet * 1000UL) / CPU_FREQ_MHZ;

    uint32_t minimo_us_x1000 = (minimo * 1000UL) / CPU_FREQ_MHZ;

    uint32_t promedio_us_x1000 = (promedio * 1000UL) / CPU_FREQ_MHZ;

    printf("TEST WCET - SISTEMA\r\n");
    
    printf("Mediciones: %lu\r\n", (unsigned long)mediciones);
    printf("\r\n");

    printf("Minimo: %lu ciclos\r\n", (unsigned long)minimo);

    printf("Promedio: %lu ciclos\r\n", (unsigned long)promedio);

    printf("WCET: %lu ciclos\r\n", (unsigned long)wcet);
    printf("\r\n");

    printf("Minimo: %lu.%03lu us\r\n", (unsigned long)(minimo_us_x1000 / 1000UL), (unsigned long)(minimo_us_x1000 % 1000UL));

    printf("Promedio: %lu.%03lu us\r\n", (unsigned long)(promedio_us_x1000 / 1000UL), (unsigned long)(promedio_us_x1000 % 1000UL));

    printf("WCET: %lu.%03lu us\r\n", (unsigned long)(wcet_us_x1000 / 1000UL), (unsigned long)(wcet_us_x1000 % 1000UL));
}
