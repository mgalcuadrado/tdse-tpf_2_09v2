/* 
 * secuencia.c
 *
 * Created on: Jul 26, 2026 
 *      Author: Bauti
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "secuencia.h"
#include <string.h>
#include "matriz.h"
#include "boton.h"
#include "stm32f1xx_hal.h"

/*Funciones*/
Secuencia_t* secuenciaCrear() {
    Secuencia_t* s = (Secuencia_t*)malloc(sizeof(Secuencia_t));
    if (s == NULL){
        printf("Error al crear Secuencia \n");
        return NULL;
    }

    s->indice_sec = 0;
    secuenciaVaciar(s);
    srand(HAL_GetTick());
    for (uint8_t i = 0; i < CANT_ELEMENTOS; i++){
        uint8_t ran = rand() % 2; //Se usar srand(GetTickCount()) en el main que funcione adecuadamente
        s->lista_sec[0][i] = (ran == 0) ? 0 : 255;
    }
    return s;
}

//Es como la de pintarDibujo, pero para secuencia. Se usa para poner el cursor principalmente,
//y también para mostrar la secuencia objetivo y marcar aciertos/errores (ver secuencia.h)
void secuenciaPintarSeccion(Matriz_t* matriz, uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t fil = (pos / DIM_SECUENCIA) * TAM_PINCEL_SECUENCIA;
    uint8_t col = (pos % DIM_SECUENCIA) * TAM_PINCEL_SECUENCIA;
    for (uint8_t i = 0; i < TAM_PINCEL_SECUENCIA; i++) {
        for (uint8_t j = 0; j < TAM_PINCEL_SECUENCIA; j++) {
            matrizSetCasillero(matriz, fil + i, col + j, r, g, b);
        }
    }
}
//2 auxiliares privadas que tienen que ir arriba
//Se usa para devolver una casilla a su color anterior cuando se le saca el cursor de encima
static void secuenciaRestaurarCasilla(Secuencia_t* sec, Matriz_t* matriz, uint8_t pos) {
    uint8_t colorCasilla = sec->lista_sec[1][pos];
    secuenciaPintarSeccion(matriz, pos, 0, 0, colorCasilla);
}


void secuenciaInsertarElemento(Secuencia_t* sec, uint8_t color, Matriz_t* matriz, uint8_t fil, uint8_t col) {
	if (fil >= MATRIZ_FILAS || col >= MATRIZ_COLUMNAS) {
		printf("Error al acceder matriz \n");
		return;
	}

	uint8_t pos = col/TAM_PINCEL_SECUENCIA + fil/TAM_PINCEL_SECUENCIA * DIM_SECUENCIA; //Calcula la posicion en la secuencia de la matriz
    sec->lista_sec[1][pos] = color;
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = color;

    uint8_t base_fil = (fil / TAM_PINCEL_SECUENCIA) * TAM_PINCEL_SECUENCIA;
    uint8_t base_col = (col / TAM_PINCEL_SECUENCIA) * TAM_PINCEL_SECUENCIA;
    for (uint8_t i = 0; i < TAM_PINCEL_SECUENCIA; i++) {
        for(uint8_t j = 0; j < TAM_PINCEL_SECUENCIA; j++) {

            matrizSetCasillero(matriz, base_fil + i, base_col + j, red, green, blue);
        }
    }

}

void secuenciaAvanzar(Secuencia_t* sec, BotonEvento_t input, Matriz_t* matriz) {
	if (sec == NULL || sec->indice_sec >= (DIM_SECUENCIA * DIM_SECUENCIA)) {
		printf("Error al acceder Secuencia \n"); //Por swv no deberiamos tener problema con los printf
		return;
	}

	// Antes que nada devuelvo la casilla a su color original
	if (matriz != NULL) {
		secuenciaRestaurarCasilla(sec, matriz, sec->indice_sec);
	}

	// Muy similar a dibujoAvanzar, se mueve en la matriz y pinta el cursor
	switch (input) {
	case BOTON_IZQUIERDA:
		if (sec->indice_sec % DIM_SECUENCIA > 0){
			sec->indice_sec -= 1;
		} else {
			sec->indice_sec += DIM_SECUENCIA - 1;
		}
		break;

	case BOTON_ABAJO:
		if (sec->indice_sec / DIM_SECUENCIA < DIM_SECUENCIA - 1){
			sec->indice_sec += DIM_SECUENCIA;
		} else {
			sec->indice_sec -= (DIM_SECUENCIA * (DIM_SECUENCIA - 1));
		}
		break;

	case BOTON_DERECHA:
		if (sec->indice_sec % DIM_SECUENCIA < DIM_SECUENCIA - 1){
			sec->indice_sec += 1;
		} else {
			sec->indice_sec -= DIM_SECUENCIA - 1;
		}
		break;

	case BOTON_ARRIBA:
		if (sec->indice_sec / DIM_SECUENCIA > 0){
			sec->indice_sec -= DIM_SECUENCIA;
		} else {
			sec->indice_sec += (DIM_SECUENCIA * (DIM_SECUENCIA - 1));
		}
		break;

	default:
		return;
	}

	// Pinta el cursor
	if (matriz != NULL) {
		secuenciaPintarSeccion(matriz, sec->indice_sec, 250, 0, 0);
	}
}

uint8_t secuenciaElementoActual(Secuencia_t* sec) {
	return sec->lista_sec[1][sec->indice_sec];
}


void secuenciaPrint(Secuencia_t* sec) {
    printf("%d Indice \n", sec->indice_sec);
    for (uint8_t i = 0; i<CANT_ELEMENTOS; i++) {
        printf("%d Objetivo %d \n", sec->lista_sec[0][i], i);
        printf("%d Usuario %d \n", sec->lista_sec[1][i], i);
    }
}

void secuenciaVaciar(Secuencia_t* sec) {
    for (uint8_t i = 0; i < CANT_ELEMENTOS; i++)
    {
        sec->lista_sec[1][i]= 0;
    }
    
}

bool secuenciaCompleta(Secuencia_t* sec) {
    for (uint8_t i = 0; i < CANT_ELEMENTOS; i++){
        if (sec->lista_sec[0][i] != sec->lista_sec[1][i]){
            return false;
        }

    }
    return true;
}

void secuenciaBorrar(Secuencia_t* sec) {
    if (sec != NULL) {
        free(sec);
    }
}

