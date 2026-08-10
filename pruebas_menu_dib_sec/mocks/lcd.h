/*
 * mocks/lcd.h
 *
 * MOCK para tests de escritorio: en vez de escribir a un LCD físico,
 * guarda el último texto impreso en cada fila para poder inspeccionarlo.
*/

#ifndef LCD_H
#define LCD_H

#include <stdint.h>

#define LCD_FILAS 4
#define LCD_MAX_CARACTERES 64

void lcdSetearCursor(uint8_t columna, uint8_t fila);
void lcdPrint(const char* mensaje);
void lcdBorrar(void);

// --- Utilidades del mock ---
extern char lcd_contenido[LCD_FILAS][LCD_MAX_CARACTERES];
extern int lcdPrint_llamadas;
void lcd_mock_reset(void);

#endif
