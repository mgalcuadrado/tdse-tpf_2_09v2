/*
 * test_dibujo.c
 *
 * Pruebas de escritorio (no requieren la placa) para dibujo.c:
 * movimiento del cursor con wrap-around, pintado, reinicio y el
 * ciclo de "cambiar pincel" ya migrado a Tick.
 *
 * Compilar (ver instrucciones al final del archivo o el README).
*/

#include "test_framework.h"
#include "dibujo.h"
#include "boton.h"
#include "matriz.h"
#include "lcd.h"
#include <stdio.h>

static void test_dibujo_crear_y_borrar(void) {
    TEST_CASE("dibujoCrear: estado inicial correcto");

    Dibujo_t* dibujo = dibujoCrear();
    ASSERT_TRUE(dibujo != NULL, "dibujoCrear no devuelve NULL");
    ASSERT_TRUE(dibujo->matriz != NULL, "la matriz interna se crea");
    ASSERT_EQ_INT(0, dibujo->indice_fil, "indice_fil arranca en 0");
    ASSERT_EQ_INT(0, dibujo->indice_col, "indice_col arranca en 0");
    ASSERT_EQ_INT(1, dibujo->tam_pincel, "tam_pincel arranca en 1");

    dibujoBorrar(dibujo);

    // No debe crashear al borrar NULL (defensivo, por si se llama dos veces)
    dibujoBorrar(NULL);
    ASSERT_TRUE(1, "dibujoBorrar(NULL) no crashea");
}

static void test_dibujo_avanzar_wrap_horizontal(void) {
    TEST_CASE("dibujoAvanzar: wrap-around horizontal (tam_pincel=1)");

    Dibujo_t* dibujo = dibujoCrear();

    // Un paso a la derecha desde el borde: avanza normal
    dibujoAvanzar(dibujo, BOTON_DERECHA);
    ASSERT_EQ_INT(1, dibujo->indice_col, "DERECHA suma 1 en el medio de la matriz");

    // Llevar el cursor hasta la última columna y confirmar que el
    // siguiente DERECHA da la vuelta a la columna 0
    dibujo->indice_col = MATRIZ_COLUMNAS - 1;
    dibujoAvanzar(dibujo, BOTON_DERECHA);
    ASSERT_EQ_INT(0, dibujo->indice_col, "DERECHA en el borde vuelve a columna 0");

    // Desde columna 0, IZQUIERDA debe dar la vuelta a la última columna
    dibujoAvanzar(dibujo, BOTON_IZQUIERDA);
    ASSERT_EQ_INT(MATRIZ_COLUMNAS - 1, dibujo->indice_col, "IZQUIERDA en columna 0 vuelve al final");

    dibujoBorrar(dibujo);
}

static void test_dibujo_avanzar_wrap_vertical(void) {
    TEST_CASE("dibujoAvanzar: wrap-around vertical (tam_pincel=1)");

    Dibujo_t* dibujo = dibujoCrear();

    dibujo->indice_fil = MATRIZ_FILAS - 1;
    dibujoAvanzar(dibujo, BOTON_ARRIBA);
    ASSERT_EQ_INT(0, dibujo->indice_fil, "ARRIBA en el borde vuelve a fila 0");

    dibujoAvanzar(dibujo, BOTON_ABAJO);
    ASSERT_EQ_INT(MATRIZ_FILAS - 1, dibujo->indice_fil, "ABAJO en fila 0 vuelve a la última fila");

    dibujoBorrar(dibujo);
}

static void test_dibujo_avanzar_con_pincel_grande(void) {
    TEST_CASE("dibujoAvanzar: los saltos respetan el tamaño de pincel");

    Dibujo_t* dibujo = dibujoCrear();
    dibujo->tam_pincel = 2; // MATRIZ_COLUMNAS/FILAS = 8 -> bloques de a 2

    dibujoAvanzar(dibujo, BOTON_DERECHA);
    ASSERT_EQ_INT(2, dibujo->indice_col, "con pincel=2, DERECHA salta de a 2");

    dibujo->indice_col = MATRIZ_COLUMNAS - 2; // último bloque válido
    dibujoAvanzar(dibujo, BOTON_DERECHA);
    ASSERT_EQ_INT(0, dibujo->indice_col, "con pincel=2, el último bloque vuelve a 0");

    dibujoBorrar(dibujo);
}

static void test_dibujo_pintar_una_celda(void) {
    TEST_CASE("dibujoPintar: pincel 1x1 pinta una sola celda con el color pedido");

    Dibujo_t* dibujo = dibujoCrear();
    dibujo->indice_fil = 3;
    dibujo->indice_col = 4;

    int llamadas_antes = matrizSetCasillero_llamadas;
    dibujoPintar(dibujo, 10, 20, 30);

    ASSERT_EQ_INT(1, matrizSetCasillero_llamadas - llamadas_antes, "se pinta exactamente 1 celda");
    ASSERT_EQ_INT(10, dibujo->matriz->red[3][4], "rojo aplicado correctamente");
    ASSERT_EQ_INT(20, dibujo->matriz->green[3][4], "verde aplicado correctamente");
    ASSERT_EQ_INT(30, dibujo->matriz->blue[3][4], "azul aplicado correctamente");

    dibujoBorrar(dibujo);
}

static void test_dibujo_pintar_con_pincel_grande(void) {
    TEST_CASE("dibujoPintar: pincel 2x2 pinta un bloque de 4 celdas");

    Dibujo_t* dibujo = dibujoCrear();
    dibujo->tam_pincel = 2;
    dibujo->indice_fil = 2;
    dibujo->indice_col = 2;

    int llamadas_antes = matrizSetCasillero_llamadas;
    dibujoPintar(dibujo, 5, 6, 7);

    ASSERT_EQ_INT(4, matrizSetCasillero_llamadas - llamadas_antes, "se pintan 4 celdas (2x2)");
    ASSERT_EQ_INT(5, dibujo->matriz->red[2][2], "celda (2,2) pintada");
    ASSERT_EQ_INT(5, dibujo->matriz->red[3][3], "celda (3,3) pintada");
    ASSERT_EQ_INT(0, dibujo->matriz->red[4][4], "celda fuera del bloque queda intacta");

    dibujoBorrar(dibujo);
}

static void test_dibujo_reiniciar(void) {
    TEST_CASE("dibujoReiniciar: apaga la matriz y vuelve el cursor al origen");

    Dibujo_t* dibujo = dibujoCrear();
    dibujo->indice_fil = 5;
    dibujo->indice_col = 6;
    dibujoPintar(dibujo, 255, 255, 255);

    int llamadas_antes = matrizLlenar_llamadas;
    dibujoReiniciar(dibujo);

    ASSERT_EQ_INT(1, matrizLlenar_llamadas - llamadas_antes, "se llama a matrizLlenar una vez");
    ASSERT_EQ_INT(0, dibujo->indice_fil, "indice_fil vuelve a 0");
    ASSERT_EQ_INT(0, dibujo->indice_col, "indice_col vuelve a 0");
    ASSERT_EQ_INT(0, dibujo->matriz->red[5][6], "la celda que estaba pintada quedó apagada");

    dibujoBorrar(dibujo);
}

static void test_dibujo_cambiar_pincel_tick(void) {
    TEST_CASE("dibujoCambiarPincelTick: duplica/divide y hace wrap 1<->8, sin bloquear");

    Dibujo_t* dibujo = dibujoCrear(); // tam_pincel = 1

    bool termino;

    termino = dibujoCambiarPincelTick(dibujo, BOTON_ARRIBA);
    ASSERT_EQ_INT(2, dibujo->tam_pincel, "ARRIBA duplica el pincel (1->2)");
    ASSERT_TRUE(!termino, "todavia no termino de elegir (no llego ACEPTAR/ATRAS)");

    dibujoCambiarPincelTick(dibujo, BOTON_ARRIBA);
    dibujoCambiarPincelTick(dibujo, BOTON_ARRIBA);
    ASSERT_EQ_INT(8, dibujo->tam_pincel, "tres ARRIBA seguidos: 1->2->4->8");

    dibujoCambiarPincelTick(dibujo, BOTON_ARRIBA);
    ASSERT_EQ_INT(1, dibujo->tam_pincel, "pasar de 8 hace wrap-around a 1");

    termino = dibujoCambiarPincelTick(dibujo, BOTON_ABAJO);
    ASSERT_EQ_INT(8, dibujo->tam_pincel, "bajar desde 1 hace wrap-around a 8");
    ASSERT_TRUE(!termino, "seguimos dentro del sub-menu de pincel");

    termino = dibujoCambiarPincelTick(dibujo, BOTON_ACEPTAR);
    ASSERT_TRUE(termino, "ACEPTAR indica que hay que volver al menu anterior");

    dibujo->tam_pincel = 4; // valor arbitrario para probar que ATRAS tampoco lo modifica
    termino = dibujoCambiarPincelTick(dibujo, BOTON_ATRAS);
    ASSERT_TRUE(termino, "ATRAS tambien indica que hay que volver al menu anterior");
    ASSERT_EQ_INT(4, dibujo->tam_pincel, "ATRAS no modifica el tam_pincel");

    dibujoBorrar(dibujo);
}

int main(void) {
    printf("=== Pruebas del modulo Dibujo ===\n");

    test_dibujo_crear_y_borrar();
    test_dibujo_avanzar_wrap_horizontal();
    test_dibujo_avanzar_wrap_vertical();
    test_dibujo_avanzar_con_pincel_grande();
    test_dibujo_pintar_una_celda();
    test_dibujo_pintar_con_pincel_grande();
    test_dibujo_reiniciar();
    test_dibujo_cambiar_pincel_tick();

    return test_resumen_final();
}
