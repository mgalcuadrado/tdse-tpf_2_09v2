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

#define CANT_ELEMENTOS 25 // 32 x 32 dado un pincel de 8 x 8 = 5 x 5 casilleros

/*Funciones*/
Secuencia_t* crearSecuencia() {
    secuencia_t s = malloc(sizeof(struct Secuencia));
    if (s != NULL){
        s ->indice_sec = 0;
        for (uint8_t i = 0; i<=25; i++){
            uint8_t ran = rand() % 3;
            switch (ran) {
                case 0:
                s->lista_sec[0][i].r = 255;
                s->lista_sec[0][i].g = 0;
                s->lista_sec[0][i].b = 0;
                break;
                case 1:
                s->lista_sec[0][i].r = 0;
                s->lista_sec[0][i].g = 255;
                s->lista_sec[0][i].b = 0;
                break;
                case 2:
                s->lista_sec[0][i].r = 0;
                s->lista_sec[0][i].g = 0;
                s->lista_sec[0][i].b = 255;
                break;
            }
            vaciar_secuencia(s);
        }
    }
    return s;
}

void insertar_elemento(Secuencia_t* sec, uint8_t red, uint8_t green, uint8_t blue, Matriz_t* matriz, uint8_t fil, uint8_t col) {
    uint8_t pos = fil/8 + col/8 * 5; //Calcula la posicion en la secuencia de la matriz
    sec->lista_sec[1][pos].r = red;
    sec->lista_sec[1][pos].g = green;
    sec->lista_sec[1][pos].b = blue;
    for (int i = 0; ((i + fil)/8) == (fil/8); i++) {
        matrizSetCasillero(matriz, fil+i, col, red, green, blue);
    }
    for (int i = 1; ((i + col)/8) == (col/8); i++) {
        matrizSetCasillero(matriz, fil, col+i, red, green, blue);
    }
    for (int i = -1; ((i + fil)/8) == (fil/8); i--) {
        matrizSetCasillero(matriz, fil+i, col, red, green, blue);
    }
    for (int i = -1; ((i + col)/8) == (col/8); i--) {
        matrizSetCasillero(matriz, fil, col+i, red, green, blue);
    }
}



void vaciar_secuencia(Secuencia_t* sec) {
    for (uint8_t i = 0; i<= 25; i++)
    {
        sec->lista_sec[1][i].r = 0;
        sec->lista_sec[1][i].g = 0;
        sec->lista_sec[1][i].b = 0;
    }
    
}
bool secuencia_completa(Secuencia_t* sec) {
    for (uint8_t i = 0; i <= 25; i++){
        if (sec->lista_sec[0][i].r != sec->lista_sec[1][i].r){
            return false;
        }
        if (sec->lista_sec[0][i].g != sec->lista_sec[1][i].g){
            return false;
        }
        if (sec->lista_sec[0][i].b != sec->lista_sec[1][i].b){
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