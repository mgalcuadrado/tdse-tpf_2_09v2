#ifndef potenciometro_H
#define potenciometro_h

#include <stdint.h>
#include <stdbool.h>


typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;

} Potenciometros_t;


void pote_init(void);

uint8_t adc_a_color(uint16_t valor_raw);

void escrutar_potenciometros(void);

Potenciometros_t procesar_potenciometros(void);

#endif
