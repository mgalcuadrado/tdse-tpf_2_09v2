/*
 * app.c
 *
 *  Created on: Aug 14, 2026
 *      Author: Martin
 */

#include "lcd.h"
#include "boton.h"

//Acá entraría cualquier init necesario para el programa
void appInit(){

	return;
}

void appUpdate(){
	taskEscrutar();
	taskProcesar();
	taskActuar();
}

void taskEscrutar(){
	botonLeer();
	//leerPotenciometros();

}
void taskProcesar(){
	//menuProcesar();
}
void taskActuar(){
	lcdActuar();
	hub75Actuar();
}
