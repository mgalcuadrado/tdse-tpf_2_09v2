

#include "lcd.h"



static I2C_HandleTypeDef *lcd_hi2c;

static char bufferLCD[LCD_FILAS][LCD_COLUMNAS+1];		//Es lo que se manda al actuador para imprimir
static bool refreshearLCD = false;						//Indica al actuador que tiene que updatear el lcd

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

static bool lcdMandarInterno(char data, uint8_t rs) {
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

    return (HAL_I2C_Master_Transmit(lcd_hi2c, LCD_I2C_ADDR, arregloDatos, 4, 10) == HAL_OK);
}

static bool  lcdMandarComando(char cmd) {
    return lcdMandarInterno(cmd, 0x00); // RS = 0 para comandos
}

static bool lcdMandarDato(char data) {
    return lcdMandarInterno(data, 0x01); // RS = 1 para caracteres de texto
}

void lcdBorrar(void) {
    lcdMandarComando(0x01);
    HAL_Delay(2);
}

// Posiciona el cursor en un LCD 2004 (4 lineas x 20 columnas)
bool lcdSetearCursor(uint8_t col, uint8_t fil) {
    uint8_t offsets[] = {0x00, 0x40, 0x14, 0x54};	//Las direcciones de memoria DDRAM de cada fila están desordenadas
    if (fil < 4) {
        return lcdMandarComando(0x80 | (offsets[fil] + col));
    }
    return false;
}

//Imprime una cadena
static bool lcdPrint(char *cadena) {
    while (*cadena) {
    	if (!lcdMandarDato(*cadena++)) {
    		return false; // Retorna false si falla algún byte
		}
    }
    return true;
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

//Funcion que se llamará en la tarea procesar, manda al buffer lo que se imprimirá en el actuador
void lcdBufferearLinea(uint8_t linea, char* cadena){
	if (linea >= LCD_FILAS || cadena == NULL) {
		return;
	}

	//Primero se revisa si cambió respecto a lo anteriormente mostrado
	//Si cambió, pongo la flag de refreshearLCD en true
	uint8_t i=0;
	while (cadena[i] != '\0' && i < LCD_COLUMNAS) {

	        if (bufferLCD[linea][i] != cadena[i]) {
	            bufferLCD[linea][i] = cadena[i];
	            refreshearLCD = true;
	        }
	        i++;
	}

	//Le pongo espacios en los caracteres vacíos porque la ejecución de lcdBorrar demora 2ms aprox

	while (i < LCD_COLUMNAS) {
	        if (bufferLCD[linea][i] != ' ') {
	            bufferLCD[linea][i] = ' ';
	            refreshearLCD = true;
	        }
	        i++;
	    }
	bufferLCD[linea][LCD_COLUMNAS] = '\0';
}

//Esta función se llama en el actuador, toma el buffer y lo imprime.
void lcdActuar(){

	if (lcd_hi2c->State != HAL_I2C_STATE_READY || !refreshearLCD) {
		return;
	}

	for (uint8_t fil = 0; fil < LCD_FILAS; fil++) {
	        if(!lcdSetearCursor(0, fil)){
	        	return;						//Si falla una de las 2, vuelve a intentar
	        }

	        if(!lcdPrint(bufferLCD[fil])){
	        	return;
	        }
	}
	refreshearLCD=false;	//Cambia la flag si no tiene que reintentar el print
}

//Borrar buffer para el procesar, menos bloqueante que con el comando.
void lcdVaciarBuffer(){
	for (uint8_t fil = 0; fil < LCD_FILAS; fil++) {
		for (uint8_t col = 0; col < LCD_COLUMNAS; col++) {
			if (bufferLCD[fil][col] != ' ') {
				bufferLCD[fil][col] = ' ';
				refreshearLCD = true;
			}
		}
	}
}
