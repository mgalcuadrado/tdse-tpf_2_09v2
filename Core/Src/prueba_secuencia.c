#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "secuencia.h"
#include <string.h>
#include "matriz.h"

bool pruebaSecuencia(void) {

    // Pruebas del modo Secuencia
    Secuencia_t* sec = crearSecuencia();
    if (sec == NULL) {
        printf("Error al crear secuencia \n");
        return false;
    }

    Matriz_t* matriz = matrizCrear();
    if (matriz == NULL) {
        printf("Error al crear matriz \n");
        secuenciaBorrar(sec);
        return false;
    }

    uint8_t fil = 5;
    uint8_t col = 8;

    //Insertar_elemento
    printf("Prueba de insertar elemento en la Secuencia -> Fil = %d / Col = %d \n", fil, col);
    insertar_elemento(sec, 255, matriz, fil, col);
    uint8_t pos_og = fil/8 + col/8 * 4;

    col = 1;
    uint8_t pos = fil/8 + col/8 * 4;

    if (sec->lista_sec[1][pos_og] != 255 || sec->lista_sec[1][pos] != 0) {
        printf("Error al insertar elemento \n");
        secuenciaBorrar(sec);
        return false;
    }
    printf("Exitosa \n");

    //Vaciar_Secuencia
    printf("Prueba de vaciar la secuencia \n");
    vaciar_secuencia(sec);
    if (sec->lista_sec[1][pos_og] != 0) {
        printf("Error al vaciar secuencia \n");
        secuenciaBorrar(sec);
        return false;
    }
    printf("Exitosa \n");

    //Secuencia_Completa
    printf("Prueba de Secuencia_Completa \n");
    for (uint8_t i=0; i < 16; i++) {
        sec->lista_sec[1][i] = sec->lista_sec[0][i];
    }
    if (secuencia_completa(sec)){
        printf("Exitosa \n");
    } else {
        printf("Error \n");
        secuenciaBorrar(sec);
        return false;
    }
    printf("%p \n", &sec);
    print_secuencia(sec);
    secuenciaBorrar(sec);
    return true;
}
