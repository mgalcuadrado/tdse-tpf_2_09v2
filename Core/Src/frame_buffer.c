/*
 * frame_buffer.c
 *
 *  Created on: Jul 18, 2026
 *      Author: Mechi
 */



#include "frame_buffer.h"
#include "pixeles.h"
#define LIMITE 127

//uint32_t pines_rgb = R1_Pin | G1_Pin | BL1_Pin | R2_Pin | G2_Pin | B2_Pin;
volatile uint32_t framebuffer[BUFFER_FILAS][BUFFER_COLUMNAS];
void frameBufferInit(void)
{
   	//par de pixeles en negro: todos los pines_rgb se apagan (los pines están movidos al sector de reset)
    for (int f = 0; f < BUFFER_FILAS; f++){
        for (int c = 0; c < BUFFER_COLUMNAS; c++){
        	//if (f== 0&& c == 255) framebuffer[f][c] = parpixeles_B1;
        	//else
        	framebuffer[f][c] = parpixeles_negro;
        	//amebuffer[f][c] = parpixeles_B1_R2;
        }
    }
}

const uint32_t rgb1 = R1_Pin | BL1_Pin | G1_Pin |((R1_Pin | BL1_Pin | G1_Pin)<<16);
const uint32_t rgb2 = R2_Pin | B2_Pin | G2_Pin |((R2_Pin | B2_Pin | G2_Pin)<<16);

void frameBufferUpdateCasilla(Matriz_t * matriz, int fila_matriz, int columna_matriz){
	uint8_t inf = 1;
	if (fila_matriz%16 < 8)inf=0; //para saber si va en rgb1 o rgb2
	uint8_t pantalla = 1;
		if (fila_matriz >= 16)  pantalla = 2;	//para saber si va a la pantalla 1 o a la pantalla 2
	uint8_t f = fila_matriz %2;
	uint8_t c = 0;
	if (!inf) c = (pantalla==1)?((int)(fila_matriz /2))*MATRIZ_COLUMNAS + columna_matriz : ((int)((fila_matriz-8)/2))*MATRIZ_COLUMNAS + columna_matriz;
	else c = (pantalla==1)?(((int)((fila_matriz-8)/2)))*MATRIZ_COLUMNAS+ columna_matriz: ((int)((fila_matriz-16)/2))*MATRIZ_COLUMNAS+ columna_matriz;
	uint8_t r=0, g=0, b=0;
	 matrizGetColorCasillero(matriz, fila_matriz, columna_matriz, &r, &g, &b);
	 uint32_t color = 0;
	 switch (inf){
		case 0:
			//los datos van en RGB1
			if (r > LIMITE) color |= R1_Pin;
			else color |= (R1_Pin <<16);
			if (g > LIMITE) color |= G1_Pin;
			else color |= (G1_Pin <<16);
			if (b > LIMITE) color |= B1_Pin;
			else color |= (B1_Pin <<16);
			break;
		case 1:
			if (r > LIMITE) color |= R2_Pin;
			else color |= (R2_Pin <<16);
			if (g > LIMITE) color |= G2_Pin;
			else color |= (G2_Pin <<16);
			if (b > LIMITE) color |= B2_Pin;
			else color |= (B2_Pin <<16);
			break;
		default:
			break;
	}

	 uint32_t buffer= framebuffer[f][c];
	 buffer&= ~(inf == 0 ? rgb1 : rgb2); //SE LIMPIAN LOS BITS YA GUARDADOS PARA ESTA CASILLA EN EL BUFFER
	 buffer|= color;
	 framebuffer[f][c] = buffer;

}

static int fila_test = 0;
static int columna_test = 0;
void testBarridoCompleto(Matriz_t * matriz){
	uint8_t r = 0,g = 0,b = 0;
	if (fila_test <8) r=255;
	else if (fila_test < 16) g = 255;
	else if (fila_test < 24) r = 255;
	else {
		//r=255;
		g=255;//b=255;
	}
	matrizSetCasillero(matriz, fila_test, columna_test, r,g,b);
    frameBufferUpdateCasilla(matriz, fila_test, columna_test);
    columna_test++;
    if (columna_test == MATRIZ_COLUMNAS){
    	columna_test = 0;
    	fila_test++;
    	if (fila_test == MATRIZ_FILAS) fila_test = 0;
    }
}

void testBarridoBuffer(void){
	framebuffer[fila_test][columna_test] = parpixeles_B1_R2;
	columna_test++;
	    if (columna_test == BUFFER_COLUMNAS){
	    	columna_test = 0;
	    	fila_test++;
	    	if (fila_test == BUFFER_FILAS) fila_test = 0;
	    }
}
