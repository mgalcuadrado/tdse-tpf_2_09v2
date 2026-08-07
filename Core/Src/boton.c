/*
 * boton.c
 *
 * Created on: Ago 4, 2026
 *      Author: Bauti
*/

#include "main.h"
#include "boton.h"

BotonEvento_t botonLeer() {
    static uint32_t ultimoTiempo = 0;

    // Variables estáticas para recordar el estado anterior de cada pin (1 = Suelto, 0 = Presionado)
    static GPIO_PinState estadoAnt_Arriba = GPIO_PIN_SET;
    static GPIO_PinState estadoAnt_Abajo  = GPIO_PIN_SET;
    static GPIO_PinState estadoAnt_Ok     = GPIO_PIN_SET;
    static GPIO_PinState estadoAnt_Back   = GPIO_PIN_SET;

    // Si no pasaron 50ms desde el último evento, ignorar para filtrar rebotes mecánicos
    if ((HAL_GetTick() - ultimoTiempo) < DEBOUNCE_MS) {
        return BOTON_NINGUNO;
    }

    // 1. Leer el estado actual de los pines
    GPIO_PinState actual_Arriba = HAL_GPIO_ReadPin(BU1_GPIO_Port, BU1_Pin);
    GPIO_PinState actual_Abajo  = HAL_GPIO_ReadPin(BU2_GPIO_Port, BU2_Pin);
    GPIO_PinState actual_Ok     = HAL_GPIO_ReadPin(BU3_GPIO_Port, BU3_Pin);
    GPIO_PinState actual_Back   = HAL_GPIO_ReadPin(BU4_GPIO_Port, BU4_Pin);

    BotonEvento_t evento = BOTON_NINGUNO;

    // 2. Detección de Flanco: Estaba suelto (SET) Y AHORA está presionado (RESET)
    if (estadoAnt_Arriba == GPIO_PIN_SET && actual_Arriba == GPIO_PIN_RESET) {
        evento = BOTON_ARRIBA;
        ultimoTiempo = HAL_GetTick();
    }
    else if (estadoAnt_Abajo == GPIO_PIN_SET && actual_Abajo == GPIO_PIN_RESET) {
        evento = BOTON_ABAJO;
        ultimoTiempo = HAL_GetTick();
    }
    else if (estadoAnt_Ok == GPIO_PIN_SET && actual_Ok == GPIO_PIN_RESET) {
        evento = BOTON_OK;
        ultimoTiempo = HAL_GetTick();
    }
    else if (estadoAnt_Back == GPIO_PIN_SET && actual_Back == GPIO_PIN_RESET) {
        evento = BOTON_BACK;
        ultimoTiempo = HAL_GetTick();
    }

    // 3. Actualizar los estados anteriores para la siguiente lectura
    estadoAnt_Arriba = actual_Arriba;
    estadoAnt_Abajo  = actual_Abajo;
    estadoAnt_Ok     = actual_Ok;
    estadoAnt_Back   = actual_Back;

    return evento; // Devuelve el evento detectado en este instante
}
