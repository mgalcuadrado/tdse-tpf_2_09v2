#include "pote.h"
#include <stdlib.h>
extern uint16_t adc_buffer[3];

/*
 * Conversión ADC 12 bits
 * a posición matriz 32x32
 */

uint8_t adc_a_posicion(uint16_t valor_raw){
    return (uint8_t)((valor_raw * 32) / 4096);
}

/*
 * Conversión ADC 12 bits
 * a brillo 0-255
 */

uint8_t adc_a_brillo(uint16_t valor_raw){
    return (uint8_t)(valor_raw >> 4);
}

/*
 * Filtro con histéresis
 */

uint8_t aplicar_filtro_ruido(uint8_t nuevo,
                             uint8_t anterior){

    if(abs((int)nuevo - (int)anterior) <= 2){
        return anterior;
    }
    return nuevo;
}

void leer_potenciometros(Potenciometros_t *pots){
    uint8_t x_raw;
    uint8_t y_raw;
    uint8_t brillo_raw;
    /*
     * Leer DMA
     */

    x_raw =
    adc_a_posicion(adc_buffer[0]);
    y_raw =
    adc_a_posicion(adc_buffer[1]);
    brillo_raw =
    adc_a_brillo(adc_buffer[2]);
    /*
     * Aplicar filtro
     */

    pots->x = aplicar_filtro_ruido(x_raw, pots->x);
    pots->y =
    aplicar_filtro_ruido(y_raw, pots->y);
    pots->brillo = aplicar_filtro_ruido(brillo_raw, pots->brillo);
}

bool posicion_cambio(uint8_t x, uint8_t y){

    static uint8_t old_x = 255;
    static uint8_t old_y = 255;

    if(x != old_x || y != old_y){
        old_x = x;
        old_y = y;
        return true;
    }
    return false;
}