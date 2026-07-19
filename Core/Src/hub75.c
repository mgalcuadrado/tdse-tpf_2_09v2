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

void hub75Refresh(void){
	for (int fila = 0; fila < BUFFER_FILAS; fila++){
        GPIOA -> BSRR = OE_Pin; //prender el OE implica apagar la pantalla (lógica invertida)
        GPIOB -> BSRR = (A_Pin | B_Pin | C_Pin | D_Pin)<<16; //se apagan todos los pines
        uint32_t direccion = 0;
        
        if (fila & MASK_A) direccion |= A_Pin;
        if ((fila & MASK_B)>>1) direccion |= B_Pin;
        if ((fila & MASK_C)>>2) direccion |= C_Pin;
        //if ((fila & MASK_D)>>3) direccion |= D_Pin;
       // printf("fila = %d manda dirección %lu\n", fila, GPIOB->BSRR);
        
        GPIOB -> BSRR = direccion;
        for (int columna = 0;columna < BUFFER_COLUMNAS; columna++){
            GPIOC->BSRR= framebuffer[fila][columna]; 
            //printf("framebuffer[%d][%d]=%lu\n", fila, columna,framebuffer[fila][columna]);
            GPIOB->BSRR = CLK_Pin; //pulso de clock para indicar inicio del pasaje de datos
            GPIOB->BSRR = (CLK_Pin)<<16;   
        }
        GPIOA -> BSRR = LAT_Pin; //se fijan los datos con un pulso
        GPIOA -> BSRR = (LAT_Pin)<<16;
        GPIOA -> BSRR = (OE_Pin<<16); //apago OE para prender pantalla (lógica inversa)
    }
}
