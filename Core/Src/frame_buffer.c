/*
 * frame_buffer.c
 *
 *  Created on: Jul 18, 2026
 *      Author: Mechi
 */



#include "frame_buffer.h"
#define LIMITE 127
/* cada uint32_t en framebuffer una lógica de Bit Set/Reset Register (BSRR):
    Bits 0 al 15 son de SETteo (un 1 en la posición i implica settear ese pin a 1 (encendido)).
        Ej: |**************** ***************1| implica encender el pin asociado a la posición 0. 
    Bits 16 al 31 son de RESETteo (un 1 en la posición i<<16 implica resettear ese pin (apagado))
        Ej: |***************1 ****************| implica apagar el pin asociado a la posición 0. 
*/
uint32_t pines_rgb = R1_Pin | G1_Pin | B1_Pin | R2_Pin | G2_Pin | B2_Pin;
uint32_t framebuffer[BUFFER_FILAS][BUFFER_COLUMNAS];
void frameBufferInit(void)
{
    //para probar voy a prender en rojo toda la matriz al principio... a ver si sobrevive
    //uint32_t casilla_inicial1 = (( G1_Pin | B1_Pin | G2_Pin | B2_Pin)<<16) | R1_Pin | R2_Pin;
    uint32_t casilla_inicial2 = (( G1_Pin | R1_Pin | G2_Pin | R2_Pin)<<16) | B1_Pin | B2_Pin;
    //casillas en negro: todos los pines_rgb se apagan (los pines están movidos al sector de reset)
    uint32_t casilla_negro = (pines_rgb<<16);
    for (int f = 0; f < BUFFER_FILAS; f++){
        for (int c = 0; c < BUFFER_COLUMNAS; c++){
            framebuffer[f][c] = casilla_negro;
        	/*if (c == f) framebuffer[f][c] = casilla_inicial2;
        	else framebuffer[f][c] = casilla_negro;*/
        }
    }
}

void frameBufferUpdate(Matriz_t * matriz){
    for (int f = 0; f < BUFFER_FILAS; f++){
        for (int c = 0; c < BUFFER_COLUMNAS; c++){
            uint8_t r=0, g=0, b=0;
            matrizGetColorCasillero(matriz, f, c, &r, &g, &b);
            if (r > LIMITE) {
            	framebuffer[f][c] |= R1_Pin;
            	//framebuffer[f][c] |= !(R1_Pin <<16)
            }
            else {
            	framebuffer[f][c] |= (R1_Pin <<16);
            	//framebuffer[f][c] |= !R1_Pin;
            }
            if (g > LIMITE){
            	framebuffer[f][c] |= G1_Pin;
            	//framebuffer[f][c] |= !(G1_Pin <<16)
            }
            else {
            	framebuffer[f][c] |= (G1_Pin <<16);
            	//framebuffer[f][c] |= !G1_Pin;
            }
            if (b > LIMITE){
            	framebuffer[f][c] |= B1_Pin;
            }
			else{
				framebuffer[f][c] |= (B1_Pin <<16);
			}
            matrizGetColorCasillero(matriz, f+BUFFER_FILAS, c, &r, &g, &b);
			if (r > LIMITE) {
				framebuffer[f][c] |= R2_Pin;
				//framebuffer[f][c] |= !(R2_Pin <<16)
			}
			else {
				framebuffer[f][c] |= (R2_Pin <<16);
				//framebuffer[f][c] |= !R2_Pin;
			}
			if (g > LIMITE){
				framebuffer[f][c] |= G2_Pin;
				//framebuffer[f][c] |= !(G2_Pin <<16)
			}
			else {
				framebuffer[f][c] |= (G2_Pin <<16);
				//framebuffer[f][c] |= !G2_Pin;
			}
			if (b > LIMITE){
				framebuffer[f][c] |= B2_Pin;
			}
			else{
				framebuffer[f][c] |= (B2_Pin <<16);
           }

        }
    }
}

