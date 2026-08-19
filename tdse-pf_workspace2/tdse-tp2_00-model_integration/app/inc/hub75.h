/*
 * hub75.h
 *
 *  Created on: Jul 18, 2026
 *      Author: Mechi
 */

#ifndef INC_HUB75_H_
#define INC_HUB75_H_
#include "main.h"
#include "frame_buffer.h"
#include "stdint.h"


// hub75Init inicializa los valores del hub75
 void hub75Init(void);

 //hub75SetBrightness varía la intensidad de brillo de las pantallas.
 //No implementada todavia al no ser parte del MVP
 void hub75SetBrightness(int brillo);

 //hub75Update actualiza la pantalla
 void hub75Update(void);

#endif
