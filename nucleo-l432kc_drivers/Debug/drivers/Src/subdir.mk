################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/nucleo-l432kc_gpio_driver.c 

OBJS += \
./drivers/Src/nucleo-l432kc_gpio_driver.o 

C_DEPS += \
./drivers/Src/nucleo-l432kc_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/%.o drivers/Src/%.su drivers/Src/%.cyclo: ../drivers/Src/%.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_L432KC -DSTM32L4 -DSTM32 -DSTM32L432KCUx -c -I../Inc -I"D:/Documents/Electronics/STM32 Workspace/nucleo-l432kc_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-Src

clean-drivers-2f-Src:
	-$(RM) ./drivers/Src/nucleo-l432kc_gpio_driver.cyclo ./drivers/Src/nucleo-l432kc_gpio_driver.d ./drivers/Src/nucleo-l432kc_gpio_driver.o ./drivers/Src/nucleo-l432kc_gpio_driver.su

.PHONY: clean-drivers-2f-Src

