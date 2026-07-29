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

char seleccion_pixelart (char seleccionado[7], int indice_seleccion) {
    char input = ' ';
    printf("(%c) Limpiar Tablero \n", seleccionado[0]);
    printf("(%c) Guardar Dibujo \n", seleccionado[1]);
    printf("(%c) Cargar Dibujo \n", seleccionado[2]);
    printf("(%c) Nuevo Dibujo \n", seleccionado[3]);
    printf("(%c) Cambiar Pincel \n", seleccionado[4]);
    printf("(%c) Modo Secuencia \n", seleccionado[5]);
        
    scanf("%c", &input); //Se va a cambiar por el input de algun boton
    return input;
}

void interaccion_menu_pixelart (char input, char seleccion[7], int indice_seleccion, Matriz_t* matriz) {
    switch (input) {
            case 's':
                seleccionado[indice_seleccion] = ' ';
                if (indice_seleccion >= 5 ) {    
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
            case ' ': //Boton Rojo de aceptar
                opcion_elegida_pixerlart(indice_seleccion, matriz);
                break;
            case 'b': //Boton Negro para atras
                //volver a dibujar - PixelArt
                break;
    }        
}

char seleccion_secuencia(char seleccionado[3], int indice_seleccion) {
    char input = ' ';
    printf("(%c) Limpiar Secuencia \n", seleccionado[0]);
    printf("(%c) Modo Pixelart \n", seleccionado[1]);
        
    printf("%d \n", indice_seleccion);
    scanf("%c", &input); //Se va a cambiar por el input de algun boton

    return input
}

// void tipo_pincel()

void opcion_elegida_pixelart (int indice_seleccion, Matriz_t* matriz){
    switch (indice_seleccion)
    {
        case 0: //Limpiar Tablero
            matrizBorrar(matriz);
            break;
        case 1: // Guardar Dibujo
            memEscribirMatriz(0x0000, matriz); //Placeholder 0x0000, en la implementacion va a variar 
            break;
        case 2: // Cargar Dibujo
            memLeerMatriz(0x0000, matriz); //Placeholder 0x0000, en la implementacion va a variar
            break;
        case 3: //Nuevo Dibujo
            matriz = matrizCrear();
            break;
        case 4: //Cambiar Pincel
            //tipo_pincel(wasd)
            break;
        case 5: //Modo Secuencia
            menu_secuencia();
            break;
    }
    return
}

void opcion_elegida_secuencia (int indice_seleccion, Secuencia_t* sec) {
    switch (indice_seleccion) {
        case 0: //Limpiar Secuencia
            secuenciaBorrar(sec);
            sec = crearSecuencia();
            break;
        case 1: //Menu Pixerlart
            secuenciaBorrar(sec);
            menu_pixelart();
            break;
    }
}


void menu_pixelart () {
    Matriz_t* matriz = matrizcrear(); //Se puede cambiar de lugar dependiendo de la implementacio / Esta para futuras pruebas
    char seleccionado[7] = {'*',' ',' ',' ',' ',' '}; // 6 opciones en el menu + 1 por el /n
    int indice_seleccion = 0;

    while (1) {
        char input = seleccion_pixelart (seleccionado[7], indice_seleccion);
        interaccion_menu_pixelart(input, seleccionado[7], indice_seleccion, matriz);
        
    }
    return 0;
}


void menu_secuencia () {
    Secuencia_t* secuencia = crearSecuencia();
    char seleccionado[3] = {'*',' '}; // 2 opciones en el menu + se agrega el resto para reusar una funcion
    int indice_seleccion = 0;

    while (1) {
        char input = seleccion_secuencia(seleccionado, indice_seleccion);
        interaccion_menu_secuencia(input, seleccionado, indice_seleccion, secuencia);
    }
    return 0
}
