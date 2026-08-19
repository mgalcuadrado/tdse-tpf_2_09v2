# tdse-tpf_2_09v2
# Documentación General del Proyecto
## UBA en Acción: Juego RGB
### PROYECTO FINAL DE TALLER DE SISTEMAS EMBEBIDOS (TA123)
#### Dispositivo Interactivo Modular con Display RGB

En este archivo se encuentra la documentación central del Trabajo Integrador Final de Taller de Sistemas Embebidos del grupo 9 del curso 2 (1er Cuatrimestre del 2025) realizado para utilizarse en el stand de UBA en Acción de la Facultad de Ingeniería de la Universidad de Buenos Aires (UBA) con el objetivo de proveer un espacio lúdico dentro de la propuesta de UBa en Acción donde se motiven las vocaciones científico-tecnlógicas (STEM). Para este Trabajo Práctico Integrador se utilizó una ST NÚCLEO F103RB.

---

## Índice

1. [Sección 1: Visión General del Proyecto](#1-sección-1-visión-general-del-proyecto)
2. [Sección 2: Hardware del proyecto](#2-sección-2-hardware-del-proyecto)
3. [Sección 3: Configuración del IOC](#3-sección-3-configuración-del-ioc)
4. [Sección 4: Documentación de las pantallas (frame buffer y HUB75)](#4-sección-4-documentación-de-las-pantallas-frame-buffer-y-hub75)
5. [Sección 5: Documentación de la matriz](#5-sección-5-documentación-de-la-matriz)
6. [Sección 6: Documentación de los módulos I2C](#6-sección-6-documentación-de-los-módulos-i2c)
7. [Sección 7: Documentación de los estados](#7-sección-7-documentación-de-los-estados)
8. [Sección 8: Documentación de los botones](#8-sección-8-documentación-de-los-botones)
9. [Sección 9: Documentación del Menú](#9-sección-9-documentación-del-menú)
10. [Sección 10: Documentación de los potenciómetros](#10-sección-10-documentación-de-los-potenciómetros)
11. [Sección 11: Documentación de los cálculos de tiempos de ejecución](#11-sección-11-documentación-de-los-cálculos-de-tiempos-de-ejecución)

---

## 1. Sección 1: Visión General del Proyecto

* **Responsables:** 
    * BARRIONUEVO, JUAN BAUTISTA - 109086 - <jbbarrionuevo@fi.uba.ar>
    * GABAY, Cloe - 109788 - <cgabay@fi.uba.ar>
    * GAMBERALE, María de las Mercedes - 108834 - <mgamberale@fi.uba.ar>
    * LEON, Martín Fernando	- 109138 - <mfleon@fi.uba.ar>
* **Estado:** En revisión

### Descripción

El proyecto consiste en un sistema con pantallas RGB de 32x32 pixeles de modo de controlar por medio de botones y potenciómetros lo mostrado en la misma. Se diseñan dos modos de juego, secuencia (un juego de recordar e imitar una secuencia mostrada) y PixelArt (un juego para ir dibujando en la pantalla variando el color de lo mostrado con potenciómetros). Para navegar por los distintos modos y tener opciones en los mismos se utiliza un menú, mostrado en un Display I2C. Se agrega una memoria para almacenar pixelArts guardados y poder guardar nuevos. 

[Volver al Índice](#índice)

---

## 2. Sección 2: Hardware del proyecto

* **Responsables:** [María de las Mercedes Gamberale (mgalcuadrado)]
* **Estado:** Completado 

### Detalle del Hardware

Los materiales utilizados fueron los siguientes:

INCLUIR MATERIALES - TRAER DEL INFORME

### Nota importante sobre las pantallas obtenidas
Las pantallas a comprar requerían ser accesibles en precio, relativamente económicas y aptas para exteriores dado que los stands de UBA en Acción se realizan de día y al aire libre. El mejor trade-off entre estas características se encontró en las pantallas P10-3535-2S; sin embargo, la documentación de las mismas resultó ser escasa por lo que su funcionamiento adecuado fue analizado por inspección, prueba e investigación de variantes de los protocolos usuales de pantallas de esta índole. Esto se discutirá en detalle en [la documentación de las pantallas](#4-sección-4-documentación-de-las-pantallas-frame-buffer-y-hub75).

Se utilizaron dos pantallas RGB de 16x32 píxeles conectadas en cascada (_daisy chain_) y colocadas con la siguiente distribución:

![Distribución Pantallas](bitacoras/img/conexionado_pantallas.png)

Se destaca que las pantallas están invertidas una respecto a la otra ya que el cable de conexionado proveído por el fabricante no era lo suficientemente largo como para colocarlas con la misma orientación y, en lugar de rehacer el cable con un largo mayor, simplemente se rotó una de las pantallas para que los conectoeres de salida de la pantalla 1 y de entrada de la pantalla 2 quedaran alineados; esto se corrigió con relativa facilidad por software, no agregando complejidad mayor al problema en cuestión.  

### Justificación de inclusión de los buffers SN74HCT245 y su conexionado

### Justificación del uso de fuente switching - cálculos de consumo estimados

### Alimentación de la ST
Se trabajó en la alimentación independiente de la ST. Para esto resulta muy importante conocer lo siguiente:
1. Para alimentar externamente como se hace en este trabajo se debe mover el jumper JP5 del modo de alimentación por UART (U5V) al modo de alimentación externa (E5V). 
2. Se conecta luego a GND y a E5V.

### Esquemáticos y PCB

Para poder probar la alimentación de la ST con la fuente de 5V 4A se realizó, en una primera versión con el objetivo de probar las pantallas LED y la alimentación de la ST Núcleo, el siguiente PCB:
Nótese que el LD1 cuando se está trabajando con alimentación externa se prenderá y apagará intermitentemente. Esto es adecuado para la utilización de alimentación externa ya que es indicadora de que no se detecta comunicación por UART.
![Diseño PCBv1](bitacoras/img/captura_pcb_v1.png)
![Placa v1 en físico](bitacoras/img/fisico_pcb_v1.jpg)

La primera placa se diseñó en EasyEDA el 16 de julio del 2026 y [el proyecto se puede visualizar en este enlace]( https://oshwlab.com/mgamberale/project_ptvksycq). 

Con esta placa, al ver que esta no funcionaba como era debido, se resolvió agregar los transceptores SN74HCT245 para que las señales recibidas en la pantalla tuviesen un nivel lógico de 5V (como es debido) en lugar de los 3V3 de los pines de salida de la ST NÚCLEO F103RB. 

Se realizó, luego de haberse probado su adecuado funcionameinto en protoboard, una segunda versión del circuito impreso, ya incluyendo la ST completa, los buffers, el conector para el IDC, pines para conectar el Display la Memoria, y las borneras para botones y potenciómetros. El diseño y la placa resultante se pueden ver a continuación, estando también [el proyecto disponible para su visualización en EasyEDA]( https://oshwlab.com/mgamberale/project_rwfgvxck): 

![Diseño PCBv2](bitacoras/img/captura_pcb_v2.png)
![Placa v2 en físico](img/fisico_pcb_v2.jpg)

Esta placa propuso sendos inconvenientes, siendo los más destacados: 
- Al descargar esta placa se movió la pista del clock (CLK) hacia arriba accidentalmente, generándoseun cortocircuito entre el output enable (OE), latch (LAT) que no se descurió hasta luego de soldar toda la placa. Se cortaron algunas pistas y se realizaron puentes por la capa inferior, pero estos produjeron cortos accidentales en sendas ocasiones. 
- Las borneras de 3 pines para los potenciómetros se agregaron co la huella incorrecta; teniendo estas una separación de 3.5mm en lugar de las de 5mm vendidas comercialmente. Se soldaron para pruebas los cables directamente a la placa, lo que provocó cortocircuitos y falsos contactos. 
- Sendos puentes eran evitables. 
- Los puentes se hicieron con cable multifilar, así que algunos producían cortos o falsos contactos. 
- La separación entre pistas tenía una separación mínima de 0.3mm, por lo cual algunas pistas tenían cortos. La clearance del plano de masa estaba en 0.6mm, lo que también causó sendos problemas. 
- Por una facilidad de ruteo se había movido el pin del clock del PB13 al PA10. Esto resultó contraproducente por restricciones de la ST, así que se regresó al pin PB13. 

Se realizó entonces una tercera versión final de la placa, corrigiendo estos errores e inconvenientes. Esta se encuentra también dentro del mismo proyecto de EasyEDA que la anterior dada la baja cantidad de cambios al esquemático (únicamente el descripto en el ítem anterior). 

El diseño y la placa resultante se pueden ver a continuación, estando también [el proyecto disponible para su visualización en EasyEDA]( https://oshwlab.com/mgamberale/project_rwfgvxck): 

![Diseño PCBv3](bitacoras/img/captura_pcb_v3.png)
![Placa v3 en físico](img/fisico_pcb_v3.jpg)





[Volver al Índice](#índice)

---

## 3. Sección 3: Configuración del IOC

* **Responsables:** Equipo.

### Configuración de Periféricos y Pines
Explicación de la configuración del IOC (STM32CubeMX), asignación de pines y periféricos (GPIO, etc.).

Los pines utilizados en el ioc son los siguientes (DEBEN TENER LA ETIQUETA DESIGNADA):

```I2C ```

En pinout Configurations a la izquierda, ir a Connectivity > I2C1 > Mode I2C > 
```
I2C1(SCL) | PB6
I2C1(SCA) | PB7
```

```HUB75 ```
Configurar como GPIO_Output con Maximum Output Speed HIGH y en GPIO Output Level LOW, a excepción del OE cuyo Output Level es HIGH. 
```
R1   | PC9
G1   | PC10
BL1  | PC8 
R2   | PC6
G2   | PC7
B2   | PC11

A    | PB10
CLK  |  PB13
LAT  | PA6
OE   | PA9
```

```BOTONES ```

Configurar como GPIO_Input y, particularmente, con GPIO Pull-up.

```
BU1 | PC0
BU2 | PC1
BU3 | PC2
BU4 | PC3
BU5 | PC4
BU6 | PC5

```

```POTENCIÓMETROS ```

Se configura el modo *Analog* del IOC. Se utiliza el ADC1, en particular los canales ```IN0```, ```IN1``` e ```IN4``` del ```ADC1```. 

En _Parameter Settings_ se:
- aumenta el number of conversions a 3
- modifican los Ranks de modo que en el Rank 1 se escuche el Channel 0, Rank 2 al Chanmel 1 y Rank 3 al Channel 4; y el sampling rate se fijó en 239.5 Cycles para los tres canales.

### Clock Configuration

En la Clock Configuration se debe cambiar lo siguiente:

* PLL Source Mux en HSI 
* PLLMUX en x16
* ADC Prescaler en /6 

Adicionalmente, verificar lo marcado en verde  en la imagen a continuación. Se indican tambien las casillas a modificar, en violeta, para hallarlas con facilidad. 

![Configuracion del clock](bitacoras/img/configclk1.png)



[Volver al Índice](#índice)

---

## 4. Sección 4: Documentación de las pantallas (frame buffer y HUB75)

* **Responsables:** [Nombre del compañero / Equipo]

### Gestión de Pantallas
Explicación del protocolo HUB75, la gestión de la memoria (Frame Buffer), tasas de refresco y controladores de pantalla.

[Volver al Índice](#índice)

---

## 5. Sección 5: Documentación de la matriz

* **Responsables:** [Nombre del compañero / Equipo]

### Control de la Matriz
Mapeo de LEDs, lógica de renderizado, coordenadas y funciones para manipular la matriz.

[Volver al Índice](#índice)

---

## 6. Sección 6: Documentación de los módulos I2C

* **Responsable:** Martín León.

Se detalla a continuación el modo en el que se maneja la lógica de la matriz para su posterior uso como salida en la matriz de luces HUB75, y la implementación de las funciones hehcas en el TDA para su uso.

Se consideró para este proyecto, a la matriz como un cuadrado de 32x32. Cada casillero se guarda como una estructura Casillero_t, en la cual hay 3 valores, siendo estos R, G, y B respectivamente. 

`typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b
} Casillero_t`

La matriz entonces, se guarda como una estructura Matriz_t, en la cual se tiene una grilla de datos Casillero_t.

`typedef struct {
    Casillero_t grilla[MATRIZ_FILAS][MATRIZ_COLUMNAS];
} Matriz_t;`

El TDA matriz incluye las siguientes funciones:
` Matriz_t* matrizCrear(void);`

Esta función permite crear una instancia de matriz, haciendo el manejo de memoria dinámica correspondiente. Devuelve un puntero a la matriz recientemente creada, y la inicializa con todos sus casilleros en negro. Si falla en crearla, devuelve NULL

` void      matrizBorrar(Matriz_t* matrizEntrada);`

Esta función elimina una instancia de la matriz, tomando un puntero a la matriz a destruir como argumento de entrada. 

` void      matrizSetCasillero(Matriz_t* matrizEntrada, uint8_t fila, uint8_t col, uint8_t r, uint8_t g, uint8_t b);`

Esta función recibe como argumentos un puntero a la matriz a modificar, la fila y columna a modificar, y el color a poner en dicho casillero. Si se le da una ubicación fuera de los límites de la matriz, da un error a la consola de debugging y no hace nada más. De lo contrario, Pone el color recibido en el casillero indicado.

` void matrizGetCasillero(Matriz_t* matrizEntrada, uint8_t fila, uint8_t col, Casillero_t* salida)`

Esta función recibe como argumentos un puntero a la matriz, la fila y columna deseadas, y un puntero a Casillero_t en el que se devolverá el casillero deseado. Si los punteros no son NULL y la ubicación no está fuera de limites, hace que Casillero_t* salida esté dirigido hacia el casillero pedido.

` void      matrizGetColorCasillero(Matriz_t* matrizEntrada, uint8_t fila, uint8_t col, uint8_t* entradaR, uint8_t* entradaG, uint8_t* entradaB);`

Esta función recibe como argumentos un puntero a la matriz a modificar, la fila y columna deseadas, y 3 punteros entradaR, entradaG, y entradaB en los que se devuelven los valores RGB del casillero pedido.

` void matrizLlenar(Matriz_t* matrizEntrada, uint8_t r, uint8_t g, uint8_t b);`

Esta función recibe como argumentos un puntero a la matriz a modificar, y el color deseado. Se asume que Matriz_t apunta a una matriz válida. La función modifica el color de todos los casilleros en matrizEntrada y lo convierte en el color indicado.


### Comunicación I2C
Se detalla a continuación el planteo y modo de uso de ambos dispositivos I2C utilizados en este proyecto; La memoria EEPROM y el display LCD2004.

Para el display LCD2004, se utilizó una placa conversora PCF8574 cuya dirección I2C es de 0x27. Esta placa convierte señales I2C en señales aptas para ser recibidas por los 8 pines del display. Cuando se envía 1 Byte (8 bits) por el I2C, se envía cada bit a las terminales P0 a P7 del LCD.
De estas, las primeras 4 se usan para opciones y manejo general:

-	P0: Register Select	(En 0 indica comando, en 1 indica datos)
-	P1: Read/Write	(Generalmente en 0 para escribir)
-	P2: Enable 		(Para el clock, detallado mas adelante)
-	P3: Backlight		(En general siempre en 0 para mantenerla prendida)

Las siguientes 4 terminales (P4-P7) se usan para enviar datos o comandos.

Dado que se deben enviar bytes de 8 bits y solo hay 4 terminales donde mandar bits, se emplea un mecanismo para dividir el bit a enviar en partes. Esto se hace con la función

` static void lcdMandarInterno(char data, uint8_t rs)`

Esta función recibe un byte a enviar al LCD, y un rs que indica si el dato es un comando o un dato a imprimir. Divide el byte en 2 partes, y convierte cada parte en los primeros 4 bits de un byte. Luego envía al I2C 4 bytes: 2 para cada fragmento. Se envían 2 bytes por fragmento porque la lectura del LCD es de flanco descendente: Primero se envía el fragmento con el bit enable en 1, y luego se envía con el bit enable en 0.

El resto de funciones del LCD se basan en el uso de lcdMandarInterno:

` void lcdMandarComando(char cmd);`

Envía un dato, el cual será interpretado como comando (Setea rs en 0).

` void lcdMandarDato(char data);`

Envía un dato, el cual será interpretado como dato a imprimir (Setea rs en 1).

` void lcdBorrar(void);`

Limpia la pantalla del LCD, haciendo uso del comando 0x01.

` void lcdSetearCursor(uint8_t col, uint8_t fil);`

Pone el cursor en la fila y columna indicadas, para luego poder imprimir en esa posición. Se presupone que fil y col son valores que no sobrepasan la cantidad máxima de caracteres del LCD, pero no mueve el cursor si no es así.

` void lcdPrint(char *cadena);`

Imprime una cadena, empezando desde la posición del cursor actual. Se presupone que la cadena no sobrepasa el límite máximo de caracteres del LCD.

` void lcdInicializar(I2C_HandleTypeDef *hi2c);`

Inicializa el LCD. Primero lo setea a modo 8 bits 2 veces con el comando 0x30, y luego lo setea a modo 4 bits con el comando 0x32. Esto es sugerido por el fabricante porque el chip no sabe en qué modo inicia al encenderse.
Luego, se pone en modo de 4 líneas con el comando 0x28, y enciende la pantalla y esconde el cursor con el comando 0x0C.
Finalmente, borra lo que esté previamente impreso en el LCD, y setea el cursor de manera que avance a la derecha luego de imprimir cada caracter.

` void lcdBufferearLinea(uint8_t linea, char* cadena);`

Esta es la función que se llama desde la etapa de procesado. Pone  una línea en el buffer, la cual luego puede imprimirse en la etapa de actuadores.

---
Se procede a la documentación de la EEPROM

Para la memoria EEPROM, se utilizó el integrado AT24C256 que permite almacenar datos de manera no volátil. La comunicación se hace mediante I2C, usando direcciones internas de memoria de 16 bits (I2C_MEMADD_SIZE_16BIT). La dirección I2C de la memoria es de 0x50.
Dado que se deben escribir bloques de datos de tamaño variable y la memoria no puede escribir atravesando un límite de página de 64 bytes, los datos a enviar se dividen en fragmentos, manteniéndolos por debajo del espacio en la página actual.

` HAL_StatusTypeDef memEscribir(uint16_t addr, uint8_t *datos, uint16_t largo);`

Recibe la dirección de memoria addr donde se empieza a escribir, el puntero a los datos y la cantidad de bytes a guardar. Calcula cuántos bytes se pueden escribir dentro de la página actual antes de chocar con el límite de 64 bytes y envía ese fragmento mediante HAL_I2C_Mem_Write. Luego espera 5 ms y actualiza las direcciones para repetir el proceso en un bucle while hasta haber enviado todos los datos a la EEPROM.

` HAL_StatusTypeDef memLeer(uint16_t addr, uint8_t *datos, uint16_t largo);`

Lee una cantidad de bytes indicada por largo desde la dirección addr y los guarda en el puntero de salida uint8_t *datos.  La lectura completa se hace en un solo llamado a HAL_I2C_Mem_Read , ya que la operación de lectura en la EEPROM no tiene la restricción de límite de página.

` HAL_StatusTypeDef memEscribirMatriz(uint16_t addr, Matriz_t* matriz) ;`

Guarda la estructura completa de la matriz en la EEPROM a partir de la dirección addr. Hace uso de memEscribir, funcionando como un wrapper para mayor comodidad de uso fuera del TDA.

` HAL_StatusTypeDef memLeerMatriz(uint16_t addr, Matriz_t* matriz);`

 Carga en la estructura matriz los datos previamente guardados en la EEPROM desde la dirección addr. Hace uso de memLeer, funcionando como un wrapper para mayor comodidad de uso fuera del TDA.

[Volver al Índice](#índice)

---

## 7. Sección 7: Documentación de los estados

* **Responsables:** [Nombre del compañero / Equipo]

### Máquina de Estados Finitos (FSM)
Diagrama de estados, transiciones, eventos de entrada y acciones asociadas a cada estado del sistema.

[Volver al Índice](#índice)

---

## 8. Sección 8: Documentación de los botones

* **Responsables:** [Nombre del compañero / Equipo]

### Entradas Digitales e Interrupciones
Manejo de antirrebote (debouncing), interrupciones de GPIO (EXTI), detección de pulsación corta/larga.

[Volver al Índice](#índice)

---

## 9. Sección 9: Documentación del Menú

* **Responsables:** [Nombre del compañero / Equipo]

### Navegación e Interfaz de Usuario
Estructura jerárquica del menú, navegación entre pantallas, renderizado de opciones y selección.

[Volver al Índice](#índice)

---

## 10. Sección 10: Documentación de los potenciómetros

* **Responsables:** [Cloe Gabay]

### Entradas analógicas

Los potenciómetros se utilizan como entradas analógicas para controlar el color RGB utilizado por el sistema. Cada potenciómetro está asociado a uno de los componentes del color:

- Potenciómetro 1 → Rojo (R)
- Potenciómetro 2 → Verde (G)
- Potenciómetro 3 → Azul (B)

Las señales analógicas son adquiridas mediante el ADC1 de la STM32 NÚCLEO F103RB.

### Canales utilizados

Se utilizan tres canales del ADC1:

| Potenciómetro | Canal ADC | Pin |
|---------------|-----------|-----|
| Rojo | ADC1_IN0 | PA0 |
| Verde | ADC1_IN1 | PA1 |
| Azul | ADC1_IN4 | PA4 |

Los tres pines se configuran en modo analógico.

### Configuración del ADC

El ADC1 se configura para realizar una secuencia de tres conversiones.

La configuración utilizada es:

- **ADC:** ADC1
- **Scan Conversion Mode:** Enabled
- **Número de conversiones:** 3
- **Rank 1:** Channel 0
- **Rank 2:** Channel 1
- **Rank 3:** Channel 4
- **Sampling Time:** 239.5 ADC cycles para los tres canales

De esta manera, cada vez que se inicia una secuencia se realizan las siguientes conversiones:

ADC1
 │
 ├── Rank 1 → Channel 0 (PA0) → Rojo
 │
 ├── Rank 2 → Channel 1 (PA1) → Verde
 │
 └── Rank 3 → Channel 4 (PA4) → Azul

### Entradas Analógicas (ADC)
Configuración de canales ADC, escalado de valores, filtrado de ruido (promedios, DMA) y asignación a parámetros del sistema.

Debido a que los potenciómetros utilizan tres canales del ADC1 mediante una secuencia de conversiones, se utiliza DMA (Direct Memory Access) para almacenar automáticamente los resultados de las conversiones en memoria.

En el IOC se configura el DMA asociado al ADC1:

- **DMA:** DMA1
- **Canal:** Channel 1
- **Dirección:** Peripheral to Memory
- **Modo:** Normal
- **Incremento de periférico:** Disabled
- **Incremento de memoria:** Enabled
- **Alineación del periférico:** Half Word (16 bits)
- **Alineación de memoria:** Half Word (16 bits)
- **Prioridad:** High

El incremento de memoria permite que cada conversión de la secuencia sea almacenada en una posición consecutiva del buffer.

La correspondencia utilizada es:

| Conversión | Canal ADC | Posición en buffer | Potenciómetro |
|------------|-----------|--------------------|---------------|
| Rank 1 | ADC1_IN0 | `adc_buffer[0]` | Rojo |
| Rank 2 | ADC1_IN1 | `adc_buffer[1]` | Verde |
| Rank 3 | ADC1_IN4 | `adc_buffer[2]` | Azul |

El DMA se encuentra asociado al ADC mediante `__HAL_LINKDMA()`, de manera que el ADC1 utiliza el canal DMA configurado para transferir automáticamente los resultados de las conversiones hacia el buffer de memoria.

Uso del DMA
Para obtener los resultados de las tres conversiones se utiliza DMA (Direct Memory Access).

El DMA permite transferir los resultados generados por el ADC directamente a una zona de memoria sin que el procesador tenga que realizar una lectura individual de cada conversión.

Se utiliza un buffer de tres posiciones: static uint16_t adc_buffer[3];

La configuración del DMA permite incrementar la dirección de memoria después de cada transferencia. Por lo tanto, los resultados quedan almacenados de la siguiente manera:

adc_buffer[0] → ADC1_IN0 → Rojo
adc_buffer[1] → ADC1_IN1 → Verde
adc_buffer[2] → ADC1_IN4 → Azul

El tamaño de cada elemento es de 16 bits (uint16_t), coincidiendo con la resolución del ADC.

Secuencia de adquisición: la función encargada de obtener los tres valores es 
         static bool leer_3_canales(uint16_t raw[3])

Esta función inicia una secuencia de tres conversiones mediante:
         HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_buffer, 3);

El tercer argumento indica que se deben transferir tres resultados al buffer.

Una vez iniciada la conversión, el programa espera a que el DMA complete la transferencia:

         HAL_DMA_PollForTransfer(
             &hdma_adc1,
             HAL_DMA_FULL_TRANSFER,
             DMA_TIMEOUT_MS
         );

Cuando la transferencia finaliza, los valores almacenados en el buffer se copian al arreglo recibido por la función:

raw[0] = adc_buffer[0];
raw[1] = adc_buffer[1];
raw[2] = adc_buffer[2];


Conversión de ADC a color

El ADC entrega valores de 12 bits, en el rango: 0 ... 4095 y el sistema utiliza valores de color de 8 bits: 0 ... 255.

Para realizar esta conversión se utiliza:

         uint8_t adc_a_color(uint16_t valor_raw)
         {
             return (uint8_t)(valor_raw >> 4);
         }

El desplazamiento de cuatro bits equivale aproximadamente a dividir el valor del ADC por 16:
4095 / 16 ≈ 255 -> Por lo tanto:
         ADC = 0    → color = 0
         ADC = 4095 → color = 255

Filtrado de ruido: para evitar pequeñas variaciones producidas por ruido eléctrico o fluctuaciones naturales de la señal analógica se implementa un filtro por umbral. Se utiliza:

         #define UMBRAL_FILTRO 2

La función:
         
         static uint8_t aplicar_filtro_ruido(
             uint8_t nuevo,
             uint8_t anterior
         )

compara el nuevo valor con el valor anteriormente almacenado, tal que si la diferencia es menor o igual al umbral, se conserva el valor anterior:
         
         |nuevo - anterior| ≤ 2
                 │
                 └── Se conserva el valor anterior

Si la diferencia supera el umbral, se acepta el nuevo valor, evitando qye pequeñas fluctuaciones del ADC produzcan cambios visibles innecesarios en el color mostrado.

Función de escrutinio - actualizar los potenciómetros es:
         void escrutarPotenciometros(void)

Su funcionamiento general es:
         
         escrutarPotenciometros()
                 │
                 ▼
         leer_3_canales()
                 │
                 ▼
         ADC1 + DMA
                 │
                 ├── raw[0] → Rojo
                 ├── raw[1] → Verde
                 └── raw[2] → Azul
                 │
                 ▼
         adc_a_color()
                 │
                 ▼
         Filtro de ruido
                 │
                 ▼
         valor_r
         valor_g
         valor_b

Los valores procesados se mantienen internamente en:
         
         static uint8_t valor_r;
         static uint8_t valor_g;
         static uint8_t valor_b;

Para acceder a ellos desde el resto de la aplicación se utiliza:

         Potenciometros_t obtenerPotenciometros(void)

Esta función devuelve una estructura con los tres componentes:

         Potenciometros_t valores;
         valores.r = valor_r;
         valores.g = valor_g;
         valores.b = valor_b;

De esta forma, el resto del sistema no necesita conocer cómo se realiza la adquisición mediante ADC y DMA.


La lectura de los potenciómetros se realiza dentro de la tarea de escrutinio:
         
         void taskEscrutar(){
         
             botonLeer();
             escrutarPotenciometros();
         }

La arquitectura de la aplicación queda entonces:

         appUpdate()
             │
             ├── hub75Update()
             │
             ├── taskEscrutar()
             │       │
             │       ├── botonLeer()
             │       │
             │       └── escrutarPotenciometros()
             │               │
             │               └── ADC1 + DMA
             │
             ├── taskProcesar()
             │
             └── taskActuar()


La inicialización del ADC y del DMA es realizada por las funciones generadas por STM32CubeMX/HAL.

El módulo de potenciómetros dispone de: void pote_init(void) - aunque actualmente no requiere realizar una inicialización adicional, ya que los periféricos son inicializados durante el arranque del sistema.

Consideraciones sobre DMA
El uso de DMA permite desacoplar la transferencia de los resultados del ADC de la lectura individual realizada por el procesador. 
En esta implementación se utiliza el modo DMA_NORMAL, por lo que cada llamada a HAL_ADC_Start_DMA() realiza una transferencia de tres muestras y finaliza.

La implementación actual espera explícitamente la finalización de la transferencia mediante HAL_DMA_PollForTransfer(). Esto simplifica el control de la adquisición y permite garantizar que los tres valores estén disponibles antes de continuar con el procesamiento.

[Volver al Índice](#índice)

---

## 11. Sección 11: Documentación de los cálculos de tiempos de ejecución

* **Responsables:** [Nombre del compañero / Equipo]

### Rendimiento y Temporización
Mediciones de latencia, tiempos de ciclo, interrupciones periódicas, uso de Timers y análisis de cuellos de botella en la ejecución.

[Volver al Índice](#índice)

```
