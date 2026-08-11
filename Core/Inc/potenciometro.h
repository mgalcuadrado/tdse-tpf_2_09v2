#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

#include <stdint.h>
#include <stdbool.h>


void leer_potenciometros(uint8_t *r, uint8_t *g, uint8_t *b);
uint8_t adc_a_posicion(uint16_t valor_raw);
uint8_t adc_a_brillo(uint16_t valor_raw);
bool posicion_cambio(uint8_t x, uint8_t y);


#endif
