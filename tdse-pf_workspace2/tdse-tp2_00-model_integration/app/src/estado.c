/*
 * estado.c
 *		Created on: Aug 8, 2026
 *      Author: Bauti
*/

#include "estado.h"
#include "boton.h"
#include "menu_principal.h"
#include "menu_dibujo.h"
#include "menu_secuencia.h"
#include "matrizinicio.h"

static EstadoSistema_t estado_sistema_actual = ESTADO_MENU_PRINCIPAL;
static EstadoOperacion_t estado_operacion_actual = ESTADO_SETUP;

void sistemaInit(void) {
    sistemaCambiarOperacion(ESTADO_NORMAL);
}

void sistemaProcesar(void) {
	switch (estado_operacion_actual){
		case ESTADO_SETUP:
			sistemaCambiarOperacion(ESTADO_FALLA);
			break;
		case ESTADO_NORMAL:
			sistemaTickTiempo();
			BotonEvento_t input = botonUltimoEvento();
			sistemaTick(input);
			break;
		case ESTADO_FALLA:
			sistemaError();
			break;
	}
}

void sistemaCambiarOperacion(EstadoOperacion_t nueva_operacion) {
	estado_operacion_actual = nueva_operacion;

	switch (nueva_operacion) {
	case ESTADO_SETUP:
		sistemaCambiarEstado(ESTADO_MENU_PRINCIPAL);
		break;
	case ESTADO_NORMAL:
		sistemaProcesar();
		break;
	case ESTADO_FALLA:
		sistemaError();
		break;
	}
}


void sistemaCambiarEstado(EstadoSistema_t nuevo_estado) {
    estado_sistema_actual = nuevo_estado; //Arranca en MENU_PRINCIPAL

    switch (nuevo_estado) {
        case ESTADO_MENU_PRINCIPAL:
            menuPrincipalEntrar();
            break;
        case ESTADO_CAMBIANDO_BRILLO:
        	menuPrincipalCambiandoBrilloTick(BOTON_NINGUNO);
			break;
        case ESTADO_MENU_DIBUJO:
            menuDibujoEntrar();
            break;
        case ESTADO_GUARDANDO_DIBUJO:
        	menuDibujoGuardando();
        	break;
        case ESTADO_CARGANDO_DIBUJO:
        	menuDibujoCargando();
            break;
        case ESTADO_MENU_SECUENCIA:
            menuSecuenciaEntrar();
            break;
        case ESTADO_CAMBIANDO_PINCEL:
        	menuDibujoCambiarPincelTick(BOTON_NINGUNO);
			break;
        case ESTADO_DIBUJANDO:
        	menuDibujoDibujarTick(BOTON_NINGUNO);
			break;
        case ESTADO_MOSTRANDO_SECUENCIA:
			menuSecuenciaMostrarEntrar();
			break;
        case ESTADO_COMPLETANDO_SECUENCIA:
			menuSecuenciaCompletarTick(BOTON_NINGUNO);
			break;
        case ESTADO_LIMPIAR_SECUENCIA:
        	menuSecuenciaLimpiandoTick(BOTON_NINGUNO);
        	break;
        case ESTADO_LIMPIAR_DIBUJO:
			menuDibujoLimpiandoTick(BOTON_NINGUNO);
			break;
        default:
            break;
    }
}

void sistemaTick(BotonEvento_t input) {
	
    if (input == BOTON_NINGUNO) {
        return;
    }

    switch (estado_sistema_actual) {
        case ESTADO_MENU_PRINCIPAL:
            menuPrincipalTick(input);
            break;
        case ESTADO_CAMBIANDO_BRILLO:
			menuPrincipalCambiandoBrilloTick(input);
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
        case ESTADO_LIMPIAR_DIBUJO:
        	menuDibujoLimpiandoTick(input);
        	break;
        case ESTADO_LIMPIAR_SECUENCIA:
			menuSecuenciaLimpiandoTick(input);
			break;
        case ESTADO_COMPLETANDO_SECUENCIA:
			menuSecuenciaCompletarTick(input);
			break;
		default:
			break;
    }
}

void sistemaTickTiempo(void) {
	switch (estado_sistema_actual){
	case ESTADO_MOSTRANDO_SECUENCIA:
		menuSecuenciaMostrarTick();
		break;
	case ESTADO_COMPLETANDO_SECUENCIA:
		menuSecuenciaCompletarTick(BOTON_NINGUNO);
		break;
	case ESTADO_GUARDANDO_DIBUJO:
		menuDibujoGuardando();
		break;
	case ESTADO_CARGANDO_DIBUJO:
		menuDibujoCargando();
		break;
	default:
		break;
	}
}

void sistemaError() {
	static bool primera_falla_tick = false;
	if(!primera_falla_tick){
		primera_falla_tick = true;
		lcdBufferearLinea(0, "Error en Sistema");
		lcdBufferearLinea(1, "Para reanudar");
		lcdBufferearLinea(2, "el funcionamiento");
		lcdBufferearLinea(3, "reiniciar placa");
	}
	// NVIC_SystemReset(); seria una solución para reiniciar la placa y reanudar el funcionamiento
}

Matriz_t* sistemaObtenerMatrizActiva(void) {
    switch (estado_sistema_actual) {
        case ESTADO_DIBUJANDO:
        case ESTADO_CAMBIANDO_PINCEL:
            return menuDibujoObtenerMatriz();

        case ESTADO_COMPLETANDO_SECUENCIA:
            return menuSecuenciaObtenerMatriz();

        default:
            // Durante los menús principales/secundarios no hay matriz activa
            return NULL;
    }
}
