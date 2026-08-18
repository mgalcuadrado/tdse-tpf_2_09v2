#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Potenciometros_t;


void escrutarPotenciometros(void);

Potenciometros_t obtenerPotenciometros(void);

#endif
