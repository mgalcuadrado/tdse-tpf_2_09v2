/*
 * mocks/main.h
 *
 * MOCK de main.h: en la placa real, HAL_GetTick() la provee la HAL de
 * ST (incrementa sola con el SysTick). Acá la simulamos con un
 * contador que los tests controlan a mano, para poder probar delays
 * no bloqueantes sin tener que esperar tiempo real.
*/

#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

uint32_t HAL_GetTick(void);

// --- Utilidades del mock, solo para los tests ---
void mock_tick_setear(uint32_t valor_ms);
void mock_tick_avanzar(uint32_t delta_ms);

#endif
