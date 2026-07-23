#include "hub75.c"
#define BUFFER_COLUMNA 128
uint32_t casilla_r1 = R1_Pin | ((G2_Pin | B2_Pin | R2_Pin | G1_Pin | B1_Pin)<<16);
uint32_t casilla_negro =  ((R1_Pin | G2_Pin | B2_Pin | R2_Pin | G1_Pin | B1_Pin)<<16);

static int contador = 0;
static int fila_actual = 0;

void hub75Test1(void){
     GPIOA->BSRR = OE_Pin;
  for (int columna = 0; columna < BUFFER_COLUMNA; columna++)
        if (columna == contador) GPIOC->BSRR= casilla_r1;
        else GPIOC->BSRR= casilla_negro;
        GPIOB->BSRR=CLK_Pin;
        _NOP();
        GPIOB->BSRR=(CLK_Pin<<16);
   }
   GPIOA->BSRR=LAT_Pin;
      _NOP();
        GPIOA->BSRR=(LAT_Pin<<16);
if (fila_actual) GPIOB->BSRR=A_Pin;
else GPIOB->BSRR=(A_Pin<<16);
//fila_actual++ // comento esto para ver de a una fila primero
GPIOA->BSRR = (OE_Pin<<16);


}


