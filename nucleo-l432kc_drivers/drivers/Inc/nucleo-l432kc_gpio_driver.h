/*
 * nucleo-l432kc_gpio_driver.h
 *
 *  Created on: Jan 26, 2025
 *      Author: mrityunjay
 */

#ifndef INC_NUCLEO_L432KC_GPIO_DRIVER_H_
#define INC_NUCLEO_L432KC_GPIO_DRIVER_H_

#include "nucleo-l432kc.h"

/***************************************************************************************/
/*                              GPIO STRUCTURE DEFINITION                              */
/***************************************************************************************/

/* structure for a GPIO pin configuration settings */
typedef struct{
	uint8_t GPIO_PinNumber;					/*!< possible values from @GPIO_PinNumber */
	uint8_t GPIO_PinMode;					/*!< possible values from @GPIO_PinMode */
	uint8_t GPIO_PinOpSpeed;				/*!< possible values from @GPIO_PinOpSpeed */
	uint8_t GPIO_PinOpType;					/*!< possible values from @GPIO_PinOpType */
	uint8_t GPIO_PinPUPD;					/*!< possible values from @GPIO_PinPUPD */
	uint8_t GPIO_PinAltFun;					/*!< possible values from @GPIO_PinAltFun */
}GPIO_PinConfig_t;


/* handle structure for a GPIO pin */
typedef struct{
	GPIO_RegDef_t *pGPIOx;					/*!< base address of the GPIO port type-casted to GPIO_RegDef_t */
	GPIO_PinConfig_t GPIO_PinConfig;		/*!< GPIO pin configuration settings */
}GPIO_Handle_t;

/*******************************************************************************************/
/*                              GPIO PIN CONFIGURATION MACROS                              */
/*******************************************************************************************/

/* MACROS for GPIO Pin Number
 * @GPIO_PinNumber
 */

#define GPIO_NO_0					0		/*!< GPIO Pin Number 0 */
#define GPIO_NO_1					1		/*!< GPIO Pin Number 1 */
#define GPIO_NO_2					2		/*!< GPIO Pin Number 2 */
#define GPIO_NO_3					3		/*!< GPIO Pin Number 3 */
#define GPIO_NO_4					4		/*!< GPIO Pin Number 4 */
#define GPIO_NO_5					5		/*!< GPIO Pin Number 5 */
#define GPIO_NO_6					6		/*!< GPIO Pin Number 6 */
#define GPIO_NO_7					7		/*!< GPIO Pin Number 7 */
#define GPIO_NO_8					8		/*!< GPIO Pin Number 8 */
#define GPIO_NO_9					9		/*!< GPIO Pin Number 9 */
#define GPIO_NO_10					10		/*!< GPIO Pin Number 10 */
#define GPIO_NO_11					11		/*!< GPIO Pin Number 11 */
#define GPIO_NO_12					12		/*!< GPIO Pin Number 12 */
#define GPIO_NO_13					13		/*!< GPIO Pin Number 13 */
#define GPIO_NO_14					14		/*!< GPIO Pin Number 14 */
#define GPIO_NO_15					15		/*!< GPIO Pin Number 15 */


/* MACROS for GPIO Pin Mode
 * @GPIO_PinMode
 */

#define GPIO_MODE_IN				0		/*!< 00 : Input mode */
#define GPIO_MODE_OUT				1		/*!< 01 : General purpose output mode */
#define GPIO_MODE_ALTFN				2		/*!< 10 : Alternate function mode */
#define GPIO_MODE_ANALOG			3		/*!< 11: Analog mode (reset state) */
#define GPIO_MODE_ITFT				4		/*!< Interrupt - Falling Edge Trigger */
#define GPIO_MODE_ITRT				5		/*!< Interrupt - Rising Edge Trigger */
#define GPIO_MODE_ITFRT				6		/*!< Interrupt - Falling & Rising Edge Trigger */


/* MACROS for GPIO Pin Output Speed
 * @GPIO_PinOpSpeed
 */

#define GPIO_OPSPEED_LOW			0		/*!< 00: Low speed */
#define GPIO_OPSPEED_MEDIUM			1		/*!< 01: Medium speed */
#define GPIO_OPSPEED_HIGH			2		/*!< 10: High speed */
#define GPIO_OPSPEED_VERYHIGH		3		/*!< 11: Very high speed */


/* MACROS for GPIO Output Type
 * @GPIO_PinOpType
 */

#define GPIO_OPTYPE_PUSHPULL		0		/*!< 0: Output push-pull (reset state) */
#define GPIO_OPTYPE_OPENDRAIN		1		/*!< 1: Output open-drain */

/* MACROS for GPIO Pull Up/ Pull Down
 * @GPIO_PinPUPD
 */

#define GPIO_PUPD_NOPUPD			0		/*!< 00: No pull-up, pull-down */
#define GPIO_PUPD_PU				1		/*!< 01: Pull-up */
#define GPIO_PUPD_PD				2 		/*!< 10: Pull-down */

/* MACROS for GPIO Alternate Function Mode
 * @GPIO_PinAltFun
 */

#define GPIO_ALTFUN_0				0		/*!< 0000: AF0 */
#define GPIO_ALTFUN_1				1		/*!< 0001: AF1 */
#define GPIO_ALTFUN_2				2		/*!< 0010: AF2 */
#define GPIO_ALTFUN_3				3		/*!< 0011: AF3 */
#define GPIO_ALTFUN_4				4		/*!< 0100: AF4 */
#define GPIO_ALTFUN_5				5		/*!< 0101: AF5 */
#define GPIO_ALTFUN_6				6		/*!< 0110: AF6 */
#define GPIO_ALTFUN_7				7		/*!< 0111: AF7 */
#define GPIO_ALTFUN_8				8		/*!< 1000: AF8 */
#define GPIO_ALTFUN_9				9		/*!< 1001: AF9 */
#define GPIO_ALTFUN_10				10		/*!< 1010: AF10 */
#define GPIO_ALTFUN_11				11		/*!< 1011: AF11 */
#define GPIO_ALTFUN_12				12		/*!< 1100: AF12 */
#define GPIO_ALTFUN_13				13		/*!< 1101: AF13 */
#define GPIO_ALTFUN_14				14		/*!< 1110: AF14 */
#define GPIO_ALTFUN_15				15		/*!< 1111: AF15 */

/***********************************************************************/
/*                              GPIO APIS                              */
/***********************************************************************/

/* GPIO Peripheral Clock Setup */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDis);

/* Initialization and DeInitialization */

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/* Data Read and Write */

bool GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, bool Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint16_t PinNumber);

/* IRQ Configuration and IRS Handling */

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, bool EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_NUCLEO_L432KC_GPIO_DRIVER_H_ */
