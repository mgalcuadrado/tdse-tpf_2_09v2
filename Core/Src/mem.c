/*
 * mem.c
 *
 *  Created on: Apr 4, 2026
 *      Author: Martin
 */


#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





#define EEPROM_I2C_ADDR       (0x50 << 1)  // Dirección I2C base de la AT24C256
#define EEPROM_PAGE_SIZE      64           // Tamaño de página de la AT24C256 (64 bytes)


//V2 con arquitectura nueva

extern I2C_HandleTypeDef hi2c1;

// Buffer para enviar al acttuador
static uint8_t bufferMemoria[sizeof(Matriz_t)];

// Variables para el guardado no bloqueante
static bool memEscribiendo = false;
static uint16_t addrActual = 0;
static uint16_t bytesRestantesAEscribir = 0;
static uint16_t bytesEscritos = 0;
static uint32_t ultimoTiempo = 0;


// Función para leer los datos (No importa el limite de pagina acá)
HAL_StatusTypeDef memLeer(uint16_t addr, uint8_t *datos, uint16_t largo)
{
    return HAL_I2C_Mem_Read(&hi2c1, EEPROM_I2C_ADDR, addr,
                           I2C_MEMADD_SIZE_16BIT,
                           datos, largo, HAL_MAX_DELAY);
}




// Procesar: manda lo que se va a escribir al buffer
//Mando a escribir el bloque de 3*32*32 bytes = 3072 bytes

bool memBufferearEscrituraMatriz(uint16_t addr, Matriz_t* matriz) {
    // Si la eeprom ya está ocupada guardando algo, se rechaza otra escritura
    if (memEscribiendo || matriz == NULL) {
        return false;
    }

    // Copiamos la matriz al buffer
    memcpy(bufferMemoria, matriz, sizeof(Matriz_t));


    addrActual = addr;
    bytesEscritos = 0;
    bytesRestantesAEscribir = sizeof(Matriz_t);
    ultimoTiempo = 0;

    // Levantamos la bandera para la fase ACTUAR
    memEscribiendo = true;
    return true;
}

//Devuelve si la memoria esta ocupada por si es necesario
bool memEstaOcupada(void) {
    return memEscribiendo;
}

// Leo la matriz desde la eeprom
HAL_StatusTypeDef memLeerMatriz(uint16_t addr, Matriz_t* matriz) {
    if (memEscribiendo) {
        return HAL_BUSY; // No leer mientras se está escribiendo
    }
    return memLeer(addr, (uint8_t*)matriz, sizeof(Matriz_t));
}

// Actuador
void memActuar(void) {
    if (memEscribiendo==false) {
        return;
    }

    // Dado que la versión anterior era bloqueante, se usa un timer para la espera necesaria de 5ms entre páginas
    // Espero 5ms a la escritura de la eeprom o sino explota

    if ((HAL_GetTick() - ultimoTiempo) < 5) {
        return;
    }

    //Escribo una pagina en la eeprom, y no escribo de nuevo hasta que hayan pasado los 5ms

    // Calculo cuantos bytes puedo escribir antes de chocar
	// con el limite de pagina o quedarme sin datos para escribir
    uint16_t limitePagina = EEPROM_PAGE_SIZE - (addrActual % EEPROM_PAGE_SIZE);
    uint16_t sizeFragmento = (bytesRestantesAEscribir < limitePagina) ? bytesRestantesAEscribir : limitePagina;


    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&hi2c1, EEPROM_I2C_ADDR, addrActual,
                                                I2C_MEMADD_SIZE_16BIT,
                                                &bufferMemoria[bytesEscritos],
                                                sizeFragmento, 100);

    if (status == HAL_OK) {

        // Updateo mis punteros para el loop
        addrActual += sizeFragmento;
        bytesEscritos += sizeFragmento;
        bytesRestantesAEscribir -= sizeFragmento;
        ultimoTiempo = HAL_GetTick(); // Guardamos el tiempo de esta página


        if (bytesRestantesAEscribir == 0) {
            memEscribiendo = false; // Baja la flag si
        }
    }
}
