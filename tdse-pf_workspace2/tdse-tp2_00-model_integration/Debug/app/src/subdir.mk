################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/src/app.c \
../app/src/boton.c \
../app/src/dibujo.c \
../app/src/estado.c \
../app/src/frame_buffer.c \
../app/src/hub75.c \
../app/src/lcd.c \
../app/src/logger.c \
../app/src/matriz.c \
../app/src/matrizInicio.c \
../app/src/mem.c \
../app/src/menu_dibujo.c \
../app/src/menu_principal.c \
../app/src/menu_secuencia.c \
../app/src/potenciometro.c \
../app/src/secuencia.c \
../app/src/test.c \
../app/src/test_wcet_LCD.c \
../app/src/test_wcet_adc.c \
../app/src/test_wcet_boton.c \
../app/src/test_wcet_hub75.c \
../app/src/test_wcet_sistema.c 

OBJS += \
./app/src/app.o \
./app/src/boton.o \
./app/src/dibujo.o \
./app/src/estado.o \
./app/src/frame_buffer.o \
./app/src/hub75.o \
./app/src/lcd.o \
./app/src/logger.o \
./app/src/matriz.o \
./app/src/matrizInicio.o \
./app/src/mem.o \
./app/src/menu_dibujo.o \
./app/src/menu_principal.o \
./app/src/menu_secuencia.o \
./app/src/potenciometro.o \
./app/src/secuencia.o \
./app/src/test.o \
./app/src/test_wcet_LCD.o \
./app/src/test_wcet_adc.o \
./app/src/test_wcet_boton.o \
./app/src/test_wcet_hub75.o \
./app/src/test_wcet_sistema.o 

C_DEPS += \
./app/src/app.d \
./app/src/boton.d \
./app/src/dibujo.d \
./app/src/estado.d \
./app/src/frame_buffer.d \
./app/src/hub75.d \
./app/src/lcd.d \
./app/src/logger.d \
./app/src/matriz.d \
./app/src/matrizInicio.d \
./app/src/mem.d \
./app/src/menu_dibujo.d \
./app/src/menu_principal.d \
./app/src/menu_secuencia.d \
./app/src/potenciometro.d \
./app/src/secuencia.d \
./app/src/test.d \
./app/src/test_wcet_LCD.d \
./app/src/test_wcet_adc.d \
./app/src/test_wcet_boton.d \
./app/src/test_wcet_hub75.d \
./app/src/test_wcet_sistema.d 


# Each subdirectory must supply rules for building sources it contributes
app/src/%.o app/src/%.su app/src/%.cyclo: ../app/src/%.c app/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../app/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-app-2f-src

clean-app-2f-src:
	-$(RM) ./app/src/app.cyclo ./app/src/app.d ./app/src/app.o ./app/src/app.su ./app/src/boton.cyclo ./app/src/boton.d ./app/src/boton.o ./app/src/boton.su ./app/src/dibujo.cyclo ./app/src/dibujo.d ./app/src/dibujo.o ./app/src/dibujo.su ./app/src/estado.cyclo ./app/src/estado.d ./app/src/estado.o ./app/src/estado.su ./app/src/frame_buffer.cyclo ./app/src/frame_buffer.d ./app/src/frame_buffer.o ./app/src/frame_buffer.su ./app/src/hub75.cyclo ./app/src/hub75.d ./app/src/hub75.o ./app/src/hub75.su ./app/src/lcd.cyclo ./app/src/lcd.d ./app/src/lcd.o ./app/src/lcd.su ./app/src/logger.cyclo ./app/src/logger.d ./app/src/logger.o ./app/src/logger.su ./app/src/matriz.cyclo ./app/src/matriz.d ./app/src/matriz.o ./app/src/matriz.su ./app/src/matrizInicio.cyclo ./app/src/matrizInicio.d ./app/src/matrizInicio.o ./app/src/matrizInicio.su ./app/src/mem.cyclo ./app/src/mem.d ./app/src/mem.o ./app/src/mem.su ./app/src/menu_dibujo.cyclo ./app/src/menu_dibujo.d ./app/src/menu_dibujo.o ./app/src/menu_dibujo.su ./app/src/menu_principal.cyclo ./app/src/menu_principal.d ./app/src/menu_principal.o ./app/src/menu_principal.su ./app/src/menu_secuencia.cyclo ./app/src/menu_secuencia.d ./app/src/menu_secuencia.o ./app/src/menu_secuencia.su ./app/src/potenciometro.cyclo ./app/src/potenciometro.d ./app/src/potenciometro.o ./app/src/potenciometro.su ./app/src/secuencia.cyclo ./app/src/secuencia.d ./app/src/secuencia.o ./app/src/secuencia.su ./app/src/test.cyclo ./app/src/test.d ./app/src/test.o ./app/src/test.su ./app/src/test_wcet_LCD.cyclo ./app/src/test_wcet_LCD.d ./app/src/test_wcet_LCD.o ./app/src/test_wcet_LCD.su ./app/src/test_wcet_adc.cyclo ./app/src/test_wcet_adc.d ./app/src/test_wcet_adc.o ./app/src/test_wcet_adc.su ./app/src/test_wcet_boton.cyclo ./app/src/test_wcet_boton.d ./app/src/test_wcet_boton.o ./app/src/test_wcet_boton.su ./app/src/test_wcet_hub75.cyclo ./app/src/test_wcet_hub75.d ./app/src/test_wcet_hub75.o ./app/src/test_wcet_hub75.su ./app/src/test_wcet_sistema.cyclo ./app/src/test_wcet_sistema.d ./app/src/test_wcet_sistema.o ./app/src/test_wcet_sistema.su

.PHONY: clean-app-2f-src

