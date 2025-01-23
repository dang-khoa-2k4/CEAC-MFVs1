################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/CEAC_BLE.c \
../Core/Src/IR.c \
../Core/Src/PID.c \
../Core/Src/PWMcontrol.c \
../Core/Src/average_filter.c \
../Core/Src/encoder_ENCTIM.c \
../Core/Src/encoder_IT.c \
../Core/Src/global.c \
../Core/Src/input_reading.c \
../Core/Src/led_display.c \
../Core/Src/main.c \
../Core/Src/scheduler.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/ultraSonic.c 

OBJS += \
./Core/Src/CEAC_BLE.o \
./Core/Src/IR.o \
./Core/Src/PID.o \
./Core/Src/PWMcontrol.o \
./Core/Src/average_filter.o \
./Core/Src/encoder_ENCTIM.o \
./Core/Src/encoder_IT.o \
./Core/Src/global.o \
./Core/Src/input_reading.o \
./Core/Src/led_display.o \
./Core/Src/main.o \
./Core/Src/scheduler.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/ultraSonic.o 

C_DEPS += \
./Core/Src/CEAC_BLE.d \
./Core/Src/IR.d \
./Core/Src/PID.d \
./Core/Src/PWMcontrol.d \
./Core/Src/average_filter.d \
./Core/Src/encoder_ENCTIM.d \
./Core/Src/encoder_IT.d \
./Core/Src/global.d \
./Core/Src/input_reading.d \
./Core/Src/led_display.d \
./Core/Src/main.d \
./Core/Src/scheduler.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/ultraSonic.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/CEAC_BLE.cyclo ./Core/Src/CEAC_BLE.d ./Core/Src/CEAC_BLE.o ./Core/Src/CEAC_BLE.su ./Core/Src/IR.cyclo ./Core/Src/IR.d ./Core/Src/IR.o ./Core/Src/IR.su ./Core/Src/PID.cyclo ./Core/Src/PID.d ./Core/Src/PID.o ./Core/Src/PID.su ./Core/Src/PWMcontrol.cyclo ./Core/Src/PWMcontrol.d ./Core/Src/PWMcontrol.o ./Core/Src/PWMcontrol.su ./Core/Src/average_filter.cyclo ./Core/Src/average_filter.d ./Core/Src/average_filter.o ./Core/Src/average_filter.su ./Core/Src/encoder_ENCTIM.cyclo ./Core/Src/encoder_ENCTIM.d ./Core/Src/encoder_ENCTIM.o ./Core/Src/encoder_ENCTIM.su ./Core/Src/encoder_IT.cyclo ./Core/Src/encoder_IT.d ./Core/Src/encoder_IT.o ./Core/Src/encoder_IT.su ./Core/Src/global.cyclo ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/input_reading.cyclo ./Core/Src/input_reading.d ./Core/Src/input_reading.o ./Core/Src/input_reading.su ./Core/Src/led_display.cyclo ./Core/Src/led_display.d ./Core/Src/led_display.o ./Core/Src/led_display.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/scheduler.cyclo ./Core/Src/scheduler.d ./Core/Src/scheduler.o ./Core/Src/scheduler.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/ultraSonic.cyclo ./Core/Src/ultraSonic.d ./Core/Src/ultraSonic.o ./Core/Src/ultraSonic.su

.PHONY: clean-Core-2f-Src

