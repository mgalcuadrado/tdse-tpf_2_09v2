#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "secuencia.h"
#include <string.h>
#include "tesela.h"

#define MAX_ELEMENTOS 32

/*Estructura interna*/
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} casilla_t;

typedef struct {
        casilla_t tesela[MAX_ELEMENTOS][MAX_ELEMENTOS];
        int tamano_col;
        int tamano_fil;
        int tamaño_pincel = 2^3;
        int indiceActual_col;
        int indiceActual_fil;
} secuencia_t;

/*Funciones*/
secuencia_t crearSecuencia() {
    secuencia_t s = malloc(sizeof(struct Secuencia));
    if (s != NULL){
        s ->tamano_col = 0;
        s ->tamano_fil = 0;
        s ->indiceActual_col = 0;
        s ->indiceActual_fil = 0;
    }
    return s;
}

bool estaVacia(secuencia_t s){
    return s->tamano_fil == 0 && s->tamano_col == 0;
}

void reiniciar(secuencia_t s){
    s->indiceActual_col = 0;
    s->indiceActual_fil = 0;
}

void avanzar(secuencia_t s, char direccion) {
    switch (direccion)
    {
    case 'w':
        if (s->indiceActual_col < s->tamano_col){
            s->indiceActual_col++;
        }
        break;
    
    case 'a':
        if (s->indiceActual_fil > 0){
            s->indiceActual_fil--;
        }
        break;
    case 's':
        if (s->indiceActual_col > 0){
            s->indiceActual_col--;
        }
        break;
    case 'd':
        if (s->indiceActual_fil < s->tamano_fil){
            s->indiceActual_fil++;
        }
        break;
    }
}

casilla_t elementoActual(secuencia_t s) {
    if (s->indiceActual_col < s->tamano_col &&
        s->indiceActual_fil < s->tamano_fil) {
        return s->tesela[s->indiceActual_fil][s->indiceActual_col];
    }
    return -1;
}

void insertarElemento(secuencia_t s, int elemento_r, int elemento_g, int elemento_b, int fil, int col) {
    if (s->tamano_col < MAX_ELEMENTOS || s->tamano_fil < MAX_ELEMENTOS ) {
        s->tesela_r[fil][col] = elemento_r;
        s->tesela_g[fil][col] = elemento_g;
        s->tesela_b[fil][col] = elemento_b;
    }
}


void destruirSecuencia(secuencia_t s) {
    free(s);
}