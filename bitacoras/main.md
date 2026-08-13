# Bitácora de los Estados - estado.h/.c {#bitacora-del-menuxfa}

Se implementaron los siguientes estados en un archivo $estado.h$ para
poder acceder al menú del juego:


    typedef enum {
        ESTADO_MENU_PRINCIPAL = 0,
        ESTADO_CAMBIANDO_BRILLO,
        ESTADO_MENU_DIBUJO,
        ESTADO_LIMPIAR_DIBUJO,
        ESTADO_DIBUJANDO,
        ESTADO_CAMBIANDO_PINCEL,
        ESTADO_MENU_SECUENCIA,
        ESTADO_COMPLETANDO_SECUENCIA,
        ESTADO_MOSTRANDO_SECUENCIA,
        ESTADO_LIMPIAR_SECUENCIA
    } EstadoSistema_t;

Se diseñaron dichos estados de esta forma para poder utilizar un switch
y que, en cada ciclo de la placa, se pueda ir directamente al último
menú en el que quedó el usuario.

    static EstadoSistema_t estado_actual = ESTADO_MENU_PRINCIPAL;


    - void sistemaInit(void);

Se utiliza antes de la sección $while(1)$ en main.c. Inicia la interfaz
del menú en general, cambiando el estado al $ESTADO\_MENU\_PRINCIPAL$ y
entra al menú principal.


    - void sistemaTick(BotonEvento_t input);

Esta función se utiliza para interactuar con el menú a partir de
interrupciones, siendo en particular el input que resulta ser la lectura
de alguno de los botones.


    - void sistemaCambiarEstado(EstadoSistema_t nuevo_estado);

Esta función se diseñó con el propósito de variar el estado_actual a
partir de la interacción del usuario con el menú y a partir de dicho
cambio, entrar al nuevo.


    - void sistemaTickTiempo(void);

El propósito de esta función es similar a
$void sistemaTick(BotonEvento_t input);$, pero con el propósito
específico de utilizarse en las secciones del menú que no requieran
interacción con el usuario y deban esperarse un tiempo determinado.
Estos son los casos en los que se muestra la secuencia a completar y en
los que el usuario completa la secuencia.

# Bitácora de la Lectura de los Botones - boton.h/.c {#bitacora-del-menuxfa}

    typedef enum  {
        BOTON_NINGUNO = 0,
        BOTON_ARRIBA,
        BOTON_ABAJO,
        BOTON_IZQUIERDA,
        BOTON_DERECHA,
        BOTON_ACEPTAR,
        BOTON_ATRAS
    }BotonEvento_t;

    // Tiempo mínimo para captar una respuesta
    #define DEBOUNCE_MS 50

Nuevamente, como los estados, se diseñó la lectura del botón de tal
forma que se pudiera comparar utilizando un switch. Además, se define un
parámetro DEBOUNCE MS para filtrar respuestas falsas o ruido.

$BotonEvento_t botonLeer(void);$

Esta única función sirve para detectar el botón presionado y devolver la
lectura a partir del typedef definido previamente. Algo para destacar,
es la siguiente definición:

        GPIO_PinState actual_Arriba = HAL_GPIO_ReadPin(BU1_GPIO_Port, BU1_Pin);
        GPIO_PinState actual_Abajo = HAL_GPIO_ReadPin(BU2_GPIO_Port, BU2_Pin);
        GPIO_PinState actual_Izquierda = HAL_GPIO_ReadPin(BU3_GPIO_Port, BU3_Pin);
        GPIO_PinState actual_Derecha = HAL_GPIO_ReadPin(BU4_GPIO_Port, BU4_Pin);
        GPIO_PinState actual_Aceptar = HAL_GPIO_ReadPin(BU5_GPIO_Port, BU5_Pin);
        GPIO_PinState actual_Atras = HAL_GPIO_ReadPin(BU6_GPIO_Port, BU6_Pin);

Estas definiciones indican qué acciones resultan de dichos botones en el
menú.

# Bitácora del Menú Implementado {#bitacora-del-menuxfa}

## Planteo General {#planteo-general-del-menuxfa-del-modo-pixel-art}

Se detalla a continuación el formato diseñado para la interfaz del Juego
RGB utilizado.

![Esquema general del
menu.](./img/menu_diagrama.png){#fig:diagrama_general_sistema
width="70%"}

Los 3 menús comparten dos variables:


    static char seleccion
    static int indice_seleccion

Donde ambas están para describir el comportamiento del menú, dónde está
parado el usuario respecto al cursor y qué opciones hay allí. En
particular, los menús utilizan los códigos lcd.h/.c para presentar en el
display el menú y la interacción con el usuario.

Además, los 3 menús con ciertas opciones específicas tienen 4 botones
para interactuar. Para subir, bajar, aceptar o volver al menú anterior.

## Menú Principal - menu_principal.h/.c {#planteo-general-del-menuxfa-del-modo-pixel-art}

Para el diseño del menú principal se declaran las siguientes variables:


    static char seleccion[4] = {'*', ' ',' '};
    static int indice_seleccion = 0;
    static int brillo = 25;

Se define una variable de selección para mostrar al usuario en el
display donde se encuentra en el menú, indicada por el asterisco. La
variable $indice\_seleccion$ indica la opción en la que se encuentra el
usuario. La variable brillo se utiliza para regular el brillo que
presenta la matriz de LED's, que se encuentra en las opciones del
$menu\_ principal$.

Las funciones utilizadas para el armado de esta sección son las
siguientes:

    - void menuPrincipalEntrar(void);

Esta función, como las semejantes tipo menuSecuenciaEntrar() y
menuDibujoEntrar(), se utiliza para inicializar las variables que se van
a utilizar en dicho menú.

    - void menuPrincipalTick(BotonEvento_t input);

Esta función define la interacción del usuario con el menú principal
utilizando los botones. En particular, en el menú principal no se puede
volver más atrás dado que es la base de la interfaz.

    - void menuPrincipalPrint(char seleccion[3], int indice_seleccion);

Esta función escribe en el display, utilizando las funciones lcd.h/.c,
el menú principal y la posición del cursor.

## Menú Dibujo - menu_dibujo.h/.c y dibujo.h/.c {#planteo-general-del-menuxfa-del-modo-pixel-art}

    static Dibujo_t* dibujo_actual = NULL;
    static char seleccion[6] = {'*', ' ', ' ', ' ', ' '}; // 5 opciones + \n
    static int indice_seleccion = 0;

La única diferencia respecto al menú principal es la aparición de un
Dibujo_t. Este TDA sirve para compactar los datos necesarios para el
funcionamiento de este modo:

    typedef struct  {
        Matriz_t* matriz;
        uint8_t indice_fil;
        uint8_t indice_col;
        uint8_t tam_pincel;
        Casillero_t* color_anterior;
    } Dibujo_t;

En dibujo_t, se encuentran indice_fil e indice_col para indicar la
posición en la que se encuentra el usuario parado en la matriz de LED's.
El tam_pincel indica el tamaño en el que se va a dibujar de un mismo
color en la matriz. La variable color_anterior define el color que se
encontraba antes de que el usuario se parara en tal casilla. Esto
permite implementar un cursor para que el usuario sepa dónde está parado
en la matriz.

    typedef struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    } Casillero_t;

    #define MATRIZ_FILAS      32
    #define MATRIZ_COLUMNAS   32
    typedef struct {
        Casillero_t grilla[MATRIZ_FILAS][MATRIZ_COLUMNAS];
    } Matriz_t;

    - void menuDibujoDibujarTick(BotonEvento_t input);

Esta función define la interacción con el usuario cuando elige la opción
de dibujar. El usuario puede moverse en 4 direcciones en la matriz;
utiliza el botón de aceptar para dibujar y el botón atrás para volver al
menú de dibujo.

    - void menuDibujoCambiarPincelTick(BotonEvento_t input);

Utilizando esta función, el usuario llega al submenú para editar el
tamaño del pincel con el que desea pintar. Puede variar en 1x1, 2x2, 4x4
y 8x8.

    - void menuDibujoDibujarPrint(BotonEvento_t input);

Esta función muestra en el display lo que el usuario está dibujando, la
última dirección en la que se movió el usuario y con qué botón vuelve al
menú anterior.

    - void menuDibujoLimpiandoTick(BotonEvento_t input);

El propósito de esta función es verificar con el usuario si desea
eliminar el dibujo que estaba realizando hasta ahora en la matriz.

## Menú Secuencia - menu_secuencia.h/.c y secuencia.h/.c {#menu_secuencia}

    #define CANT_ELEMENTOS 16 // 32 x 32 dado un pincel de 8 x 8 = 4 x 4 casilleros
    #define TAM_PINCEL_SECUENCIA 8
    #define DIM_SECUENCIA 4 // 4 x 4 la matriz de secuencia

Se aclaran estos defines para una mayor comprensión del código en la
sección de secuencia. En particular se fijó el valor del tamaño del
pincel a 8 para tener secciones de matrices del tipo 8 x 8, obteniendo
16 secciones ya que la matriz es de 32 x 32.

    typedef struct Secuencia_t {
        uint8_t lista_sec[2][CANT_ELEMENTOS];
        uint8_t indice_sec;
    } Secuencia_t;

Este TDA define dos listas compuestas por valores de 255 o 0, donde la
lista_sec\[0\] es una secuencia generada aleatoriamente que el usuario
tiene que completar para ganar el juego. La lista_sec\[1\] es la lista
de valores que va ir rellenando el usuario para ganar.

    - void menuSecuenciaMostrarEntrar(void);

Esta función inicializa la secuencia que luego el usuario debe completar
en orden.

    - void menuSecuenciaMostrarTick(void);

Esta función permite continuar el desarrollo de la demostración de la
secuencia a completar, permitiendo que cada sección, sea de color negro
o prendida, se visualice por 3 segundos aproximadamente.

    - void menuSecuenciaCompletarTick(BotonEvento_t input);

Esta función permite al usuario completar la secuencia que debe
desarrollar para poder ganar. Nuevamente, como en dibujo, puede moverse
en 4 direcciones, aceptar para pintar en la casilla en la que está
parado y volver atrás usando el botón para atrás.

    - void menuSecuenciaCompletandoPrint(BotonEvento_t input);

Como en $void menuDibujoDibujarPrint(BotonEvento_t input);$, el usuario
puede observar en el display que se encuentra jugando la secuencia, cuál
fue la última dirección a la que se movió y qué botón debe presionar
para salir.

    - void menuSecuenciaLimpiandoTick(BotonEvento_t input);

Esta función permite al usuario asegurarse si desea limpiar la
secuencia, reduciendo la posibilidad de borrar la matriz y la secuencia
por accidente.
