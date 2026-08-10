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

/*Funciones*/
Secuencia_t* secuenciaCrear() {
    Secuencia_t* s = (Secuencia_t*)malloc(sizeof(Secuencia_t));
    if (s == NULL){
        printf("Error al crear Secuencia \n");
        return NULL;
    }

    s->indice_sec = 0;
    secuenciaVaciar(s);

    for (uint8_t i = 0; i < CANT_ELEMENTOS; i++){
        uint8_t ran = rand() % 2; //Se usar srand(GetTickCount()) en el main que funcione adecuadamente
        s->lista_sec[0][i] = (ran == 0) ? 0 : 255;
    }
    return s;
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

void secuenciaAvanzar(Secuencia_t* sec, BotonEvento_t input) {
	if (sec->indice_sec >= (DIM_SECUENCIA * DIM_SECUENCIA)) {
		printf("Error al acceder Secuencia \n");
		return;
	}
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
		break;
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
