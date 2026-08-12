#include POTENCIOMETRO_H
#include <stdlib.h>
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim4;

extern uint16_t adc_buffer[3];


/*
 * Inicializa el ADC + DMA y el TIM4.
 */
void pote_init(void)
{
    HAL_ADC_Start_DMA(
        &hadc1,
        (uint32_t *)adc_buffer,
        3
    );

    HAL_TIM_Base_Start_IT(&htim4);
}


/*
 * Actualiza los valores de los potenciómetros.
 */
void pote_update(void)
{
    uint8_t x;
    uint8_t y;
    uint8_t brillo;

    static uint8_t old_x = 0;
    static uint8_t old_y = 0;

    leer_potenciometros(&x, &y, &brillo);

    HUB75_SetBrightness(brillo);

    if (posicion_cambio(x, y))
    {
        matrix_moveCursor(
            old_x,
            old_y,
            x,
            y,
            RED
        );

        old_x = x;
        old_y = y;
    }
}

/* Conversión ADC 12 bits a posición matriz 32x32 */
uint8_t adc_a_posicion(uint16_t valor_raw)
{
    return (uint8_t)((valor_raw * 32) / 4096);
}


/* Conversión ADC 12 bits a brillo 0-255 */
uint8_t adc_a_brillo(uint16_t valor_raw)
{
    return (uint8_t)(valor_raw >> 4);
}


/* Filtro con histéresis */
uint8_t aplicar_filtro_ruido(uint8_t nuevo, uint8_t anterior)
{
    if (abs((int)nuevo - (int)anterior) <= 2)
    {
        return anterior;
    }

    return nuevo;
}


void leer_potenciometros(uint8_t *r, uint8_t *g, uint8_t *b)
{
    uint8_t r_raw;
    uint8_t g_raw;
    uint8_t b_raw;

    static uint8_t r_anterior = 0;
    static uint8_t g_anterior = 0;
    static uint8_t b_anterior = 0;

    /* Leer DMA */
    r_raw = adc_a_posicion(adc_buffer[0]);
    g_raw = adc_a_posicion(adc_buffer[1]);
    b_raw = adc_a_brillo(adc_buffer[2]);

    /* Aplicar filtro */
    r_anterior = aplicar_filtro_ruido(r_raw, r_anterior);
    g_anterior = aplicar_filtro_ruido(g_raw, g_anterior);
    b_anterior = aplicar_filtro_ruido(b_raw, b_anterior);

    /* Devolver los valores mediante punteros */
    *r = r_anterior;
    *g = g_anterior;
    *b = b_anterior;
}


bool posicion_cambio(uint8_t x, uint8_t y)
{
    static uint8_t old_x = 255;
    static uint8_t old_y = 255;

    if (x != old_x || y != old_y)
    {
        old_x = x;
        old_y = y;

        return true;
    }

    return false;
}

/*main.c
while (1)
{
    pote_update();
}

y:

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM4)
    {
        HUB75_Refresh();
    }
}
*/