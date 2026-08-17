################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app.c \
../Core/Src/boton.c \
../Core/Src/dibujo.c \
../Core/Src/estado.c \
../Core/Src/frame_buffer.c \
../Core/Src/hub75.c \
../Core/Src/lcd.c \
../Core/Src/main.c \
../Core/Src/matriz.c \
../Core/Src/matrizInicio.c \
../Core/Src/mem.c \
../Core/Src/menu_dibujo.c \
../Core/Src/menu_principal.c \
../Core/Src/menu_secuencia.c \
../Core/Src/potenciometro.c \
../Core/Src/secuencia.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/test_wcet_adc.c \
../Core/Src/test_wcet_boton.c \
../Core/Src/test_wcet_hub75.c \
../Core/Src/test_wcet_sistema.c 

OBJS += \
./Core/Src/app.o \
./Core/Src/boton.o \
./Core/Src/dibujo.o \
./Core/Src/estado.o \
./Core/Src/frame_buffer.o \
./Core/Src/hub75.o \
./Core/Src/lcd.o \
./Core/Src/main.o \
./Core/Src/matriz.o \
./Core/Src/matrizInicio.o \
./Core/Src/mem.o \
./Core/Src/menu_dibujo.o \
./Core/Src/menu_principal.o \
./Core/Src/menu_secuencia.o \
./Core/Src/potenciometro.o \
./Core/Src/secuencia.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/test_wcet_adc.o \
./Core/Src/test_wcet_boton.o \
./Core/Src/test_wcet_hub75.o \
./Core/Src/test_wcet_sistema.o 

C_DEPS += \
./Core/Src/app.d \
./Core/Src/boton.d \
./Core/Src/dibujo.d \
./Core/Src/estado.d \
./Core/Src/frame_buffer.d \
./Core/Src/hub75.d \
./Core/Src/lcd.d \
./Core/Src/main.d \
./Core/Src/matriz.d \
./Core/Src/matrizInicio.d \
./Core/Src/mem.d \
./Core/Src/menu_dibujo.d \
./Core/Src/menu_principal.d \
./Core/Src/menu_secuencia.d \
./Core/Src/potenciometro.d \
./Core/Src/secuencia.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/test_wcet_adc.d \
./Core/Src/test_wcet_boton.d \
./Core/Src/test_wcet_hub75.d \
./Core/Src/test_wcet_sistema.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../app/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/app.cyclo ./Core/Src/app.d ./Core/Src/app.o ./Core/Src/app.su ./Core/Src/boton.cyclo ./Core/Src/boton.d ./Core/Src/boton.o ./Core/Src/boton.su ./Core/Src/dibujo.cyclo ./Core/Src/dibujo.d ./Core/Src/dibujo.o ./Core/Src/dibujo.su ./Core/Src/estado.cyclo ./Core/Src/estado.d ./Core/Src/estado.o ./Core/Src/estado.su ./Core/Src/frame_buffer.cyclo ./Core/Src/frame_buffer.d ./Core/Src/frame_buffer.o ./Core/Src/frame_buffer.su ./Core/Src/hub75.cyclo ./Core/Src/hub75.d ./Core/Src/hub75.o ./Core/Src/hub75.su ./Core/Src/lcd.cyclo ./Core/Src/lcd.d ./Core/Src/lcd.o ./Core/Src/lcd.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/matriz.cyclo ./Core/Src/matriz.d ./Core/Src/matriz.o ./Core/Src/matriz.su ./Core/Src/matrizInicio.cyclo ./Core/Src/matrizInicio.d ./Core/Src/matrizInicio.o ./Core/Src/matrizInicio.su ./Core/Src/mem.cyclo ./Core/Src/mem.d ./Core/Src/mem.o ./Core/Src/mem.su ./Core/Src/menu_dibujo.cyclo ./Core/Src/menu_dibujo.d ./Core/Src/menu_dibujo.o ./Core/Src/menu_dibujo.su ./Core/Src/menu_principal.cyclo ./Core/Src/menu_principal.d ./Core/Src/menu_principal.o ./Core/Src/menu_principal.su ./Core/Src/menu_secuencia.cyclo ./Core/Src/menu_secuencia.d ./Core/Src/menu_secuencia.o ./Core/Src/menu_secuencia.su ./Core/Src/potenciometro.cyclo ./Core/Src/potenciometro.d ./Core/Src/potenciometro.o ./Core/Src/potenciometro.su ./Core/Src/secuencia.cyclo ./Core/Src/secuencia.d ./Core/Src/secuencia.o ./Core/Src/secuencia.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/test_wcet_adc.cyclo ./Core/Src/test_wcet_adc.d ./Core/Src/test_wcet_adc.o ./Core/Src/test_wcet_adc.su ./Core/Src/test_wcet_boton.cyclo ./Core/Src/test_wcet_boton.d ./Core/Src/test_wcet_boton.o ./Core/Src/test_wcet_boton.su ./Core/Src/test_wcet_hub75.cyclo ./Core/Src/test_wcet_hub75.d ./Core/Src/test_wcet_hub75.o ./Core/Src/test_wcet_hub75.su ./Core/Src/test_wcet_sistema.cyclo ./Core/Src/test_wcet_sistema.d ./Core/Src/test_wcet_sistema.o ./Core/Src/test_wcet_sistema.su

.PHONY: clean-Core-2f-Src

