/*
 * mem.h
 *
 *  Created on: Apr 4, 2026
 *      Author: Martin
 */

#ifndef INC_MEM_H_
#define INC_MEM_H_

#include "stm32f1xx_hal.h"
#include "matriz.h"

HAL_StatusTypeDef memEscribir(uint16_t addr, uint8_t *datos, uint16_t largo);
HAL_StatusTypeDef memLeer(uint16_t addr, uint8_t *datos, uint16_t largo);

HAL_StatusTypeDef memEscribirMatriz(uint16_t addr, Matriz_t* matriz);
HAL_StatusTypeDef memLeerMatriz(uint16_t addr, Matriz_t* matriz);


#endif
