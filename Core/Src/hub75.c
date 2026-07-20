/*
 * hub75.c
 *
 *  Created on: Jul 18, 2026
 *      Author: Mechi
 */



#include "hub75.h" //de acá saca el buffer
#include <stdio.h>
#define MASK_A 0x01
#define MASK_B 0x02
#define MASK_C 0x04
#define MASK_D 0x08
/* Nota importante: hub75 está considerando que cada uno de estos pines
 se encuentra en la siguiente sección de puertos:
 GPIOA : LAT,OE
 GPIOB: A,B,C,D,CLK
 GPIOC: R1,G1,B1,R2,G2,B2
*/

static int fila_actual = 0;

void hub75Refresh(void){

	GPIOA -> BSRR = OE_Pin; //prender el OE implica apagar la pantalla (lógica invertida)
	GPIOB -> BSRR = (A_Pin | B_Pin | C_Pin | D_Pin)<<16; //se apagan todos los pines
	uint32_t direccion = 0;

	if (fila_actual & MASK_A) direccion |= A_Pin;
	if (fila_actual & MASK_B) direccion |= B_Pin;
	if (fila_actual & MASK_C) direccion |= C_Pin;
	//printf("dirección: %lu\n", direccion);
	GPIOB -> BSRR = direccion;


	for (int columna = 0;columna < BUFFER_COLUMNAS; columna++){
		uint32_t buffer = framebuffer[fila_actual][columna];
		GPIOC->BSRR= framebuffer[fila_actual][columna];
		//printf("framebuffer[%d][%d]=%lu\n", fila, columna,framebuffer[fila][columna]);
		GPIOB->BSRR = CLK_Pin;
		__NOP(); // Pausa de 1 ciclo de reloj (macro estándar de ARM)
		__NOP();
		__NOP();
		__NOP();
		//pulso de clock para indicar inicio del pasaje de datos
		GPIOB->BSRR = (CLK_Pin)<<16;
	}
	GPIOA -> BSRR = LAT_Pin; //se fijan los datos previos con un pulso
	__NOP(); // Pausa de 1 ciclo de reloj (macro estándar de ARM)
	__NOP();
	__NOP();
	__NOP();
	GPIOA -> BSRR = (LAT_Pin)<<16;
	GPIOA -> BSRR = (OE_Pin<<16); //apago OE para prender pantalla (lógica inversa)
	fila_actual++;
	if (fila_actual == BUFFER_FILAS) fila_actual = 0;
}
