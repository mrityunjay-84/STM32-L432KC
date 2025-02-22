/*
 * 004button_trigger.c
 * AIM -> toggle LED at falling edge of interrupt
 *
 *  Created on: Feb 4, 2025
 *      Author: mrityunjay
 */

#include "nucleo-l432kc.h"

int main(void){
	// user led is at PB3 (D13)
	// configuring the GPIO registers for Port B Pin 3

	GPIO_Handle_t gpio_led;
	memset(&gpio_led, 0, sizeof(gpio_led));

	gpio_led.pGPIOx = GPIOB;
	gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_NO_3;
	gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	gpio_led.GPIO_PinConfig.GPIO_PinOpSpeed = GPIO_OPSPEED_LOW;
	gpio_led.GPIO_PinConfig.GPIO_PinOpType = GPIO_OPTYPE_PUSHPULL;
	gpio_led.GPIO_PinConfig.GPIO_PinPUPD = GPIO_PUPD_NOPUPD;


	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&gpio_led);

	// external button at PB4
	// configuring the GPIO registers for Port B Pin 4

	GPIO_Handle_t gpio_uno;
	memset(&gpio_uno, 0, sizeof(gpio_uno));

	gpio_uno.pGPIOx = GPIOB;
	gpio_uno.GPIO_PinConfig.GPIO_PinNumber = GPIO_NO_4;
	gpio_uno.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ITFT;
	gpio_uno.GPIO_PinConfig.GPIO_PinPUPD = GPIO_PUPD_PU;

	// GPIO_PeriClockControl(GPIOB, ENABLE);
	// no need here because clock to GPIOB peripheral has already been enabled
	GPIO_Init(&gpio_uno);
	GPIO_WriteToOutputPin(gpio_uno.pGPIOx, gpio_uno.GPIO_PinConfig.GPIO_PinNumber, RESET);

	// IRQ Configurations
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI4, ENABLE);
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI4, 17);			// refer vector table for priority or set your own

	while(1){

	}

	return 1;
}

void EXTI4_IRQHandler(void){
	GPIO_IRQHandling(GPIO_NO_4);
	GPIO_ToggleOutputPin(GPIOB, GPIO_NO_3);
}
