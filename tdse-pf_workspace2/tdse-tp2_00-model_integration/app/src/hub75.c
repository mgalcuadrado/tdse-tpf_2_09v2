/*
 * hub75.c
 *
 *  Created on: Jul 18, 2026
 *      Author: mechi
 */




#include "hub75.h" //de acá saca el buffer
#include <stdio.h>
#include "main.h"

//#include "pixeles.h" //de aca saca pares de pixeles distintos para pruebas
#define MASK_A 0x01
#define HUB75_INTERVALO 7u

/* Nota importante: hub75 está considerando que cada uno de estos pines
 se encuentra en la siguiente sección de puertos:
 GPIOA : LAT,OE
 GPIOB: A,B,C,D,CLK
 GPIOC: R1,G1,B1,R2,G2,B2
*/
static int fila_actual = 0;
static uint32_t ultimoTiempoHub75 = 0;

//static int brillo_pantalla;
void hub75Init(void){
	GPIOA -> BSRR = OE_Pin | (LAT_Pin<<16);
	GPIOB -> BSRR = (A_Pin | CLK_Pin)<<16;
	GPIOC->BSRR= (R1_Pin | G1_Pin | BL1_Pin | R2_Pin | G2_Pin | B2_Pin)<<16;
	//brillo_pantalla = 100;
}

void hub75Refresh(void);

void hub75Update(void){
	uint32_t ahora = HAL_GetTick();
	if ((ahora - ultimoTiempoHub75) < HUB75_INTERVALO) {
		return; // Todavia no paso el tiempo definido de esta sección
	}
	ultimoTiempoHub75 = ahora;
	hub75Refresh();
}



const uint32_t B1_R2 = BL1_Pin | R2_Pin  | (( B2_Pin | G2_Pin | G1_Pin | R1_Pin)<<16);
const uint32_t G1_G2 = G1_Pin | G2_Pin  | (( B2_Pin | R2_Pin | R1_Pin | BL1_Pin)<<16);

void hub75Refresh(void){
	for (int columna = 0;columna < BUFFER_COLUMNAS; columna++){
		GPIOC->BSRR= framebuffer[fila_actual][columna];
		GPIOB->BSRR = CLK_Pin;
		GPIOB->BSRR = (CLK_Pin)<<16;
	}

	GPIOA -> BSRR = OE_Pin; //prender el OE implica apagar la pantalla (lógica invertida)
	//Fijado de datos de la línea completa
	GPIOA -> BSRR = LAT_Pin; //se fijan los datos previos con un pulso
	GPIOA -> BSRR = (LAT_Pin)<<16;

	//Direccionamiento a la siguiente fila
	fila_actual++;
	if (fila_actual == BUFFER_FILAS) fila_actual = 0;
		GPIOB -> BSRR = (A_Pin )<<16; //se apagan todos los pines
		uint32_t direccion = 0;
		if (fila_actual & MASK_A) direccion |= A_Pin;
		GPIOB -> BSRR = direccion;
	GPIOA -> BSRR = (OE_Pin<<16); //apago OE para prender pantalla (lógica inversa)
}

void hub75SetBrightness(int brillo){
return;
}