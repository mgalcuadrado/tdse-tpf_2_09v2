## PINES IOC

Los pines utilizados en el ioc son los siguientes (DEBEN TENER LA ETIQUETA DESIGNADA):

```I2C ```
```
I2C1(SCL) | PB6

I2C1(SCA) | PB7
```

```HUB75 ```
```
R1  | PC6
G1  | PC7
B1  | PC8
R2  | PC9
G2  | PC10
B2  | PC11

A   | PB10
B   | PB12
C   | PB13
D   | PB14 (**)
CLK | PB15
LAT | PA6
OE  | PA8
```

```POTENCIÓMETROS ```
```
POTR | PA0
POTG | PA1
POTB | PA4
```

```BOTONES ```
```
BU1 | PC0
BU2 | PC1
BU3 | PC2
BU4 | PC3
BU5 | PC4
BU6 | PC5

```



Si hubiese que cambiar alguno, los siguientes pines NO se pueden utilizar: 
- ```PA2``` y ```PA3```: Los usan los printfs.
- ```PA5``` LED de usuario.
- ```PA13``` y ```PA14```: Programación y debugging.
- ```PC13```: Botón azul de usuario. 