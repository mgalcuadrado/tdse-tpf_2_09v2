#include "potenciometro.h"
#include <stdlib.h>
extern ADC_HandleTypeDef hadc1;


uint16_t adc_buffer[3];


extern ADC_HandleTypeDef hadc1;

#define UMBRAL_FILTRO      2
#define POSICION_INICIAL   255
#define POLL_TIMEOUT_MS    10

/**
 * @brief Dispara una conversión de los 3 canales ya configurados
 *        (Rank 1, 2, 3) y espera activamente (polling) a que cada
 *        una termine, leyendo los 3 valores en orden.
 * @param raw Array de 3 posiciones donde se guardan los valores crudos.
 * @return true si las 3 conversiones se completaron a tiempo, false si
 *         alguna dio timeout.
 */
static bool leer_3_canales(uint16_t raw[3])
{
    HAL_ADC_Start(&hadc1);

    for (int i = 0; i < 3; i++) {
        if (HAL_ADC_PollForConversion(&hadc1, POLL_TIMEOUT_MS) != HAL_OK) {
            HAL_ADC_Stop(&hadc1);
            return false;
        }
        raw[i] = (uint16_t)HAL_ADC_GetValue(&hadc1);
    }

    HAL_ADC_Stop(&hadc1);
    return true;
}

static uint8_t aplicar_filtro_ruido(uint8_t nuevo, uint8_t anterior)
{
    if (abs((int)nuevo - (int)anterior) <= UMBRAL_FILTRO) {
        return anterior;
    }
    return nuevo;
}

void pote_init(void)
{
    /* Con polling no hace falta arrancar nada de antemano:
     * cada lectura se dispara sola en leer_potenciometros().
     * Se deja vacía/mínima a propósito. */
}

uint8_t adc_a_posicion(uint16_t valor_raw)
{
    return (uint8_t)((valor_raw * 32) / 4096);
}

uint8_t adc_a_brillo(uint16_t valor_raw)
{
    return (uint8_t)(valor_raw >> 4);
}

void leer_potenciometros(uint8_t *r, uint8_t *g, uint8_t *b)
{
    static uint8_t r_anterior = 0;
    static uint8_t g_anterior = 0;
    static uint8_t b_anterior = 0;

    uint16_t raw[3] = {0};

    if (!leer_3_canales(raw)) {
        /* Timeout: no actualizamos nada, devolvemos el último valor
         * filtrado conocido en vez de basura. */
        *r = r_anterior;
        *g = g_anterior;
        *b = b_anterior;
        return;
    }

    uint8_t r_nuevo = adc_a_posicion(raw[0]);
    uint8_t g_nuevo = adc_a_posicion(raw[1]);
    uint8_t b_nuevo = adc_a_brillo(raw[2]);

    r_anterior = aplicar_filtro_ruido(r_nuevo, r_anterior);
    g_anterior = aplicar_filtro_ruido(g_nuevo, g_anterior);
    b_anterior = aplicar_filtro_ruido(b_nuevo, b_anterior);

    *r = r_anterior;
    *g = g_anterior;
    *b = b_anterior;
}

bool posicion_cambio(uint8_t x, uint8_t y)
{
    static uint8_t old_x = POSICION_INICIAL;
    static uint8_t old_y = POSICION_INICIAL;

    if (x != old_x || y != old_y) {
        old_x = x;
        old_y = y;
        return true;
    }
    return false;
}
