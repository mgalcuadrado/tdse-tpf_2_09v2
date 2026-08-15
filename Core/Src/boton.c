/*
 * boton.c
 *
 * Created on: Ago 4, 2026
 *      Author: Bauti
*/

#include "main.h"
#include "boton.h"

static BotonEvento_t ultimoEvento = BOTON_NINGUNO;

BotonEvento_t botonLeer() {
    static uint32_t ultimoTiempo = 0;

    // Variables estáticas para recordar el estado anterior de cada pin (1 = Suelto, 0 = Presionado)
    static GPIO_PinState estadoAnt_Arriba = GPIO_PIN_SET;
    static GPIO_PinState estadoAnt_Abajo = GPIO_PIN_SET;
    static GPIO_PinState estadoAnt_Izquierda = GPIO_PIN_SET;
    static GPIO_PinState estadoAnt_Derecha = GPIO_PIN_SET;
    static GPIO_PinState estadoAnt_Aceptar = GPIO_PIN_SET;
    static GPIO_PinState estadoAnt_Atras = GPIO_PIN_SET;



    //Leer el estado actual de los pines
    GPIO_PinState actual_Arriba = HAL_GPIO_ReadPin(BU1_GPIO_Port, BU1_Pin);
    GPIO_PinState actual_Abajo = HAL_GPIO_ReadPin(BU2_GPIO_Port, BU2_Pin);
    GPIO_PinState actual_Izquierda = HAL_GPIO_ReadPin(BU3_GPIO_Port, BU3_Pin);
    GPIO_PinState actual_Derecha = HAL_GPIO_ReadPin(BU4_GPIO_Port, BU4_Pin);
    GPIO_PinState actual_Aceptar = HAL_GPIO_ReadPin(BU5_GPIO_Port, BU5_Pin);
    GPIO_PinState actual_Atras = HAL_GPIO_ReadPin(BU6_GPIO_Port, BU6_Pin);

    BotonEvento_t evento = BOTON_NINGUNO;

    //Detección de Flanco de bajada
    if ((HAL_GetTick() - ultimoTiempo) >= DEBOUNCE_MS) {

		if (estadoAnt_Arriba == GPIO_PIN_SET && actual_Arriba == GPIO_PIN_RESET) {
			evento = BOTON_ARRIBA;
			ultimoTiempo = HAL_GetTick();
		}
		if (estadoAnt_Abajo == GPIO_PIN_SET && actual_Abajo == GPIO_PIN_RESET) {
			evento = BOTON_ABAJO;
			ultimoTiempo = HAL_GetTick();
		}
		if (estadoAnt_Izquierda == GPIO_PIN_SET && actual_Izquierda == GPIO_PIN_RESET) {
			evento = BOTON_IZQUIERDA;
			ultimoTiempo = HAL_GetTick();
		}
		if (estadoAnt_Derecha == GPIO_PIN_SET && actual_Derecha == GPIO_PIN_RESET) {
			evento = BOTON_DERECHA;
			ultimoTiempo = HAL_GetTick();
		}
		//Aceptar o Atras
		if (estadoAnt_Aceptar == GPIO_PIN_SET && actual_Aceptar == GPIO_PIN_RESET) {
			evento = BOTON_ACEPTAR;
			ultimoTiempo = HAL_GetTick();
		}
		if (estadoAnt_Atras == GPIO_PIN_SET && actual_Atras == GPIO_PIN_RESET) {
			evento = BOTON_ATRAS;
			ultimoTiempo = HAL_GetTick();
		}
    }

    //Reseteo el tiempo si cambio algun pin
    if (actual_Arriba != estadoAnt_Arriba || actual_Abajo != estadoAnt_Abajo ||
            actual_Izquierda != estadoAnt_Izquierda || actual_Derecha != estadoAnt_Derecha ||
            actual_Aceptar != estadoAnt_Aceptar || actual_Atras != estadoAnt_Atras) {

            ultimoTiempo = HAL_GetTick();
        }

    estadoAnt_Arriba = actual_Arriba;
    estadoAnt_Abajo = actual_Abajo;
    estadoAnt_Izquierda = actual_Izquierda;
    estadoAnt_Derecha = actual_Derecha;
    estadoAnt_Aceptar = actual_Aceptar;
    estadoAnt_Atras = actual_Atras;

    return evento;
}

BotonEvento_t botonUltimoEvento (void) {
	return ultimoEvento;
}

