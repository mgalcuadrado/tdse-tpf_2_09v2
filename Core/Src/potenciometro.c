#include "potenciometro.h"
#include <stdlib.h>

extern ADC_HandleTypeDef hadc1;

#define UMBRAL_FILTRO      2
#define POSICION_INICIAL   255
#define POLL_TIMEOUT_MS    10


//VARIABLES INTERNAS DEL TDA

static uint8_t valor_r = 0;
static uint8_t valor_g = 0;
static uint8_t valor_b = 0;


//FUNCIONES INTERNAS

/*Dispara conversión de los 3 canales ya configurados y espera a que cada una termine.
raw == Array de 3 posiciones donde se guardan los valores del ADC.
Devuelve true si las 3 conversiones se completaron correctamente, false si timeout.*/

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


//FUNCIONES PÚBLICAS

void pote_init(void) {

	//Al hacer polling no hace falta arrancar ninguna conversión
    //Cada lectura se dispara desde escrutar_potenciometros().
}


uint8_t adc_a_posicion(uint16_t valor_raw) {
    return (uint8_t)((valor_raw * 32) / 4096);
}

uint8_t adc_a_brillo(uint16_t valor_raw) {
    return (uint8_t)(valor_raw >> 4);
}


/*Lee los tres potenciómetros, convierte sus valores y actualiza las variables internas del TDA.*/
void escrutar_potenciometros(void) {
    uint16_t raw[3] = {0};

    //Si timeout, no se modifican los valores actuales. Se conserva el último valor válido.

    if (!leer_3_canales(raw)) {
        return;
    }

    /* Conversión de ADC a los valores utilizados por el sistema */
    uint8_t r_nuevo = adc_a_posicion(raw[0]);
    uint8_t g_nuevo = adc_a_posicion(raw[1]);
    uint8_t b_nuevo = adc_a_brillo(raw[2]);

    /* Aplicación del filtro */
    valor_r = aplicar_filtro_ruido(r_nuevo, valor_r);
    valor_g = aplicar_filtro_ruido(g_nuevo, valor_g);
    valor_b = aplicar_filtro_ruido(b_nuevo, valor_b);
}


/*Obtiene los valores actuales de los tres potenciómetros.
 Devuelve estructura con los valores r, g y b.*/
Potenciometros_t procesar_potenciometros(void) {
    Potenciometros_t valores;

    valores.r = valor_r;
    valores.g = valor_g;
    valores.b = valor_b;

    return valores;
}

bool posicion_cambio(uint8_t x, uint8_t y) {
    static uint8_t old_x = POSICION_INICIAL;
    static uint8_t old_y = POSICION_INICIAL;

    if (x != old_x || y != old_y) {
        old_x = x;
        old_y = y;

        return true;
    }

    return false;
}
