#include "potenciometro.h"
#include <stdlib.h>

extern ADC_HandleTypeDef hadc1;

#define UMBRAL_FILTRO 2
#define POLL_TIMEOUT_MS 1


static uint8_t valor_r = 0;
static uint8_t valor_g = 0;
static uint8_t valor_b = 0;


static bool leer_3_canales(uint16_t raw[3]) {
    HAL_ADC_Start(&hadc1);

    for (int i = 0; i < 3; i++) {
        if (HAL_ADC_PollForConversion(&hadc1, POLL_TIMEOUT_MS) != HAL_OK)
        {
            HAL_ADC_Stop(&hadc1);
            return false;
        }

        raw[i] = (uint16_t)HAL_ADC_GetValue(&hadc1);
    }

    HAL_ADC_Stop(&hadc1);

    return true;
}


static uint8_t aplicar_filtro_ruido(uint8_t nuevo, uint8_t anterior) {
    if (abs((int)nuevo - (int)anterior) <= UMBRAL_FILTRO) {
        return anterior;
    }
    return nuevo;
}

/*
 * Inicializa el TDA de potenciómetros.
 *
 * Como la lectura se realiza mediante polling,
 * no es necesario iniciar una conversión aquí.
 */
void pote_init(void)
{
    /*
     * Cada lectura se dispara desde
     * escrutar_potenciometros().
     */
}


uint8_t adc_a_color(uint16_t valor_raw) {
    return (uint8_t)(valor_raw >> 4);
}


/*Lee los tres potenciómetros, convierte sus valores y actualiza las variables internas R, G y B.
 * Canal ADC 0 -> Rojo
 * Canal ADC 1 -> Verde
 * Canal ADC 4 -> Azul
 */
void escrutar_potenciometros(void) {
    uint16_t raw[3] = {0};

    if (!leer_3_canales(raw)) {
        return;
    }

    uint8_t r_nuevo = adc_a_color(raw[0]);
    uint8_t g_nuevo = adc_a_color(raw[1]);
    uint8_t b_nuevo = adc_a_color(raw[2]);

    //Filtro.
    valor_r = aplicar_filtro_ruido(r_nuevo, valor_r);
    valor_g = aplicar_filtro_ruido(g_nuevo, valor_g);
    valor_b = aplicar_filtro_ruido(b_nuevo, valor_b);
}


/*Getter de los valores actuales de los potenciómetros.
Devuelve los valores actuales de R, G y B.*/

Potenciometros_t obtener_potenciometros(void) {
    Potenciometros_t valores;

    valores.r = valor_r;
    valores.g = valor_g;
    valores.b = valor_b;

    return valores;
}
