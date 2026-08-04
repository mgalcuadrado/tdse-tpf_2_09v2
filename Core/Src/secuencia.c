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

#define CANT_ELEMENTOS 16 // 32 x 32 dado un pincel de 8 x 8 = 5 x 5 casilleros

/*Funciones*/
Secuencia_t* crearSecuencia() {
    Secuencia_t* s = (Secuencia_t*)malloc(sizeof(Secuencia_t*));
    if (s == NULL){
        printf("Error al crear Secuencia");
    }

    s->indice_sec = 0;
    vaciar_secuencia(s);

    for (uint8_t i = 0; i < CANT_ELEMENTOS; i++){
        uint8_t ran = rand() % 2;
        s->lista_sec[0][i] = (ran == 0) ? 0 : 255;
    }
    return s;
}

void insertar_elemento(Secuencia_t* sec, uint8_t color, Matriz_t* matriz, uint8_t fil, uint8_t col) {
    uint8_t pos = fil/8 + col/8 * 4; //Calcula la posicion en la secuencia de la matriz
    sec->lista_sec[1][pos] = color;
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = color;

    uint8_t base_fil = (fil / 8) * 8;
    uint8_t base_col = (col / 8) * 8;
    for (uint8_t i = 0; i < 8; i++) {
        for(uint8_t j = 0; j < 8; j++) {
            matrizSetCasillero(matriz, base_fil + i, base_col + j, red, green, blue);
        }
    }
}

void print_secuencia(Secuencia_t* sec) {
    printf("%d Indice\n",sec->indice_sec);
    for (uint8_t i = 0; i<CANT_ELEMENTOS; i++) {
        printf("%d Objetivo %d\n", sec->lista_sec[0][i], i);
        printf("%d Usuario %d\n", sec->lista_sec[1][i], i);
    }
}

void vaciar_secuencia(Secuencia_t* sec) {
    for (uint8_t i = 0; i < CANT_ELEMENTOS; i++)
    {
        sec->lista_sec[1][i]= 0;
    }
    
}

bool secuencia_completa(Secuencia_t* sec) {
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
