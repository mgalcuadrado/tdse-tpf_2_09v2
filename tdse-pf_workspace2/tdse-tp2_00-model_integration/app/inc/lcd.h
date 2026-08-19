#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>
#include <stdbool.h>
#define LCD_FILAS 4
#define LCD_COLUMNAS 20

// Dirección I2C del adaptador desplazado 1 a la izquierda
#define LCD_I2C_ADDR (0x27 << 1)



void lcdInicializar(I2C_HandleTypeDef *hi2c);
void lcdBorrar(void);
bool lcdSetearCursor(uint8_t col, uint8_t fil);

//Luego de adaptar la estructura, las que se ven desde afuera deberían ser:
void lcdActuar();														//Actuador
void lcdBufferearLinea(uint8_t linea, char* cadena);					//Procesador
void lcdVaciarBuffer();


#endif /* INC_LCD_H_ */
