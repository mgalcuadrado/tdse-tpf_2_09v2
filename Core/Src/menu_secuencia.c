/* 
 * menu_secuencia.c
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
*/

#include <stdio.h>
#include "matriz.h"
#include "secuencia.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "boton.h"
#include "menu_principal.h"
#include "menu_secuencia.h"

BotonEvento_t menuSecuenciaSeleccion(char seleccion[3], int indice_seleccion) {

    char mensaje1[MAX_CARACTERES_MENSAJE];
    char mensaje2[MAX_CARACTERES_MENSAJE];

    snprintf(mensaje1, sizeof(mensaje1), "(%c) Completar Secuencia", seleccion[0]);
    snprintf(mensaje2, sizeof(mensaje2), "(%c) Limpiar Secuencia", seleccion[1]);
        

    lcdSetearCursor(0, 0);
    lcdPrint(mensaje1);

    lcdSetearCursor(0, 1);
    lcdPrint(mensaje2);


    BotonEvento_t input = botonLeer();
    return input;
}

void menuSecuenciaInteraccion (BotonEvento_t input, char seleccion[3], int* indice_seleccion, Secuencia_t* secuencia, Matriz_t* matriz) {
	switch (input) {
		case BOTON_ABAJO:
		case BOTON_ARRIBA:
			seleccion[*indice_seleccion] = ' ';
			if (*indice_seleccion == 1 ) {
					*indice_seleccion = 0;
			} else {
					*indice_seleccion = 1;
			}
			seleccion[*indice_seleccion] = '*';
			break;
		case BOTON_ACEPTAR:
			menuSecuenciaOpcionElegida (*indice_seleccion, secuencia, matriz);
			break;
		case BOTON_ATRAS:
		    printf("Falla en salir del menu secuencia \n");
		    break;
		default:
			break;
		}
}

void menuSecuenciaOpcionElegida (int indice_seleccion, Secuencia_t* secuencia, Matriz_t* matriz) {
    switch (indice_seleccion) {
        case 0: //Completar Secuencia
        	menuSecuenciaCompletar(secuencia, matriz);
            break;
        case 1: // Limpiar Secuencia
            secuenciaVaciar(secuencia);
            matrizLlenar(matriz, 0, 0, 0);
            frameBufferUpdate(matriz);
            break;
    }
}

void menuSecuenciaCompletar(Secuencia_t* secuencia, Matriz_t* matriz) {
	while (1) {
		BotonEvento_t input = botonLeer();
		switch (input) {
			case BOTON_ARRIBA:
			case BOTON_ABAJO:
			case BOTON_IZQUIERDA:
			case BOTON_DERECHA:
				secuenciaAvanzar(secuencia, input);
				break;
			case BOTON_ACEPTAR: {
				uint8_t fil = (secuencia->indice_sec / DIM_SECUENCIA)*TAM_PINCEL_SECUENCIA;
				uint8_t col = (secuencia->indice_sec % DIM_SECUENCIA)*TAM_PINCEL_SECUENCIA;
				if (secuenciaElementoActual(secuencia) == 0) {
					secuenciaInsertarElemento(secuencia, 255, matriz, fil, col);
		            frameBufferUpdate(matriz); //Prendido
				} else {
					secuenciaInsertarElemento(secuencia, 0, matriz, fil, col);	//Apagado
		            frameBufferUpdate(matriz);
				}
				break;
			}
			case BOTON_ATRAS:
				return;
			default:
				break;
		}
		if (secuenciaCompleta(secuencia)) {
			lcdSetearCursor(0, 0);
			lcdPrint("Secuencia Completa :)");
		}

	}
}


void menuSecuenciaMain (void) {
    Secuencia_t* secuencia = secuenciaCrear();
    if (secuencia == NULL){
    	printf("Error al crear secuencia \n");
    	return;
    }
    Matriz_t* matriz = matrizCrear();
    if (matriz == NULL) {
    	printf("Error al crear matriz \n");
    	return;
    }
    char seleccion[3] = {'*',' '}; // 2 opciones en el menu + se agrega el resto para reusar una funcion
    int indice_seleccion = 0;
    BotonEvento_t input = menuSecuenciaSeleccion(seleccion, indice_seleccion);
    while (1) {
        if (input == BOTON_ATRAS) {
            secuenciaBorrar(secuencia);
            matrizBorrar(matriz);
            return;
        }
        menuSecuenciaInteraccion(input, seleccion, &indice_seleccion, secuencia, matriz);
        if (input == BOTON_ABAJO || input == BOTON_ARRIBA) {
        	input = menuSecuenciaSeleccion(seleccion, indice_seleccion);
        } else {
        	input = botonLeer();
        }
    }
}
