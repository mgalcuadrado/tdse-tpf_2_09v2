## PINES IOC

Los pines utilizados en el ioc son los siguientes (DEBEN TENER LA ETIQUETA DESIGNADA):

```I2C ```

>I2C1(SCL) | PB6
I2C1(SCA) | PB7

```HUB75 ```

>R1   | PC9
G1   | PC10
BL1  | PC8 //Nota: en la ST de Mechi que tiene fallado este pin BL1 va al PC5
R2   | PC6
G2   | PC7
B2   | PC11

>A   | PB10
CLK | PA10 //Nota: en la ST de Mechi que tiene fallado este pin CLK va al PB13
LAT | PA6
OE  | PA9

```POTENCIÓMETROS ```

>POTR | PA0
POTG | PA1
POTB | PA4


```BOTONES ```

>BU1 | PC0
BU2 | PC1
BU3 | PC2
BU4 | PC3
BU5 | PC4
BU6 | PC5



```TIM3```


>Se usa el Timer3 ara correr el tiempo del refresh de la pantalla.
Prescaler = 71 (como la frecuencia del clock de la ST es de 72MHz, de 0 a 71 pasa 1us por cada pulso del timer).
Counter Period = 7500 (se refresca una fila completa de la pantalla cada 7.5ms, la pantalla completa consta de 2 filas --> refresh completo cada 15ms --> la pantalla está funcionando a aprox 66fps, podría ser más bajo sin problema).
 


## Pasos para configurar el Timer:
>Mode:

Todo en disabled salvo por Clock Source = Internal Clock. NO CLICKEAR NINGUNA CASILLA. 

>Configuration:

>Parameter settings:

*Counter Settings*
- Prescaler = 71
- Counter Mode = Up
- Counter Period = 7500
- CKD = No Division
- auto-reload period = Enable

*Trigger Output (TRGO) parameters*
- MSM = Disabled
- Trigger Event Selection = Reset




>NVIC Settings: 

darle click a la casilla de add :D

### PINES A EVITAR

Si hubiese que cambiar alguno, los siguientes pines NO se pueden utilizar: 
- ```PA2``` y ```PA3```: Los usan los printfs.
- ```PA5``` LED de usuario.
- ```PA13``` y ```PA14```: Programación y debugging.
- ```PC13```: Botón azul de usuario. 


