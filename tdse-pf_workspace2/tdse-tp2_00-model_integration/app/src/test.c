#include "test.h"
#include "app.h"

#include <stdio.h>
#include <stdint.h>

#include "stm32f1xx.h"

#include "test_wcet_adc.h"
#include "test_wcet_boton.h"
#include "test_wcet_hub75.h"
#include "test_wcet_sistema.h"
#include "test_wcet_lcd.h"


void testearWCET(void){
    testWCETADC();
    testWCETBoton();
    testWCETSistema();
    testWCETLCD();
    testWCETHUB75();
}
