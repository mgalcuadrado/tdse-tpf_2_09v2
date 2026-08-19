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

* **Responsables:** [Nombre del compañero / Equipo]

### Comunicación I2C
Direcciones I2C de los sensores/módulos, velocidades de bus, registros principales y funciones de lectura/escritura.

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

* **Responsables:** [Nombre del compañero / Equipo]

### Entradas Analógicas (ADC)
Configuración de canales ADC, escalado de valores, filtrado de ruido (promedios, DMA) y asignación a parámetros del sistema.

[Volver al Índice](#índice)

---

## 11. Sección 11: Documentación de los cálculos de tiempos de ejecución

* **Responsables:** [Nombre del compañero / Equipo]

### Rendimiento y Temporización
Mediciones de latencia, tiempos de ciclo, interrupciones periódicas, uso de Timers y análisis de cuellos de botella en la ejecución.

[Volver al Índice](#índice)

```