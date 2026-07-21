/* 
 * menu.c
 *
 * Created on: Jul 20, 2026 
 *      Author: Bauti
*/

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char menu_pixelart (char seleccionado[7], int indice_seleccion) {
    char input = ' ';
    printf("(%c) Limpiar Tablero \n", seleccionado[0]);
    printf("(%c) Guardar Dibujo \n", seleccionado[1]);
    printf("(%c) Cargar Dibujo \n", seleccionado[2]);
    printf("(%c) Nuevo Dibujo \n", seleccionado[3]);
    printf("(%c) Cambiar Pincel \n", seleccionado[4]);
    printf("(%c) Modo Secuencia \n", seleccionado[5]);
        
    printf("%d \n", indice_seleccion);
    scanf("%c", &input);
    return input;
}

void interaccion_menu (char input, char seleccion[7], int indice_seleccion, Matriz_t* matriz) {
    switch (input) {
            case 's':
                seleccionado[indice_seleccion] = ' ';
                if (indice_seleccion >= 5) {
                    indice_seleccion = 0;
                } else {
                    indice_seleccion++;
                }
                seleccionado[indice_seleccion] = '*';
                break;
            case 'w':
                seleccionado[indice_seleccion] = ' ';
                if (indice_seleccion <= 0) {
                    indice_seleccion = 5;
                } else {
                    indice_seleccion--;
                }
                seleccionado[indice_seleccion] = '*';
                break;
            case ' ':
                opcion_elegida(indice_seleccion, matriz);

    }        
}

// void tipo_pincel()

void opcion_elegida (int indice_seleccion, Matriz_t* matriz){
    switch (indice_seleccion)
    {
    case 0:
        matrizBorrar(matriz);
        break;
    case 1:
        // Guardar Dibujo
        memEscribirMatriz(0x0000, matriz); //Placeholder 0x0000, en la implementacion va a variar 
        break;
    case 2:
        // Cargar Dibujo
        memLeerMatriz(0x0000, matriz); //Placeholder 0x0000, en la implementacion va a variar
        break;
    case 3:
        //Nuevo Dibujo
        &matriz = matrizCrear(void);
        break;
    case 4:
        //Cambiar Pincel
        //tipo_pincel(wasd)
        break;
    case 5:
        //Modo Secuencia 
        break;
    }
    return
}

int interfaz_menu () {
    Matriz_t* matriz = matrizcrear(); //Se puede cambiar de lugar dependiendo de la implementacio / Esta para futuras pruebas
    char seleccionado[7] = {'*',' ',' ',' ',' ',' '}; // 5 opciones en el menu + 1 por el /n
    int indice_seleccion = 0;

    while (1) {
        char input = menu_pixelart (seleccionado[7], indice_seleccion);
        interaccion_menu(input, seleccionado[7], indice_seleccion, matriz);
        

    }
    return 0;
}