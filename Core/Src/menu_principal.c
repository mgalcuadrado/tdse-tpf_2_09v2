/* 
 * menu_principal.c
 *
 * Created on: Aug 7, 2026
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
#include "dibujo.h"
#include "boton.h"
#include "menu_principal.h"
#include "menu_dibujo.h"
#include "menu_secuencia.h"

void menuPrincipalMain (void) {
	char seleccion[3] = {'*',' '}; // 2 opciones en el menu + 1 contando el \n
	int indice_seleccion = 0;
	menuPrincipalPrint(seleccion, indice_seleccion);
	while (1) {
		BotonEvento_t input = botonLeer();
		switch (input) {
			case BOTON_ABAJO:
			case BOTON_ARRIBA:
				seleccion[indice_seleccion] = ' ';
				if (indice_seleccion == 1 ) {
				    indice_seleccion = 0;
				} else {
				    indice_seleccion = 1;
				}
				seleccion[indice_seleccion] = '*';
				menuPrincipalPrint(seleccion, indice_seleccion);
				break;
			case BOTON_ACEPTAR:
				if (indice_seleccion == 0) {
					menuDibujoMain();
				} else {
					menuSecuenciaMain();
				}
				break;
			default:
				break;
		}
	}
}

void menuPrincipalPrint(char seleccion[3], int indice_seleccion) {
	char mensaje1[MAX_CARACTERES_MENSAJE];
	char mensaje2[MAX_CARACTERES_MENSAJE];
	char mensaje3[MAX_CARACTERES_MENSAJE];
	snprintf(mensaje1, sizeof(mensaje1), "UBA en Acción: Juego RGB");
	snprintf(mensaje2, sizeof(mensaje2), "(%c) Modo Dibujo", seleccion[0]);
	snprintf(mensaje3, sizeof(mensaje3), "(%c) Modo Secuencia", seleccion[1]);

	lcdSetearCursor(0, 0);
	lcdPrint(mensaje1);

	lcdSetearCursor(0, 1);
	lcdPrint(mensaje2);

	lcdSetearCursor(0, 2);
	lcdPrint(mensaje3);
}
