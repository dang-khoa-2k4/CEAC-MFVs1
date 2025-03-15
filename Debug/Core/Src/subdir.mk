################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/FSM.c \
../Core/Src/FSM_BLE.c \
../Core/Src/FSM_config.c \
../Core/Src/FSM_line.c \
../Core/Src/FSM_maze.c \
../Core/Src/IR.c \
../Core/Src/PID.c \
../Core/Src/PWMcontrol.c \
../Core/Src/average_filter.c \
../Core/Src/communication.c \
../Core/Src/encoder.c \
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
./Core/Src/FSM.o \
./Core/Src/FSM_BLE.o \
./Core/Src/FSM_config.o \
./Core/Src/FSM_line.o \
./Core/Src/FSM_maze.o \
./Core/Src/IR.o \
./Core/Src/PID.o \
./Core/Src/PWMcontrol.o \
./Core/Src/average_filter.o \
./Core/Src/communication.o \
./Core/Src/encoder.o \
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
./Core/Src/FSM.d \
./Core/Src/FSM_BLE.d \
./Core/Src/FSM_config.d \
./Core/Src/FSM_line.d \
./Core/Src/FSM_maze.d \
./Core/Src/IR.d \
./Core/Src/PID.d \
./Core/Src/PWMcontrol.d \
./Core/Src/average_filter.d \
./Core/Src/communication.d \
./Core/Src/encoder.d \
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
	-$(RM) ./Core/Src/FSM.cyclo ./Core/Src/FSM.d ./Core/Src/FSM.o ./Core/Src/FSM.su ./Core/Src/FSM_BLE.cyclo ./Core/Src/FSM_BLE.d ./Core/Src/FSM_BLE.o ./Core/Src/FSM_BLE.su ./Core/Src/FSM_config.cyclo ./Core/Src/FSM_config.d ./Core/Src/FSM_config.o ./Core/Src/FSM_config.su ./Core/Src/FSM_line.cyclo ./Core/Src/FSM_line.d ./Core/Src/FSM_line.o ./Core/Src/FSM_line.su ./Core/Src/FSM_maze.cyclo ./Core/Src/FSM_maze.d ./Core/Src/FSM_maze.o ./Core/Src/FSM_maze.su ./Core/Src/IR.cyclo ./Core/Src/IR.d ./Core/Src/IR.o ./Core/Src/IR.su ./Core/Src/PID.cyclo ./Core/Src/PID.d ./Core/Src/PID.o ./Core/Src/PID.su ./Core/Src/PWMcontrol.cyclo ./Core/Src/PWMcontrol.d ./Core/Src/PWMcontrol.o ./Core/Src/PWMcontrol.su ./Core/Src/average_filter.cyclo ./Core/Src/average_filter.d ./Core/Src/average_filter.o ./Core/Src/average_filter.su ./Core/Src/communication.cyclo ./Core/Src/communication.d ./Core/Src/communication.o ./Core/Src/communication.su ./Core/Src/encoder.cyclo ./Core/Src/encoder.d ./Core/Src/encoder.o ./Core/Src/encoder.su ./Core/Src/input_reading.cyclo ./Core/Src/input_reading.d ./Core/Src/input_reading.o ./Core/Src/input_reading.su ./Core/Src/led_display.cyclo ./Core/Src/led_display.d ./Core/Src/led_display.o ./Core/Src/led_display.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/scheduler.cyclo ./Core/Src/scheduler.d ./Core/Src/scheduler.o ./Core/Src/scheduler.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/ultraSonic.cyclo ./Core/Src/ultraSonic.d ./Core/Src/ultraSonic.o ./Core/Src/ultraSonic.su

.PHONY: clean-Core-2f-Src

