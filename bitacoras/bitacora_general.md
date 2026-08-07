# Bitácora general

El objetivo de esta bitácora es el de documentar lo realizado y las consideraciones relevantes tenidas en cuenta para la realización del Trabajo Integrador Final de Taller de Sistemas Embebidos (TA137). 

El proyecto consiste en un sistema con pantallas RGB de 32x32 pixeles de modo de controlar por medio de botones y potenciómetros lo mostrado en la misma. Se diseñan dos modos de juego, secuencia (un juego de recordar e imitar una secuencia mostrada) y PixelArt (un juego para ir dibujando en la pantalla variando el color de lo mostrado con potenciómetros). Para navegar por los distintos modos y tener opciones en los mismos se utiliza un menú, mostrado en un Display I2C. Se agrega una memoria para almacenar pixelArts guardados y poder guardar nuevos. 

Se utilizaron dos pantallas RGB de 16x32 pixeles conectadas en cascada (_daisy chain_) y colocadas con la siguiente distribución:

![Distribución Pantallas](img/conexionado_pantallas.png)

# PCB

## Alimentación de la ST
Se trabajó en la alimentación independiente de la ST. Para esto resulta muy importante conocer lo siguiente:
1. Para alimentar externamente como se hace en este trabajo se debe mover el jumper JP5 del modo de alimentación por UART (U5V) al modo de alimentación externa (E5V). 
2. Se conecta luego a GND y a E5V.

Para poder probar la alimentación de la ST con la fuente de 5V 4A se realizó, en una primera versión con el objetivo de probar las pantallas LED y la alimentación de la ST Núcleo, el siguiente PCB:
Nótese que el LD1 cuando se está trabajando con alimentación externa se prenderá y apagará intermitentemente. Esto es adecuado para la utilización de alimentación externa ya que es indicadora de que no se detecta comunicación por UART.
![Diseño PCBv1](img/captura_pcb_v1.png)
![Placa v1 en físico](img/fisico_pcb_v1.jpg)

La primera placa se diseñó en EasyEDA el 16 de julio del 2026 y [el proyecto se puede visualizar en este enlace]( https://oshwlab.com/mgamberale/project_ptvksycq). 

Con esta placa, al ver que esta no funcionaba como era debido, se resolvió agregar los transceptores SN74HCT245 para que las señales recibidas en la pantalla tuviesen un nivel lógico de 5V (como es debido) en lugar de los 3V3 de los pines de salida de la ST NÚCLEO F103RB. 

Se realizó, luego de haberse probado su adecuado funcionameinto en protoboard, una segunda versión del circuito impreso, ya incluyendo la ST completa, los buffers, el conector para el IDC, pines para conectar el Display la Memoria, y las borneras para botones y potenciómetros. El diseño y la placa resultante se pueden ver a continuación, estando también [el proyecto disponible para su visualización en EasyEDA]( https://oshwlab.com/mgamberale/project_rwfgvxck): 

![Diseño PCBv2](img/captura_pcb_v2.png)
![Placa v2 en físico](img/fisico_pcb_v2.jpg)


## Timer
Se utilizó un timer para manejar cíclicamente por interrupción el refresco de las pantallas. Para habilitar el mismo se agregó al main lo siguiente: 

```
/* USER CODE BEGIN 2 */

  /* Application Init */
  //app_init();
  HAL_TIM_Base_Start_IT(&htim3); // PARA ARRANCAR EL TIMER 3
  /* USER CODE END 2 */

...

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    // Si salta el timer 3
    if (htim->Instance == TIM3) {
        hub75Refresh(); // Llamamos al refresh del hub75 y carga una fila del framebuffer
    }
}
/* USER CODE END 4 */
```

La configuración del Timer en el IOC se encuentra detallada en `importante_ioc.md`. 

## Correcto funcionamiento de las pantallas 
Se corroboró que ambas pantallas encienden satisfactoriamente. No se reportan LEDs quemados o rotos. 
![Pantalla LED](img/pantalla_led_encendida.jpg)

## Protocolo HUB75-ish
Las pantallas en rigor tienen una variante del protocolo HUB75, que está deplorablemente documentado en el Internet. El pinout de la entrada de las pantallas como se muestra en la serigrafía de las pantallas es la siguiente: 

![Pinout HUB75 pantalla](img/pinout_hub75.png)

Por medio de pruebas y con especial éxito hallado al secuenciar en función de lo planteado en la imagen a continuación, indicando los tiempos de activación de las distintas señales de control, se identificó que la pantalla efecivamente posee un escaneo 1/2 (direccionamiento con un solo bit `A`).

![Secuencia señales HUB75](http://www.moonbaseotago.com/hub75/wd1.png)

En base a esto se planteo un framebuffer, donde guardar la imagen a mostrar en las pantallas, de 2 filas (`A=0` y `A=1`). Como con cada escritura se cargan tanto los valores para el pixel en la fila _i_ columna _i_ y en la fila _i+8_ columna _i_ (por medio de RGB1 y  RGB2, que reaccionan al mismo pulso de Clock enviado por el pin CLK), el framebuffer resultante es una matriz de 2 filas y 256 columnas. 

## Mappeo de los pixeles en las pantallas
A continuación se puede ver el valor que tienen en las columnas del framebuffer los bloques de misma fila del buffer (pares subsiguientes desde el 16, impares desde el 17) en función de esta distribucion de serpentina.

>Nota importante: por cada fila del frame buffer, primero se escribe toda la pantalla 2 y luego la 1. Además, la pantalla 1 y la pantalla 2 se colocaron una invertida con respecto a la otra por el largo del cable IDC originalmente dado por el proveedor de las pantallas LED.

Se muestran en el orden de las columnas en la matriz (CM) para mayor claridad visual.
Como luego se trabajará con estos valores módulo 4, se indican las filas (FM) 0 y 2,
correspondientes a ese bloque de la pantalla, en el bocetado del patrón de serpentina mostrado a continuación:

#### PANTALLA 2

```
CM	 00	..... 07   08 ..... 15	 16 ..... 23   24 ..... 31
FM
0 || 63 <---- 56 | 47 <---- 40 | 31 <---- 24 | 15 <---- 08 ||
2 || 48 ----> 56 | 32 ----> 56 | 16 ----> 23 | 00 ----> 07 ||
```				

#### PANTALLA 1

```
CM	 00	..... 07   08 ..... 15	 16 ..... 23   24 ..... 31
FM
 2 || 07 <---- 00 | 23 <---- 16 | 39 <---- 32 | 55 <---- 48 ||
 0 || 08 ----> 15 | 24 ----> 31 | 40 ----> 47 | 63 ----> 56 ||
```

## Tests de las pantallas 

#### testBarridoBuffer(void)

Para hallar cómo realizar el mappeo correcto de los datos de la matriz al buffer se utilizó la función `void testBarridoBuffer(void)` que por cada llamado agrega un pixel encendido azul para el RGB1 y blanco para el RGB2 en una posición del framebuffer del 0 al BUFFER_COLUMNAS (256) para filas del 0 al BUFFER_FILAS (2)
#### testBarridoCompleto(Matriz_t * matriz)

Para verificar que el mappeo resultante de este análisis del framebuffer para ubicar las casillas de la matriz a los pixeles de las pantallas se creó la prueba `void testBarridoCompleto(Matriz_t * matriz)`. Esta modifica de a una las casillas de la matriz y actualiza el buffer. 

El resultado esperado es que se enciendan en orden los pixeles de las columnas 0 a MATRIZ_FILAS (32) para cada una de las filas, en orden, de 0 a MATRIZ_COLUMNAS (32). 


#### Líneas a agregar al main para probar estos tests   

```
/* USER CODE BEGIN SysInit */
  frameBufferInit();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  /* Application Init */
  //app_init();
  Matriz_t * matriz = matrizCrear();

  matrizLlenar(matriz, 0,0,0);
  hub75Init();
  HAL_TIM_Base_Start_IT(&htim3); // PARA ARRANCAR EL TIMER 3

  uint32_t ultimo_paso = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

   /*  Application Update */
	  if (HAL_GetTick() - ultimo_paso >= 250){
    //comentar una u otra en función del test a correr
		    //testBarridoCompleto(matriz);
		    //testBarridoBuffer();
		  ultimo_paso = HAL_GetTick();
	 }
    //app_update();
  }
  /* USER CODE END 3 */

```