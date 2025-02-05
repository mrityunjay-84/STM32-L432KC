/*
 * 001led_toggle.c
 * AIM -> toggle led using push pull configuration
 *
 *  Created on: Jan 27, 2025
 *      Author: mrityunjay
 */

#include "nucleo-l432kc.h"

/* software delay */
void delay(){
	for (uint32_t i = 0; i < 0x0000FFFF; i++);
}

int main(void){
	GPIO_Handle_t GPIO_LED;

	// User LED is PB3
	// configuring GPIO registers for Port B Pin 3

	GPIO_LED.pGPIOx = GPIOB;
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_NO_3;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_LED.GPIO_PinConfig.GPIO_PinOpSpeed = GPIO_OPSPEED_LOW;
	GPIO_LED.GPIO_PinConfig.GPIO_PinOpType = GPIO_OPTYPE_PUSHPULL;
	GPIO_LED.GPIO_PinConfig.GPIO_PinPUPD = GPIO_PUPD_NOPUPD;

	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&GPIO_LED);

	while(1){
		GPIO_ToggleOutputPin(GPIOB, GPIO_NO_3);
		delay();
	}

	return 0;
}

