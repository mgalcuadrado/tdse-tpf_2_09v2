/*
 * mem.c
 *
 *  Created on: Apr 4, 2026
 *      Author: Martin
 */


#include "mem.h"
#include <stdio.h>
#include <stdlib.h>




#define EEPROM_I2C_ADDR       (0x50 << 1)  // Dirección I2C base de la AT24C256
#define EEPROM_PAGE_SIZE      64           // Tamaño de página de la AT24C256 (64 bytes)

extern I2C_HandleTypeDef hi2c1;

// Función genérica para escribir datos
HAL_StatusTypeDef memEscribir(uint16_t addr, uint8_t *datos, uint16_t largo)
{
    HAL_StatusTypeDef status = HAL_OK;
    uint16_t bytesEscritos = 0;

    while (largo > 0)	//Considero el largo como los bytes a escribir restantes
    {
        // Calculo cuantos bytes puedo escribir antes de chocar
    	// con el limite de pagina o quedarme sin datos para escribir

        uint16_t limitePagina = EEPROM_PAGE_SIZE - (addr % EEPROM_PAGE_SIZE);
        uint16_t sizeFragmento = (largo < limitePagina) ? largo : limitePagina;

        // Escribo en la eeprom mi fragmento
        status = HAL_I2C_Mem_Write(&hi2c1, EEPROM_I2C_ADDR, addr,
                                  I2C_MEMADD_SIZE_16BIT,
                                  &datos[bytesEscritos], sizeFragmento, HAL_MAX_DELAY);

        if (status != HAL_OK) {
            return status; 		//Esto es un chequeo de si hay errores, termina la funcion si falla
        }

        // Espero 5ms a la escritura de la eeprom o sino explota

        // Si igual explota consideremos subirlo un poquito, pero se haría que tarde mas
        // el guardado y eso chocaría con updatear el display (No se puede poner una barra de
        // progreso por ejemplo
        HAL_Delay(5);

        // Updateo mis punteros para el loop
        addr += sizeFragmento;
        bytesEscritos += sizeFragmento;
        largo -= sizeFragmento;
    }

    return status;
}

// Función para leer los datos (No importa el limite de pagina acá)
HAL_StatusTypeDef memLeer(uint16_t addr, uint8_t *datos, uint16_t largo)
{
    return HAL_I2C_Mem_Read(&hi2c1, EEPROM_I2C_ADDR, addr,
                           I2C_MEMADD_SIZE_16BIT,
                           datos, largo, HAL_MAX_DELAY);
}



// guardo la matriz en la eeprom
HAL_StatusTypeDef memEscribirMatriz(uint16_t addr, Matriz_t* matriz) {
    //Mando a escribir el bloque de 3*32*32 bytes = 3072 bytes
    return memEscribir(addr, (uint8_t*)matriz, sizeof(Matriz_t));
}

// Leo la matriz desde la eeprom
HAL_StatusTypeDef memLeerMatriz(uint16_t addr, Matriz_t* matriz) {

    return memLeer(addr, (uint8_t*)matriz, sizeof(Matriz_t));
}

