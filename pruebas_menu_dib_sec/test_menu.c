/*
 * test_menu.c
 *
 * Pruebas de escritorio (no requieren la placa) para la máquina de
 * estados completa: estado.c + menu_principal.c + menu_dibujo.c +
 * menu_secuencia.c + dibujo.c + secuencia.c.
 *
 * La idea central: en vez de leer botones de un GPIO real, le
 * inyectamos eventos BotonEvento_t directo a sistemaTick() y
 * verificamos a dónde navega el sistema con sistemaObtenerEstado().
 * Esto prueba exactamente lo que nos importaba resolver: que nada
 * bloquea, porque cada sistemaTick() vuelve inmediatamente sin
 * quedarse esperando en un while.
*/

#include "test_framework.h"
#include "estado.h"
#include "menu_dibujo.h"
#include "menu_secuencia.h"
#include "boton.h"
#include "frame_buffer.h"
#include "lcd.h"
#include <stdio.h>

// Vuelve siempre al estado inicial y limpia los contadores de los mocks,
// para que cada test sea independiente de los anteriores. Importante:
// los módulos de menú guardan su contexto (Dibujo_t*/Secuencia_t*) en
// variables static, así que hay que salir "prolijo" (por ATRAS) para
// liberarlas antes de arrancar el siguiente test.
static void volver_a_menu_principal_si_hace_falta(void) {
    int intentos = 0;
    while (sistemaObtenerEstado() != ESTADO_MENU_PRINCIPAL && intentos < 10) {
        sistemaTick(BOTON_ATRAS);
        intentos++;
    }
}

static void reset_entorno(void) {
    volver_a_menu_principal_si_hace_falta();
    sistemaInit();
    lcd_mock_reset();
    frameBufferUpdate_llamadas = 0;
}

static void test_estado_inicial(void) {
    TEST_CASE("sistemaInit: arranca en el menu principal");
    reset_entorno();
    ASSERT_EQ_INT(ESTADO_MENU_PRINCIPAL, sistemaObtenerEstado(), "estado inicial es MENU_PRINCIPAL");
}

static void test_boton_ninguno_no_bloquea_ni_reimprime(void) {
    TEST_CASE("sistemaTick(BOTON_NINGUNO): no cambia estado ni reimprime (no bloquea)");
    reset_entorno();

    int lcd_antes = lcdPrint_llamadas;
    sistemaTick(BOTON_NINGUNO);

    ASSERT_EQ_INT(ESTADO_MENU_PRINCIPAL, sistemaObtenerEstado(), "el estado no cambia con BOTON_NINGUNO");
    ASSERT_EQ_INT(lcd_antes, lcdPrint_llamadas, "no se reimprime nada: sistemaTick vuelve al instante");
}

static void test_navegar_a_menu_dibujo_y_volver(void) {
    TEST_CASE("MENU_PRINCIPAL -> MENU_DIBUJO -> DIBUJANDO -> vuelta completa");
    reset_entorno();

    sistemaTick(BOTON_ACEPTAR); // selecciona "Modo Dibujo" (indice 0 por defecto)
    ASSERT_EQ_INT(ESTADO_MENU_DIBUJO, sistemaObtenerEstado(), "ACEPTAR en indice 0 entra a MENU_DIBUJO");
    ASSERT_TRUE(frameBufferUpdate_llamadas >= 1, "al crear el dibujo se refresca el frame buffer");

    sistemaTick(BOTON_ACEPTAR); // selecciona "Dibujar" (indice 0 del sub-menu)
    ASSERT_EQ_INT(ESTADO_DIBUJANDO, sistemaObtenerEstado(), "ACEPTAR en 'Dibujar' entra a ESTADO_DIBUJANDO");

    sistemaTick(BOTON_DERECHA); // mover el cursor no debe crashear ni cambiar de estado
    ASSERT_EQ_INT(ESTADO_DIBUJANDO, sistemaObtenerEstado(), "mover el cursor no cambia de estado");

    sistemaTick(BOTON_ATRAS); // vuelve al menu de dibujo
    ASSERT_EQ_INT(ESTADO_MENU_DIBUJO, sistemaObtenerEstado(), "ATRAS desde DIBUJANDO vuelve a MENU_DIBUJO");

    sistemaTick(BOTON_ATRAS); // vuelve al menu principal (libera el dibujo)
    ASSERT_EQ_INT(ESTADO_MENU_PRINCIPAL, sistemaObtenerEstado(), "ATRAS desde MENU_DIBUJO vuelve a MENU_PRINCIPAL");
}

static void test_navegacion_circular_llega_a_cambiar_pincel(void) {
    TEST_CASE("MENU_DIBUJO: navegacion circular (ARRIBA desde el primer item llega al ultimo)");
    reset_entorno();

    sistemaTick(BOTON_ACEPTAR); // entra a MENU_DIBUJO, indice_seleccion = 0
    ASSERT_EQ_INT(ESTADO_MENU_DIBUJO, sistemaObtenerEstado(), "estamos en MENU_DIBUJO");

    sistemaTick(BOTON_ARRIBA); // desde indice 0, ARRIBA da la vuelta al ultimo (indice 4 = "Cambiar Pincel")
    sistemaTick(BOTON_ACEPTAR);
    ASSERT_EQ_INT(ESTADO_CAMBIANDO_PINCEL, sistemaObtenerEstado(),
                  "ARRIBA en el primer item + ACEPTAR entra directo a CAMBIANDO_PINCEL");

    sistemaTick(BOTON_ARRIBA); // cambia tam_pincel, debe quedarse en el mismo estado
    ASSERT_EQ_INT(ESTADO_CAMBIANDO_PINCEL, sistemaObtenerEstado(), "cambiar el pincel no saca del sub-menu");

    sistemaTick(BOTON_ACEPTAR); // confirma y vuelve
    ASSERT_EQ_INT(ESTADO_MENU_DIBUJO, sistemaObtenerEstado(), "ACEPTAR en CAMBIANDO_PINCEL vuelve a MENU_DIBUJO");

    sistemaTick(BOTON_ATRAS);
    ASSERT_EQ_INT(ESTADO_MENU_PRINCIPAL, sistemaObtenerEstado(), "vuelve prolijo al menu principal");
}

static void test_navegar_a_menu_secuencia_y_completar(void) {
    TEST_CASE("MENU_PRINCIPAL -> MENU_SECUENCIA -> COMPLETANDO_SECUENCIA -> vuelta completa");
    reset_entorno();

    sistemaTick(BOTON_ABAJO); // selecciona "Modo Secuencia" (indice 1)
    sistemaTick(BOTON_ACEPTAR);
    ASSERT_EQ_INT(ESTADO_MENU_SECUENCIA, sistemaObtenerEstado(), "ACEPTAR en indice 1 entra a MENU_SECUENCIA");

    // "Limpiar Secuencia" (indice 1): ejecuta la accion pero se queda en el mismo menu
    sistemaTick(BOTON_ABAJO);
    int frame_antes = frameBufferUpdate_llamadas;
    sistemaTick(BOTON_ACEPTAR);
    ASSERT_EQ_INT(ESTADO_MENU_SECUENCIA, sistemaObtenerEstado(), "'Limpiar Secuencia' no cambia de pantalla");
    ASSERT_TRUE(frameBufferUpdate_llamadas > frame_antes, "'Limpiar Secuencia' refresca el frame buffer");

    // Volver a "Completar Secuencia" (indice 0) y entrar
    sistemaTick(BOTON_ARRIBA);
    sistemaTick(BOTON_ACEPTAR);
    ASSERT_EQ_INT(ESTADO_COMPLETANDO_SECUENCIA, sistemaObtenerEstado(), "'Completar Secuencia' entra al sub-estado");

    sistemaTick(BOTON_DERECHA); // mover cursor dentro de la secuencia, no debe crashear
    sistemaTick(BOTON_ACEPTAR); // marcar/desmarcar una celda
    ASSERT_EQ_INT(ESTADO_COMPLETANDO_SECUENCIA, sistemaObtenerEstado(), "seguimos completando la secuencia");

    sistemaTick(BOTON_ATRAS);
    ASSERT_EQ_INT(ESTADO_MENU_SECUENCIA, sistemaObtenerEstado(), "ATRAS vuelve a MENU_SECUENCIA");

    sistemaTick(BOTON_ATRAS);
    ASSERT_EQ_INT(ESTADO_MENU_PRINCIPAL, sistemaObtenerEstado(), "ATRAS vuelve a MENU_PRINCIPAL");
}

int main(void) {
    printf("=== Pruebas del menu general (maquina de estados) ===\n");

    test_estado_inicial();
    test_boton_ninguno_no_bloquea_ni_reimprime();
    test_navegar_a_menu_dibujo_y_volver();
    test_navegacion_circular_llega_a_cambiar_pincel();
    test_navegar_a_menu_secuencia_y_completar();

    return test_resumen_final();
}
