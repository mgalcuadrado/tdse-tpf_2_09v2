/*
 * estado.c
 *		Created on: Aug 8, 2026
 *      Author: Bauti
*/

#include "estado.h"
#include "menu_principal.h"
#include "menu_dibujo.h"
#include "menu_secuencia.h"

static EstadoSistema_t estado_actual = ESTADO_MENU_PRINCIPAL;

void sistemaCambiarEstado(EstadoSistema_t nuevo_estado) {
    estado_actual = nuevo_estado; //Arranca en MENU_PRINCIPAL

    switch (nuevo_estado) {
        case ESTADO_MENU_PRINCIPAL:
            menuPrincipalEntrar();
            break;
        case ESTADO_MENU_DIBUJO:
            menuDibujoEntrar();
            break;
        case ESTADO_MENU_SECUENCIA:
            menuSecuenciaEntrar();
            break;
        default:
            break;
    }
}

void sistemaInit(void) {
    sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
}

void sistemaTick(BotonEvento_t input) {

    if (input == BOTON_NINGUNO) {
        return;
    }

    switch (estado_actual) {
        case ESTADO_MENU_PRINCIPAL:
            menuPrincipalTick(input);
            break;
        case ESTADO_MENU_DIBUJO:
            menuDibujoTick(input);
            break;
        case ESTADO_DIBUJANDO:
            menuDibujoDibujarTick(input);
            break;
        case ESTADO_CAMBIANDO_PINCEL:
            menuDibujoCambiarPincelTick(input);
            break;
        case ESTADO_MENU_SECUENCIA:
            menuSecuenciaTick(input);
            break;
        case ESTADO_COMPLETANDO_SECUENCIA:
            menuSecuenciaCompletarTick(input);
            break;
    }
}
