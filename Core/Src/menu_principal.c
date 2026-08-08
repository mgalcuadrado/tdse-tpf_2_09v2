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

void menuPrincipal (void) {
	char seleccion[3] = {'*',' '}; // 2 opciones en el menu + 1 contando el \n
	int indice_seleccion = 0;
	char mensaje1[50];
	char mensaje2[50];
	char mensaje3[50];
	while (1) {
		snprintf(mensaje1, sizeof(mensaje1), "UBA en Acción: Juego RGB");
		snprintf(mensaje2, sizeof(mensaje1), "(%c) Modo Dibujo", seleccion[0]);
		snprintf(mensaje3, sizeof(mensaje2), "(%c) Modo Secuencia", seleccion[1]);

		lcdSetearCursor(0, 0);
		lcdPrint(mensaje1);

		lcdSetearCursor(0, 1);
		lcdPrint(mensaje2);

		lcdSetearCursor(0, 2);
		lcdPrint(mensaje3);

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
				break;
			case BOTON_ACEPTAR:
				if (indice_seleccion == 0) {
					menuDibujo();
				} else {
					menuSecuencia();
				}
				break;
			default:
				break;
		}
	}
}
