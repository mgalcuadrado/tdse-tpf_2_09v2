/*
 * hub75.c
 *
 *  Created on: Jul 18, 2026
 *      Author: mechi
 */




#include "hub75.h" //de acá saca el tamaño del buffer
#include <stdio.h>

#include "pixeles.h" //de aca saca casillas distintas para pruebas
#define MASK_A 0x01

/* Nota importante: hub75 está considerando que cada uno de estos pines
 se encuentra en la siguiente sección de puertos:
 GPIOA : LAT,OE
 GPIOB: A,B,C,D,CLK
 GPIOC: R1,G1,B1,R2,G2,B2
*/
static int fila_actual = 0;
void hub75Init(void){
	GPIOA -> BSRR = OE_Pin | (LAT_Pin<<16);
	GPIOB -> BSRR = (A_Pin | B_Pin | CLK_Pin)<<16;
	GPIOC->BSRR= casilla_negro;
	//GPIOC->BSRR= casilla_R1;


}
static int contador = 0;
void hub75Refresh(void){
    GPIOA -> BSRR = OE_Pin; //prender el OE implica apagar la pantalla (lógica invertida)
	GPIOB -> BSRR = (A_Pin | B_Pin )<<16; //se apagan todos los pines
	uint32_t direccion = 0;
	if (fila_actual & MASK_A) direccion |= A_Pin;
	GPIOB -> BSRR = direccion;

	for (int columna = 0;columna < BUFFER_COLUMNAS; columna++){
		//uint32_t buffer = framebuffer[fila_actual][columna];
		//GPIOC->BSRR= framebuffer[fila_actual][columna];
		if (columna %2 == 0) GPIOC->BSRR=casilla_R1_R2;
		else GPIOC->BSRR=casilla_G1_G2;
		// GPIOC->BSRR=casilla_negro;
		//pulso de clock para indicar inicio del pasaje de datos
		GPIOB->BSRR = CLK_Pin;
		GPIOB->BSRR = (CLK_Pin)<<16;
	}
	GPIOA -> BSRR = LAT_Pin; //se fijan los datos previos con un pulso
	GPIOA -> BSRR = (LAT_Pin)<<16;
	GPIOA -> BSRR = (OE_Pin<<16); //apago OE para prender pantalla (lógica inversa)
	contador++;
	if (contador == 2*BUFFER_COLUMNAS) contador = 0;
	fila_actual++;
	if (fila_actual == BUFFER_FILAS) fila_actual = 0;
}