/*
 * pixeles.h
 *
 *  Created on: 31 jul 2026
 *      Author: mechi
 */

#ifndef SRC_PIXELES_H_
#define SRC_PIXELES_H_

//Distintas combinaciones de colores de pixeles
uint32_t casilla_B1 = BL1_Pin | ((G2_Pin | B2_Pin | R2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t casilla_B2 = B2_Pin | ((G2_Pin | BL1_Pin | R2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t casilla_G1 = G1_Pin | ((G2_Pin | B2_Pin | R2_Pin | BL1_Pin | R1_Pin)<<16);
uint32_t casilla_G2 = G2_Pin | ((BL1_Pin | B2_Pin | R2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t casilla_R1 = R1_Pin | ((G2_Pin | B2_Pin | R2_Pin | G1_Pin | BL1_Pin)<<16);
uint32_t casilla_R2 = R2_Pin | ((G2_Pin | B2_Pin | BL1_Pin | G1_Pin | R1_Pin)<<16);

uint32_t casilla_B1_B2 = BL1_Pin | B2_Pin  | (( G2_Pin | R2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t casilla_B1_R2 = BL1_Pin | R2_Pin  | (( B2_Pin | G2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t casilla_R1_R2 = R1_Pin | R2_Pin  | (( B2_Pin | G2_Pin | G1_Pin | BL1_Pin)<<16);
uint32_t casilla_G1_G2 = G1_Pin | G2_Pin  | (( B2_Pin | R2_Pin | R1_Pin | BL1_Pin)<<16);
uint32_t casilla_negro =  ((R1_Pin | G2_Pin | B2_Pin | R2_Pin | G1_Pin | BL1_Pin)<<16);
uint32_t casilla_blanco =  R1_Pin | G2_Pin | B2_Pin | R2_Pin | G1_Pin | BL1_Pin;



#endif /* SRC_PIXELES_H_ */
