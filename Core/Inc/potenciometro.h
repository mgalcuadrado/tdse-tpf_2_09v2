#ifndef potenciometro_h
#define potenciometro_h

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Potenciometros_t;

void pote_init(void);

void escrutar_potenciometros(void);

Potenciometros_t procesar_potenciometros(void);

/* Convierte un valor ADC a una posición de la matriz */
uint8_t adc_a_posicion(uint16_t valor_raw);

/* Convierte un valor ADC a brillo */
uint8_t adc_a_brillo(uint16_t valor_raw);

/* Determina si hubo un cambio de posición */
bool posicion_cambio(uint8_t x, uint8_t y);

#endif
