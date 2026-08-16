#include "test_wcet_hub75.h"
#include "hub75.h"

#include <stdio.h>
#include <stdint.h>

#include "core_cm3.h"


//CONFIGURACIÓN

#define CPU_FREQ_MHZ          64U
#define NUM_MEDICIONES_WCET  1000U


//FUNCIÓN DE TESTEO

void testWCETHUB75(void) {
    uint32_t mediciones = 0;

    uint32_t wcet = 0;

    uint32_t minimo = 0xFFFFFFFFUL;

    uint64_t suma = 0;

    //Se hacen las mediciones
    while (mediciones < NUM_MEDICIONES_WCET) {
        uint32_t inicio;
        uint32_t fin;
        uint32_t ciclos;

        inicio = DWT->CYCCNT;
        /* Función a medir */
        hub75Refresh();
        fin = DWT->CYCCNT;
        /* Diferencia de ciclos */
        ciclos = fin - inicio;

        //ACTUALIZAMOS ESTADÍSTICAS
        
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

    printf("\r\n");
    printf("TEST WCET - HUB75\r\n");

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