/*
 * test_secuencia.c
 *
 * Pruebas de escritorio (no requieren la placa) para secuencia.c:
 * movimiento del cursor con wrap-around en la grilla de DIM_SECUENCIA x
 * DIM_SECUENCIA, inserción de elementos (y su volcado a la matriz),
 * vaciado y detección de secuencia completa.
 *
 * Nota: Secuencia_t es una struct con todos sus campos visibles (no
 * un puntero opaco), así que los tests pueden leer/escribir
 * directamente sec->lista_sec y sec->indice_sec cuando hace falta
 * -- por ejemplo, para simular que el usuario ya completó la
 * secuencia objetivo, que se genera al azar en secuenciaCrear().
*/

#include "test_framework.h"
#include "secuencia.h"
#include "matriz.h"
#include "boton.h"
#include <stdio.h>

static void test_secuencia_crear(void) {
    TEST_CASE("secuenciaCrear: estado inicial correcto");

    Secuencia_t* sec = secuenciaCrear();
    ASSERT_TRUE(sec != NULL, "secuenciaCrear no devuelve NULL");
    ASSERT_EQ_INT(0, sec->indice_sec, "indice_sec arranca en 0");

    bool lista_usuario_vacia = true;
    for (int i = 0; i < CANT_ELEMENTOS; i++) {
        if (sec->lista_sec[1][i] != 0) {
            lista_usuario_vacia = false;
        }
    }
    ASSERT_TRUE(lista_usuario_vacia, "la lista del usuario arranca en 0 (secuenciaVaciar interno)");

    bool objetivo_valido = true;
    for (int i = 0; i < CANT_ELEMENTOS; i++) {
        uint8_t v = sec->lista_sec[0][i];
        if (v != 0 && v != 255) {
            objetivo_valido = false;
        }
    }
    ASSERT_TRUE(objetivo_valido, "la secuencia objetivo solo tiene valores 0 o 255");

    secuenciaBorrar(sec);
    secuenciaBorrar(NULL); // no debe crashear
    ASSERT_TRUE(1, "secuenciaBorrar(NULL) no crashea");
}

static void test_secuencia_avanzar_horizontal(void) {
    TEST_CASE("secuenciaAvanzar: wrap-around horizontal en la grilla DIM_SECUENCIA");

    Secuencia_t* sec = secuenciaCrear();

    sec->indice_sec = 0;
    secuenciaAvanzar(sec, BOTON_DERECHA);
    ASSERT_EQ_INT(1, sec->indice_sec, "DERECHA suma 1 dentro de la misma fila");

    sec->indice_sec = DIM_SECUENCIA - 1; // última columna de la fila 0
    secuenciaAvanzar(sec, BOTON_DERECHA);
    ASSERT_EQ_INT(0, sec->indice_sec, "DERECHA en el borde vuelve al principio de la fila");

    secuenciaAvanzar(sec, BOTON_IZQUIERDA);
    ASSERT_EQ_INT(DIM_SECUENCIA - 1, sec->indice_sec, "IZQUIERDA en el borde vuelve al final de la fila");

    secuenciaBorrar(sec);
}

static void test_secuencia_avanzar_vertical(void) {
    TEST_CASE("secuenciaAvanzar: wrap-around vertical en la grilla DIM_SECUENCIA");

    Secuencia_t* sec = secuenciaCrear();

    sec->indice_sec = 0;
    secuenciaAvanzar(sec, BOTON_ABAJO);
    ASSERT_EQ_INT(DIM_SECUENCIA, sec->indice_sec, "ABAJO desde la primera fila baja una fila");

    sec->indice_sec = DIM_SECUENCIA * (DIM_SECUENCIA - 1); // primera columna, última fila
    secuenciaAvanzar(sec, BOTON_ABAJO);
    ASSERT_EQ_INT(0, sec->indice_sec, "ABAJO en la última fila da la vuelta a la primera");

    secuenciaAvanzar(sec, BOTON_ARRIBA);
    ASSERT_EQ_INT(DIM_SECUENCIA * (DIM_SECUENCIA - 1), sec->indice_sec,
                  "ARRIBA en la primera fila da la vuelta a la última");

    secuenciaBorrar(sec);
}

static void test_secuencia_avanzar_indice_fuera_de_rango(void) {
    TEST_CASE("secuenciaAvanzar: guarda defensiva si indice_sec quedo fuera de rango");

    Secuencia_t* sec = secuenciaCrear();
    sec->indice_sec = CANT_ELEMENTOS; // fuera de rango a propósito

    secuenciaAvanzar(sec, BOTON_DERECHA);
    ASSERT_EQ_INT(CANT_ELEMENTOS, sec->indice_sec, "con indice fuera de rango, avanzar no lo modifica");

    secuenciaBorrar(sec);
}

static void test_secuencia_insertar_elemento(void) {
    TEST_CASE("secuenciaInsertarElemento: pinta el bloque correcto en la matriz");

    Secuencia_t* sec = secuenciaCrear();
    Matriz_t* matriz = matrizCrear();

    int llamadas_antes = matrizSetCasillero_llamadas;
    secuenciaInsertarElemento(sec, 255, matriz, 0, 0); // primer bloque, fil=0 col=0

    ASSERT_EQ_INT(TAM_PINCEL_SECUENCIA * TAM_PINCEL_SECUENCIA,
                  matrizSetCasillero_llamadas - llamadas_antes,
                  "se pintan TAM_PINCEL_SECUENCIA x TAM_PINCEL_SECUENCIA celdas");
    ASSERT_EQ_INT(255, matriz->blue[0][0], "canal azul pintado con el color insertado");
    ASSERT_EQ_INT(0, matriz->red[0][0], "canal rojo queda en 0 (la secuencia solo pinta azul)");
    ASSERT_EQ_INT(255, sec->lista_sec[1][0], "la posicion 0 de la lista del usuario queda con el color");

    // Un segundo bloque (fila 2, columna 2) debe caer en otra posición de la lista
    secuenciaInsertarElemento(sec, 255, matriz, 2, 2);
    int pos_esperada = (2 / TAM_PINCEL_SECUENCIA) + (2 / TAM_PINCEL_SECUENCIA) * DIM_SECUENCIA;
    ASSERT_EQ_INT(255, sec->lista_sec[1][pos_esperada], "el segundo bloque cae en la posicion esperada de la lista");

    matrizBorrar(matriz);
    secuenciaBorrar(sec);
}

static void test_secuencia_insertar_elemento_fuera_de_rango(void) {
    TEST_CASE("secuenciaInsertarElemento: no pinta nada si fil/col estan fuera de la matriz");

    Secuencia_t* sec = secuenciaCrear();
    Matriz_t* matriz = matrizCrear();

    int llamadas_antes = matrizSetCasillero_llamadas;
    secuenciaInsertarElemento(sec, 255, matriz, MATRIZ_FILAS, 0); // fila invalida

    ASSERT_EQ_INT(llamadas_antes, matrizSetCasillero_llamadas, "no se pinta ninguna celda con fila fuera de rango");

    matrizBorrar(matriz);
    secuenciaBorrar(sec);
}

static void test_secuencia_elemento_actual(void) {
    TEST_CASE("secuenciaElementoActual: devuelve el valor de la posicion actual");

    Secuencia_t* sec = secuenciaCrear();
    Matriz_t* matriz = matrizCrear();

    sec->indice_sec = 0;
    ASSERT_EQ_INT(0, secuenciaElementoActual(sec), "arranca apagado (0) en la posicion 0");

    secuenciaInsertarElemento(sec, 255, matriz, 0, 0);
    ASSERT_EQ_INT(255, secuenciaElementoActual(sec), "despues de insertar, refleja el color insertado");

    matrizBorrar(matriz);
    secuenciaBorrar(sec);
}

static void test_secuencia_vaciar(void) {
    TEST_CASE("secuenciaVaciar: apaga toda la lista del usuario");

    Secuencia_t* sec = secuenciaCrear();
    Matriz_t* matriz = matrizCrear();

    secuenciaInsertarElemento(sec, 255, matriz, 0, 0);
    secuenciaInsertarElemento(sec, 255, matriz, 4, 4);

    secuenciaVaciar(sec);

    bool todo_apagado = true;
    for (int i = 0; i < CANT_ELEMENTOS; i++) {
        if (sec->lista_sec[1][i] != 0) {
            todo_apagado = false;
        }
    }
    ASSERT_TRUE(todo_apagado, "despues de vaciar, toda la lista del usuario esta en 0");

    matrizBorrar(matriz);
    secuenciaBorrar(sec);
}

static void test_secuencia_completa(void) {
    TEST_CASE("secuenciaCompleta: true solo cuando la lista del usuario iguala al objetivo");

    Secuencia_t* sec = secuenciaCrear();

    ASSERT_TRUE(!secuenciaCompleta(sec), "recien creada, todavia no esta completa (salvo objetivo todo en 0)");

    // Copiamos el objetivo (generado al azar) a la lista del usuario
    for (int i = 0; i < CANT_ELEMENTOS; i++) {
        sec->lista_sec[1][i] = sec->lista_sec[0][i];
    }
    ASSERT_TRUE(secuenciaCompleta(sec), "copiar el objetivo a la lista del usuario la marca como completa");

    // Alteramos un solo elemento para que deje de coincidir
    sec->lista_sec[1][0] = (sec->lista_sec[0][0] == 0) ? 255 : 0;
    ASSERT_TRUE(!secuenciaCompleta(sec), "un solo elemento distinto alcanza para que no este completa");

    secuenciaBorrar(sec);
}

int main(void) {
    printf("=== Pruebas del modulo Secuencia ===\n");

    test_secuencia_crear();
    test_secuencia_avanzar_horizontal();
    test_secuencia_avanzar_vertical();
    test_secuencia_avanzar_indice_fuera_de_rango();
    test_secuencia_insertar_elemento();
    test_secuencia_insertar_elemento_fuera_de_rango();
    test_secuencia_elemento_actual();
    test_secuencia_vaciar();
    test_secuencia_completa();

    return test_resumen_final();
}
