/* 
 * menu.c
 *
 * Created on: Jul 20, 2026 
 *      Author: Bauti
*/

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include "secuencia.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"

char seleccion_pixelart (char seleccion[7], int indice_seleccion) {
    char input = ' ';

    char mensaje1[50];
    char mensaje2[50];
    char mensaje3[50];
    char mensaje4[50];

    if (indice_seleccion < 4) {
		snprintf(mensaje1, sizeof(mensaje1), "(%c) Limpiar Tablero \n", seleccion[0]);
		snprintf(mensaje2, sizeof(mensaje2), "(%c) Guardar Dibujo \n", seleccion[1]);
		snprintf(mensaje3, sizeof(mensaje3), "(%c) Cargar Dibujo \n", seleccion[2]);
		snprintf(mensaje4, sizeof(mensaje4), "(%c) Nuevo Dibujo \n", seleccion[3]);

		lcdSetearCursor(0, 0);
		lcdPrint(mensaje1);

		lcdSetearCursor(0, 1);
		lcdPrint(mensaje2);

		lcdSetearCursor(0, 2);
		lcdPrint(mensaje3);

		lcdSetearCursor(0, 3);
		lcdPrint(mensaje4);
    } else if (3 < indice_seleccion && indice_seleccion < 7){
    	snprintf(mensaje1, sizeof(mensaje1), "(%c) Cambiar Pincel \n", seleccion[4]);
    	snprintf(mensaje2, sizeof(mensaje2), "(%c) Modo Secuencia \n", seleccion[5]);

    	lcdSetearCursor(0, 0);
    	lcdPrint(mensaje1);

    	lcdSetearCursor(0, 1);
    	lcdPrint(mensaje2);
    } else {
    	printf("Error en el Display/Menu");
    }
        
    scanf("%c", &input); //Se va a cambiar por el input de algun boton
    return input;
}

char seleccion_secuencia(char seleccion[3], int indice_seleccion) {
    char input = ' ';

    char mensaje1[50];
    char mensaje2[50];

    snprintf(mensaje1, sizeof(mensaje1), "(%c) Limpiar Secuencia \n", seleccion[0]);
    snprintf(mensaje2, sizeof(mensaje2), "(%c) Modo Pixelart \n", seleccion[1]);
        

    lcdSetearCursor(0, 0);
    lcdPrint(mensaje1);

    lcdSetearCursor(0, 1);
    lcdPrint(mensaje2);


    scanf("%c", &input); //Se va a cambiar por el input de algun boton

    return input;
}

void opcion_elegida_pixelart (int indice_seleccion, Matriz_t* matriz){
    switch (indice_seleccion)
    {
        case 0: //Limpiar Tablero
            matrizBorrar(matriz);
            break;
        case 1: // Guardar Dibujo
            memEscribirMatriz(0x0000, matriz); //Placeholder 0x0000, en la implementacion va a variar 
            frameBufferUpdate(matriz);
            break;
        case 2: // Cargar Dibujo
            memLeerMatriz(0x0000, matriz); //Placeholder 0x0000, en la implementacion va a variar
            frameBufferUpdate(matriz);
            break;
        case 3: //Nuevo Dibujo
            matriz = matrizCrear();
            frameBufferUpdate(matriz);
            break;
        case 4: //Cambiar Pincel
            //tipo_pincel(wasd)
            break;
        case 5: //Modo Secuencia
            menu_secuencia();
            break;
    }
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

void interaccion_menu_pixelart (char input, char seleccion[7], int indice_seleccion, Matriz_t* matriz) {
    switch (input) {
            case 's':
                seleccion[indice_seleccion] = ' ';
                if (indice_seleccion >= 5 ) {
                    indice_seleccion = 0;
                } else {
                    indice_seleccion++;
                }
                seleccion[indice_seleccion] = '*';
                break;
            case 'w':
                seleccion[indice_seleccion] = ' ';
                if (indice_seleccion <= 0) {
                    indice_seleccion = 5;
                } else {
                    indice_seleccion--;
                }
                seleccion[indice_seleccion] = '*';
                break;
            case ' ': //Boton Rojo de aceptar
                opcion_elegida_pixerlart(indice_seleccion, matriz);
                break;
            case 'b': //Boton Negro para atras
                //volver a dibujar - PixelArt
                break;
    }
}


// void tipo_pincel()

void menu_pixelart() {
    Matriz_t* matriz = matrizCrear(); //Se puede cambiar de lugar dependiendo de la implementacio / Esta para futuras pruebas
    frameBufferUpdate(matriz);
    char seleccion[7] = {'*',' ',' ',' ',' ',' '}; // 6 opciones en el menu + 1 por el /n
    int indice_seleccion = 0;

    while (1) {
        char input = seleccion_pixelart (seleccion, indice_seleccion);
        interaccion_menu_pixelart(input, seleccion, indice_seleccion, matriz);
        
    }
}


void menu_secuencia() {
    Secuencia_t* secuencia = crearSecuencia();
    char seleccion[3] = {'*',' '}; // 2 opciones en el menu + se agrega el resto para reusar una funcion
    int indice_seleccion = 0;

    while (1) {
        char input = seleccion_secuencia(seleccion, indice_seleccion);
        interaccion_menu_secuencia(input, seleccion, indice_seleccion, secuencia);
    }
}
