###### 15/07/2026
- 15/07/2026 19-21hs: reunión de equipo. Análisis del proyecto, planteos del menú pixel art, división de tareas, replanteos de temas a discutir. Archivo(s) modificado(s): `contrato_general.txt`. @todos
###### 16/07/2026
- 16/07/2026 9-11:30hs: Análisis de requerimientos de corriente de las pantallas LED y del resto de los componentes del TP para realizar el diseño del PCB "TdSEv1" para pruebas de alimentación y de las pantallas LED. @Mechi
- 16/07/2026 16-17:30hs: Planchado, fabricación y soldadura de los componentes de la placa "TdSEv1." @Mechi
- 16/07/2026 19:30-21hs: Elaboración de documentación inicial del proyecto. Prueba de alimentación externa para la ST con la placa "TdSEv1". Archivo(s) modificado(s): `bitacora_general.md`, `bitacora_menu.md`, `logs.md`, `img/captura_menu_pixelart_v1.png`, `img/captura_pcb_v1.png`. @Mechi
-18/07/2026 16-22pm: Investigación y desarrollo de la lógica inicial de encendido de las pantallas. Se probó prender las pantallas individualmente de rojo y blanco modificando los colores del framebuffer inicial, obteniéndose resultados favorables.
- 18/07/2026 22:30-00:45hs: Se empezó a probar combinar distintos colores, encontrándose inconvenientes de overflow y de guardado del buffer. Sigue habiendo inconvenientes con la posición individual, quizás por un incorrecto conexionado o falso contacto debido al injerto con duponts que se armó para conectar; o por una incorrecta lógica de guardado. Sí parecen funcionar mejor las filas, guárdandose los elementos al menos en las filas correctas a pesar de que estén en columnas incorrectas. Se hicieron combinaciones de rojo, blanco y azul; incluso combinándose rojo y azul para formar violeta. Los colores se distinguen satisfactoriamente, pero todavía no se pueden realizar más combinaciones que las clásicas (Rojo, Azul, Verde, Blanco, Negro (Apagado), Rojo + Azul, Rojo + Verde, Azul+Verde). @Mechi

19/07/2026 13-14hs: Armado de conexionado a 220v para la fuente switching. @Mechi
19/07/2026 20-23hs: Pruebas de la pantalla. Agregado de timers, reducción de código bloqueante (la funcion ahora imrime de a una fila... mal ero de a una). @Mechi
