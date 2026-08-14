#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f1xx_hal.h"

// Dirección I2C del adaptador desplazado 1 a la izquierda
#define LCD_I2C_ADDR (0x27 << 1)
#define MAX_CARACTERES_MENSAJE 20

void lcdInicializar(I2C_HandleTypeDef *hi2c);
void lcdBorrar(void);
void lcdSetearCursor(uint8_t col, uint8_t fil);


void lcdPrint(char *cadena);

//Funciones de bajo nivel
void lcdMandarComando(char cmd);
void lcdMandarDato(char data);

#endif /* INC_LCD_H_ */
