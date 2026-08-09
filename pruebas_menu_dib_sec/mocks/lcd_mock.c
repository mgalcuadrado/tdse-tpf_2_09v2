/*
 * mocks/lcd_mock.c
*/

#include "lcd.h"
#include <string.h>

char lcd_contenido[LCD_FILAS][LCD_MAX_CARACTERES];
int lcdPrint_llamadas = 0;
static uint8_t fila_actual = 0;

void lcdSetearCursor(uint8_t columna, uint8_t fila) {
    (void)columna;
    fila_actual = (fila < LCD_FILAS) ? fila : 0;
}

void lcdPrint(const char* mensaje) {
    lcdPrint_llamadas++;
    strncpy(lcd_contenido[fila_actual], mensaje, LCD_MAX_CARACTERES - 1);
    lcd_contenido[fila_actual][LCD_MAX_CARACTERES - 1] = '\0';
}

void lcd_mock_reset(void) {
    memset(lcd_contenido, 0, sizeof(lcd_contenido));
    lcdPrint_llamadas = 0;
    fila_actual = 0;
}

void lcdBorrar(void) {
    memset(lcd_contenido, 0, sizeof(lcd_contenido));
}
