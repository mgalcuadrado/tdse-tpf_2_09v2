/*
 * test_framework.h
 *
 * Mini-framework de tests sin dependencias externas (no hace falta
 * instalar ninguna librería, corre con gcc directo). Pensado para
 * poder correr desde PC la lógica de estado/dibujo antes de flashear
 * la placa.
*/

#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>

static int tests_totales = 0;
static int tests_fallidos = 0;
static const char* test_actual = "";

#define TEST_CASE(nombre) \
    do { test_actual = nombre; printf("\n[TEST] %s\n", nombre); } while (0)

#define ASSERT_TRUE(cond, mensaje) \
    do { \
        tests_totales++; \
        if (!(cond)) { \
            tests_fallidos++; \
            printf("  [FALLO] %s (linea %d): %s\n", test_actual, __LINE__, mensaje); \
        } else { \
            printf("  [OK] %s\n", mensaje); \
        } \
    } while (0)

#define ASSERT_EQ_INT(esperado, obtenido, mensaje) \
    do { \
        tests_totales++; \
        long e_ = (long)(esperado); \
        long o_ = (long)(obtenido); \
        if (e_ != o_) { \
            tests_fallidos++; \
            printf("  [FALLO] %s (linea %d): %s (esperado=%ld, obtenido=%ld)\n", \
                   test_actual, __LINE__, mensaje, e_, o_); \
        } else { \
            printf("  [OK] %s (=%ld)\n", mensaje, o_); \
        } \
    } while (0)

static inline int test_resumen_final(void) {
    printf("\n============================================\n");
    printf("Resultado: %d/%d pruebas OK\n", tests_totales - tests_fallidos, tests_totales);
    if (tests_fallidos > 0) {
        printf("%d PRUEBA(S) FALLARON\n", tests_fallidos);
    } else {
        printf("Todas las pruebas pasaron.\n");
    }
    printf("============================================\n");
    return tests_fallidos == 0 ? 0 : 1; // útil como exit code para CI
}

#endif
