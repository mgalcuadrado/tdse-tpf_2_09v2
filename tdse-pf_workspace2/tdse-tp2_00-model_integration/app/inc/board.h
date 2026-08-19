/*
 * Copyright (c) 2026 Juan Manuel Cruz <jcruz@fi.uba.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 */

#ifndef BOARD_H_
#define BOARD_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/
#define ZERO				(0)

#define NUCLEO_F103RC		(0)
#define NUCLEO_F303K8		(1)
#define NUCLEO_F401RE		(2)
#define NUCLEO_F446RE		(3)
#define NUCLEO_F413ZH		(4)
#define NUCLEO_F429ZI		(5)
#define NUCLEO_F439ZI		(6)
#define NUCLEO_F767ZI		(7)
#define STM32F407G_DISC1	(8)
#define STM32F429I_DISC1	(9)

#define BOARD (NUCLEO_F103RC)

/* STM32 Nucleo Boards - 32 Pins */
#if (BOARD == NUCLEO_F303K8)

#endif

/* STM32 Nucleo Boards - 64 Pins */
#if ((BOARD == NUCLEO_F103RC) || (BOARD == NUCLEO_F401RE) || (BOARD == NUCLEO_F446RE))

#define BTN_A_PIN		B1_Pin
#define BTN_A_PORT		B1_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_RESET
#define BTN_A_HOVER		GPIO_PIN_SET

#define BTN_PRESSED		BTN_A_PRESSED
#define BTN_HOVER		BTN_A_HOVER

#define LED_A_PIN		LD2_Pin
#define LED_A_PORT		LD2_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

#define LED_ON			LED_A_ON
#define LED_OFF			LED_A_OFF

//definidos en el ioc
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define BU1_Pin GPIO_PIN_0
#define BU1_GPIO_Port GPIOC
#define BU2_Pin GPIO_PIN_1
#define BU2_GPIO_Port GPIOC
#define BU3_Pin GPIO_PIN_2
#define BU3_GPIO_Port GPIOC
#define BU4_Pin GPIO_PIN_3
#define BU4_GPIO_Port GPIOC
#define BU5_Pin GPIO_PIN_4
#define BU5_GPIO_Port GPIOC
#define BU6_Pin GPIO_PIN_5
#define BU6_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LAT_Pin GPIO_PIN_6
#define LAT_GPIO_Port GPIOA
#define A_Pin GPIO_PIN_10
#define A_GPIO_Port GPIOB
#define CLK_Pin GPIO_PIN_13
#define CLK_GPIO_Port GPIOB
#define R2_Pin GPIO_PIN_6
#define R2_GPIO_Port GPIOC
#define G2_Pin GPIO_PIN_7
#define G2_GPIO_Port GPIOC
#define BL1_Pin GPIO_PIN_8
#define BL1_GPIO_Port GPIOC
#define R1_Pin GPIO_PIN_9
#define R1_GPIO_Port GPIOC
#define OE_Pin GPIO_PIN_9
#define OE_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define G1_Pin GPIO_PIN_10
#define G1_GPIO_Port GPIOC
#define B2_Pin GPIO_PIN_11
#define B2_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

#endif

/* STM32 Nucleo Boards - 144 Pins */
#if ((BOARD == NUCLEO_F413ZH) || (BOARD == NUCLEO_F429ZI) || (BOARD == NUCLEO_F439ZI) || (BOARD == NUCLEO_F767ZI))

#define BTN_A_PIN		USER_Btn_Pin
#define BTN_A_PORT		USER_Btn_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_SET
#define BTN_A_HOVER		GPIO_PIN_RESET

#define LED_A_PIN		LD1_Pin
#define LED_A_PORT		LD1_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

#endif

/* STM32 Discovery Kits */
#if ((BOARD == STM32F407G_DISC1) || (BOARD == STM32F429I_DISC1))

#define BTN_A_PIN		B1_Pin
#define BTN_A_PORT		B1_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_SET
#define BTN_A_HOVER		GPIO_PIN_RESET

#define LED_A_PIN		LD3_Pin
#define LED_A_PORT		LD3_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

#endif

/********************** typedef **********************************************/

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* BOARD_H_ */

/********************** end of file ******************************************/
