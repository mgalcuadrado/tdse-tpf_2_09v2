/*
 * pixeles.h
 *
 *  Created on: 31 jul 2026
 *      Author: mechi
 */

#ifndef SRC_PIXELES_H_
#define SRC_PIXELES_H_

//Distintas combinaciones de colores de pixeles

/* cada uint32_t de pixeles una lógica de Bit Set/Reset Register (BSRR):
    Bits 0 al 15 son de SETteo (un 1 en la posición i implica settear ese pin a 1 (encendido)).
        Ej: |**************** ***************1| implica encender el pin asociado a la posición 0.
    Bits 16 al 31 son de RESETteo (un 1 en la posición i<<16 implica resettear ese pin (apagado))
        Ej: |***************1 ****************| implica apagar el pin asociado a la posición 0.
*/

uint32_t parpixeles_B1 = BL1_Pin | ((G2_Pin | B2_Pin | R2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t parpixeles_B2 = B2_Pin | ((G2_Pin | BL1_Pin | R2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t parpixeles_G1 = G1_Pin | ((G2_Pin | B2_Pin | R2_Pin | BL1_Pin | R1_Pin)<<16);
uint32_t parpixeles_G2 = G2_Pin | ((BL1_Pin | B2_Pin | R2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t parpixeles_R1 = R1_Pin | ((G2_Pin | B2_Pin | R2_Pin | G1_Pin | BL1_Pin)<<16);
uint32_t parpixeles_R2 = R2_Pin | ((G2_Pin | B2_Pin | BL1_Pin | G1_Pin | R1_Pin)<<16);

uint32_t parpixeles_B1_B2 = BL1_Pin | B2_Pin  | (( G2_Pin | R2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t parpixeles_B1_R2 = BL1_Pin | R2_Pin  | (( B2_Pin | G2_Pin | G1_Pin | R1_Pin)<<16);
uint32_t parpixeles_R1_R2 = R1_Pin  | R2_Pin  | (( B2_Pin | G2_Pin | G1_Pin | BL1_Pin)<<16);
uint32_t parpixeles_G1_G2 = G1_Pin  | G2_Pin  | (( B2_Pin | R2_Pin | R1_Pin | BL1_Pin)<<16);
uint32_t parpixeles_B1_W2 = BL1_Pin | B2_Pin  | G2_Pin | R2_Pin  | ((G1_Pin | R1_Pin)<<16);
uint32_t parpixeles_negro = (R1_Pin | G2_Pin  | B2_Pin | R2_Pin | G1_Pin | BL1_Pin)<<16;
uint32_t parpixeles_blanco = R1_Pin | G2_Pin  | B2_Pin | R2_Pin | G1_Pin | BL1_Pin;



#endif /* SRC_PIXELES_H_ */
