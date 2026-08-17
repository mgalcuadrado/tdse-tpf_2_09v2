#include "potenciometro.h"
#include <stdlib.h>

extern ADC_HandleTypeDef hadc1;

#define UMBRAL_FILTRO      2
#define POLL_TIMEOUT_MS    10


static uint8_t valor_r = 0;
static uint8_t valor_g = 0;
static uint8_t valor_b = 0;

static bool leer_3_canales(uint16_t raw[3]) {
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


static uint8_t aplicar_filtro_ruido(uint8_t nuevo, uint8_t anterior) {
    if (abs((int)nuevo - (int)anterior) <= UMBRAL_FILTRO) {
        return anterior;
    }
    return nuevo;
}

/*Como la lectura se realiza mediante polling, no es necesario iniciar una conversión en esta función.*/
void pote_init(void) {
    /*Cada lectura se dispara desde escrutar_potenciometros().*/
}

uint8_t adc_a_color(uint16_t valor_raw) {
    return (uint8_t)(valor_raw >> 4);
}


/*Lee los tres potenciómetros y actualiza los valores internos R, G y B.*/
void escrutar_potenciometros(void) {
    uint16_t raw[3] = {0};

    /*Ante timeout, no se modifican los valores actuales. Se conserva el último valor válido.*/
    if (!leer_3_canales(raw)) {
        return;
    }


    /*Conversión ADC -> color.
     *Los tres potenciómetros utilizan exactamente
     la misma conversión: 0 ... 4095  ->  0 ... 255*/

    uint8_t r_nuevo = adc_a_color(raw[0]);
    uint8_t g_nuevo = adc_a_color(raw[1]);
    uint8_t b_nuevo = adc_a_color(raw[2]);

    valor_r = aplicar_filtro_ruido(r_nuevo, valor_r);
    valor_g = aplicar_filtro_ruido(g_nuevo, valor_g);
    valor_b = aplicar_filtro_ruido(b_nuevo, valor_b);
}


/*Obtiene los valores actuales de los tres colores.
 Devuelve struct Potenciometros_t con los valores
 actuales de R, G y B.*/
Potenciometros_t procesar_potenciometros(void) {
    Potenciometros_t valores;

    valores.r = valor_r;
    valores.g = valor_g;
    valores.b = valor_b;
    return valores;
}
