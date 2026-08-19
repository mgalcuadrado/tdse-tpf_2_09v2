#include "potenciometro.h"
#include "stm32f1xx_hal.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define UMBRAL_FILTRO 2
extern ADC_HandleTypeDef hadc1;

uint16_t muestras_adc[3] = {0,0,0};

static volatile uint8_t flagADCLectura = 0;
static uint8_t valor_r = 0;
static uint8_t valor_g = 0;
static uint8_t valor_b = 0;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	if (hadc->Instance == ADC1) {
	        flagADCLectura = 1;
	}
}

static uint8_t aplicar_filtro_ruido(uint8_t nuevo, uint8_t anterior) {
    if (abs((int)nuevo - (int)anterior) <= UMBRAL_FILTRO) {
        return anterior;
    }

    return nuevo;
}


void poteInit(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*) muestras_adc, 3);
}


uint8_t adc_a_color(uint16_t valor_raw) {
    return (uint8_t)(valor_raw >> 4);
}


void escrutarPotenciometros(void) {
    if (!flagADCLectura) {
        return;
    }
    flagADCLectura = 0;
    uint8_t r_nuevo = adc_a_color(muestras_adc[0]);
    uint8_t g_nuevo = adc_a_color(muestras_adc[1]);
    uint8_t b_nuevo = adc_a_color(muestras_adc[2]);

    /*
     * Aplicación del filtro de ruido.
     */
    valor_r = aplicar_filtro_ruido(r_nuevo, valor_r);
    valor_g = aplicar_filtro_ruido(g_nuevo, valor_g);
    valor_b = aplicar_filtro_ruido(b_nuevo, valor_b);
}


Potenciometros_t obtenerPotenciometros(void) {
    Potenciometros_t valores;

    valores.r = valor_r;
    valores.g = valor_g;
    valores.b = valor_b;

    return valores;
}
