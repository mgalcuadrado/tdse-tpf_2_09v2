/*
 * app.c
 *
 *  Created on: Aug 14, 2026
 *      Author: Martin
 */
#include "main.h"
#include "matriz.h"
#include "mem.h"
#include "lcd.h"
#include "boton.h"
#include "estado.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "hub75.h"
#include "frame_buffer.h"
#include "potenciometro.h"


//Acá entraría cualquier init necesario para el programa
void appInit(){
	frameBufferInit();
	pote_init();
	hub75Init();
	lcdInicializar(&hi2c1);
	sistemaInit();
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
	sistemaProcesar();
}
void taskActuar(){
	lcdActuar();
	hub75Actuar();
}
