

#include "lcd.h"

static I2C_HandleTypeDef *lcd_hi2c;
//Lista de comandos con rs=0

//0x01 limmpia el display, vuelve el cursor a 0,0
//0x02 vuelve el cursor a 0,0
//0x06 para que el cursor avance cada vez que se escribe un caracter
//0x08 apaga la pantalla sin borrar la ram
//0x0C enciende la pantalla y esconde el cursor
//0x0E enciende la pantalla y muestra el cursor
//0x0F enciende la pantalla y muestra el cursor parpadeando
//0x10 mueve el cursor a la izquierda
//0x14 mueve el cursor a la derecha
//0x28 pone la pantalla en modo 4 bits, fuente de 5x8 pixeles con 2 o 4 lineas
//0x30 lo pone en modo 8 bits
//0x32 lo pone en modo 4 bits
//0x40 a 0x7F dice que los proximos datos con rs=1 son para hacer un caracter personalizado
//0x80 hasta 0xFF mueve el cursor a una posicion especifica


// Manda un byte dividido en 4 bits

//rs es el registro, es 0x00 si es un comando y 0x01 si es un dato (Como una letra)
//data es el dato a mandar al lcd, o el comando.

static void lcdMandarInterno(char data, uint8_t rs) {
    HAL_StatusTypeDef res;
    //Divido el byte, up son los primeros 4 bits y lo los ultimos 4 bits, quedan los dos de la forma xxxx 0000
    uint8_t up = data & 0xF0;
    uint8_t lo = (data << 4) & 0xF0;

    // Bit 3 es el encendido de la backlight
    // Bit 2 es el enable (EN)
    // Bit 0 es register select (RS)
    uint8_t arregloDatos[4];
    arregloDatos[0] = up | rs | 0x0C; // 0000 1100	Mantengo la backlight prendida
    arregloDatos[1] = up | rs | 0x08; // 0000 1000	El ultimo bit va a ser rs
    arregloDatos[2] = lo | rs | 0x0C; // 0000 1100
    arregloDatos[3] = lo | rs | 0x08; // 0000 1000

    res = HAL_I2C_Master_Transmit(lcd_hi2c, LCD_I2C_ADDR, arregloDatos, 4, 100);
    (void)res;
}

void lcdMandarComando(char cmd) {
    lcdMandarInterno(cmd, 0x00); // RS = 0 para comandos
}

void lcdMandarDato(char data) {
    lcdMandarInterno(data, 0x01); // RS = 1 para caracteres de texto
}

void lcdBorrar(void) {
    lcdMandarComando(0x01);
    HAL_Delay(2);
}

// Posiciona el cursor en un LCD 2004 (4 lineas x 20 columnas)
void lcdSetearCursor(uint8_t col, uint8_t fil) {
    uint8_t offsets[] = {0x00, 0x40, 0x14, 0x54};
    if (fil < 4) {
        lcdMandarComando(0x80 | (offsets[fil] + col));
    }
}

//Imprime una cadena
void lcdPrint(char *cadena) {
    while (*cadena) {
        lcdMandarDato(*cadena++);
    }
}

// Inicialización estándar en modo 4 bits para el controlador HD44780
void lcdInicializar(I2C_HandleTypeDef *hi2c) {
    lcd_hi2c = hi2c;
    HAL_Delay(50); // Espera a que se estabilice antes de empezar

    // Secuencia de inicialización
    //Lo pone en 8 bits 2 veces, y despues le dice que se ponga en 4 bits
    //Esto es sugerido por el fabricante porque el chip no sabe en
    lcdMandarComando(0x30);
    HAL_Delay(5);
    lcdMandarComando(0x30);
    HAL_Delay(1);
    lcdMandarComando(0x32);
    HAL_Delay(10);

    lcdMandarComando(0x28); // Modo 4 bits, 2/4 líneas, matriz 5x8
    lcdMandarComando(0x0C); // Display ON, Cursor OFF, Parpadeo OFF
    lcdBorrar();
    lcdMandarComando(0x06); // Es para que el cursor avance cada vez que se escribe un caracter
}
