#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

#include <stdint.h>
#include <stdbool.h>


typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t brillo;

} Potenciometros_t;



void leer_potenciometros(Potenciometros_t *pots);


uint8_t adc_a_posicion(uint16_t valor_raw);


uint8_t adc_a_brillo(uint16_t valor_raw);


bool posicion_cambio(uint8_t x,
                     uint8_t y);


#endif