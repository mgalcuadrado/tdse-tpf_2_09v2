# Bitácora general

## Alimentación de la ST
Se trabajó en la alimentación independiente de la ST. Para esto resulta muy importante conocer lo siguiente:
1. Para alimentar externamente como se hace en este trabajo se debe mover el jumper JP5 del modo de alimentación por UART (U5V) al modo de alimentación externa (E5V). 
2. Se conecta luego a GND y a E5V.

Para poder probar la alimentación de la ST con la fuente de 5V 4A se realizó, en una primera versión con el objetivo de probar las pantallas LED y la alimentación de la ST Núcleo, el siguiente PCB:

![Diseño PCBv1](img/captura_pcb_v1.png)
![Placa v1 en físico](img/armado_pcb_v1.jpg)

La placa se diseñó en EasyEDA el 16 de julio del 2026 y [el proyecto se puede visualizar en este enlace]( https://oshwlab.com/mgamberale/project_ptvksycq). 

Nótese que el LD1 cuando se está trabajando con alimentación externa se prenderá y apagará intermitentemente. Esto es adecuado para la utilización de alimentación externa ya que es indicadora de que no se detecta comunicación por UART.

## IDCs DE LAS PANTALLAS LED PROVISTOS POR EL FABRICANTE
Nótese que en los IDCs provistos por el fabricante de las pantallas LED uno de los dos IDCs tiene los cables insertados en sentido inverso, lo que implica un funcionamiento espejado. Esto no se notó previo a la fabricación del PCB "TdSEv1", pero sí se tomará en cuenta para próximas iteraciones. 

## Correcto funcionamiento de las pantallas 
Se corroboró que ambas pantallas encienden satisfactoriamente. No se reportan LEDs quemados o rotos. 
![Pantalla LED](img/pantalla_led_encendida.jpg)
