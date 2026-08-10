/*
 * menu_secuencia.c
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
 *
*/

#include <stdio.h>
#include "matriz.h"
#include "secuencia.h"
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "boton.h"
#include "menu_secuencia.h"
#include "estado.h"

static Secuencia_t* secuencia_actual = NULL;
static Matriz_t* matriz_actual = NULL;
static char seleccion[3] = {'*', ' '};
static int indice_seleccion = 0;

void menuSecuenciaEntrar(void) {
    if (secuencia_actual == NULL) {
        secuencia_actual = secuenciaCrear();
        if (secuencia_actual == NULL) {
            printf("Error al crear secuencia \n");
            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            return;
        }
    }
    if (matriz_actual == NULL) {
        matriz_actual = matrizCrear();
        if (matriz_actual == NULL) {
            printf("Error al crear matriz \n");
            secuenciaBorrar(secuencia_actual);
            secuencia_actual = NULL;
            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            return;
        }
    }

    indice_seleccion = 0;
    seleccion[0] = '*';
    seleccion[1] = ' ';
    menuSecuenciaMostrar(seleccion, indice_seleccion);
}

void menuSecuenciaMostrar(char seleccion[3], int indice_seleccion) {
    char mensaje1[MAX_CARACTERES_MENSAJE];
    char mensaje2[MAX_CARACTERES_MENSAJE];

    snprintf(mensaje1, sizeof(mensaje1), "(%c) Completar Secuencia", seleccion[0]);
    snprintf(mensaje2, sizeof(mensaje2), "(%c) Limpiar Secuencia", seleccion[1]);

    lcdSetearCursor(0, 0);
    lcdPrint(mensaje1);

    lcdSetearCursor(0, 1);
    lcdPrint(mensaje2);
}

void menuSecuenciaOpcionElegida(int indice_seleccion) {
    switch (indice_seleccion) {
        case 0: // Completar Secuencia -> transición de estado
            sistemaCambiarEstado(ESTADO_COMPLETANDO_SECUENCIA);
            break;
        case 1: // Limpiar Secuencia
            secuenciaVaciar(secuencia_actual);
            matrizLlenar(matriz_actual, 0, 0, 0);
            frameBufferUpdate(matriz_actual);
            break;
        default:
            break;
    }
}

void menuSecuenciaTick(BotonEvento_t input) {
    switch (input) {
        case BOTON_ABAJO:
        case BOTON_ARRIBA:
            seleccion[indice_seleccion] = ' ';
            indice_seleccion = (indice_seleccion == 1) ? 0 : 1;
            seleccion[indice_seleccion] = '*';
            lcdBorrar();
            menuSecuenciaMostrar(seleccion, indice_seleccion);
            break;
        case BOTON_ACEPTAR:
            menuSecuenciaOpcionElegida(indice_seleccion);
            break;
        case BOTON_ATRAS:
            secuenciaBorrar(secuencia_actual);
            matrizBorrar(matriz_actual);
            secuencia_actual = NULL;
            matriz_actual = NULL;
            sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
            break;
        default:
            break;
    }
}

void menuSecuenciaCompletarTick(BotonEvento_t input) {
	if (secuenciaCompleta(secuencia_actual)) {
    	lcdBorrar();
        lcdSetearCursor(0, 0);
        lcdPrint("Secuencia Completa :)");
        sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
        /*
        static uint32_t ultimoTiempo = 0;
        if ((HAL_GetTick() - ultimoTiempo) < DEBOUNCE_MS * 40) {
			sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
		} else {
			ultimoTiempo = HAL_GetTick();
			return;
		}*/
    }

	switch (input) {
        case BOTON_ARRIBA:
        case BOTON_ABAJO:
        case BOTON_IZQUIERDA:
        case BOTON_DERECHA:
            secuenciaAvanzar(secuencia_actual, input);
            break;
        case BOTON_ACEPTAR: {
            uint8_t fil = (secuencia_actual->indice_sec / DIM_SECUENCIA) * TAM_PINCEL_SECUENCIA;
            uint8_t col = (secuencia_actual->indice_sec % DIM_SECUENCIA) * TAM_PINCEL_SECUENCIA;
            if (secuenciaElementoActual(secuencia_actual) == 0) {
                secuenciaInsertarElemento(secuencia_actual, 255, matriz_actual, fil, col); // Prendido
            } else {
                secuenciaInsertarElemento(secuencia_actual, 0, matriz_actual, fil, col);   // Apagado
            }
            frameBufferUpdate(matriz_actual);
            break;
        }
        case BOTON_ATRAS:
            sistemaCambiarEstado(ESTADO_MENU_SECUENCIA);
            lcdBorrar();
            menuSecuenciaMostrar(seleccion, indice_seleccion); // reimprime el menú al volver
            return;
        default:
            break;
    }


}
