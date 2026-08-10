#include "main.h"

static uint32_t tick_actual_ms = 0;

uint32_t HAL_GetTick(void) {
    return tick_actual_ms;
}

void mock_tick_setear(uint32_t valor_ms) {
    tick_actual_ms = valor_ms;
}

void mock_tick_avanzar(uint32_t delta_ms) {
    tick_actual_ms += delta_ms;
}
