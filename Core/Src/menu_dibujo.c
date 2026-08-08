/* 
 * menu_dibujo.c
 *
 * Created on: Aug 7, 2026
 *      Author: Bauti
*/

#include <stdio.h>
#include "mem.h"
#include "matriz.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "frame_buffer.h"
#include "lcd.h"
#include "dibujo.h"
#include "boton.h"
#include "menu_dibujo.h"

BotonEvento_t seleccionDibujo (char seleccion[6], int indice_seleccion) {

    char mensaje1[50];
    char mensaje2[50];
    char mensaje3[50];

    if (indice_seleccion < 3) {
		snprintf(mensaje1, sizeof(mensaje1), "(%c) Dibujar", seleccion[0]);
		snprintf(mensaje2, sizeof(mensaje2), "(%c) Nuevo Dibujo", seleccion[1]);
		snprintf(mensaje3, sizeof(mensaje3), "(%c) Guardar Dibujo", seleccion[2]);


		lcdSetearCursor(0, 0);
		lcdPrint(mensaje1);

		lcdSetearCursor(0, 1);
		lcdPrint(mensaje2);

		lcdSetearCursor(0, 2);
		lcdPrint(mensaje3);

    } else if (2 < indice_seleccion && indice_seleccion < 5){
    	snprintf(mensaje1, sizeof(mensaje1), "(%c) Cargar Dibujo", seleccion[3]);
    	snprintf(mensaje2, sizeof(mensaje2), "(%c) Cambiar Pincel", seleccion[4]);

    	lcdSetearCursor(0, 0);
    	lcdPrint(mensaje1);

    	lcdSetearCursor(0, 1);
    	lcdPrint(mensaje2);
    } else {
    	printf("Error en el Display/Menu \n");
    }
        
    BotonEvento_t input = botonLeer();
    return input;
}

void opcionElegidaDibujo (int indice_seleccion, Dibujo_t* dibujo){
    switch (indice_seleccion) {
    	case 0: // Dibujar
    		dibujar(dibujo);
    		break;
        case 1: //Nuevo Dibujo
            dibujoReiniciar(dibujo);
            break;
        case 2: // Guardar Dibujo
            memEscribirMatriz(0x0000, dibujo->matriz); //Placeholder 0x0000, en la implementacion va a variar
            frameBufferUpdate(dibujo->matriz);
            break;
        case 3: // Cargar Dibujo
            memLeerMatriz(0x0000, dibujo->matriz); //Placeholder 0x0000, en la implementacion va a variar
            frameBufferUpdate(dibujo->matriz);
            break;
        case 4: //Cambiar Pincel
            dibujoCambiarPincel(dibujo);
            break;
    }
}


void interaccionMenuDibujo (BotonEvento_t input, char seleccion[6], int* indice_seleccion, Dibujo_t* dibujo) {
    switch (input) {
            case BOTON_ABAJO:
                seleccion[*indice_seleccion] = ' ';
                if (*indice_seleccion >= 4 ) {
                    *indice_seleccion = 0;
                } else {
                    (*indice_seleccion)++;
                }
                seleccion[*indice_seleccion] = '*';
                break;
            case BOTON_ARRIBA:
                seleccion[*indice_seleccion] = ' ';
                if (*indice_seleccion <= 0) {
                    *indice_seleccion = 4;
                } else {
                    (*indice_seleccion)--;
                }
                seleccion[*indice_seleccion] = '*';
                break;
            case BOTON_ACEPTAR: //Boton Rojo de aceptar
                opcionElegidaDibujo(*indice_seleccion, dibujo);
                break;
            case BOTON_ATRAS:
            	printf("Falla en salir del menu dibujo \n");
                break;
            default:
            	break;
    }
}

void dibujar (Dibujo_t* dibujo) {
	while (1) {
		BotonEvento_t input = botonLeer();
		switch (input) {
		case BOTON_ARRIBA:
		case BOTON_ABAJO:
		case BOTON_IZQUIERDA:
		case BOTON_DERECHA:
			dibujoAvanzar(dibujo, input);
			break;
		case BOTON_ACEPTAR:
			//Lectura de potes para obtener valores R, G Y B
			//dibujoPintar(dibujo, r, g, b);
			break;
		case BOTON_ATRAS:
			return;
		default:
			printf("Error al leer el boton al dibujar \n");
			break;
		}

	}
}

void menuDibujo() {
    Dibujo_t* dibujo = crearDibujo();
    frameBufferUpdate(dibujo->matriz);
    char seleccion[6] = {'*',' ',' ',' ',' '}; // 5 opciones en el menu + 1 por el /n
    int indice_seleccion = 0;

    while (1) {
        BotonEvento_t input = seleccionDibujo (seleccion, indice_seleccion);
        if (input == BOTON_ATRAS) {
        	dibujoBorrar(dibujo);
        	return;
        }
        interaccionMenuDibujo(input, seleccion, &indice_seleccion, dibujo);
        
    }
}


