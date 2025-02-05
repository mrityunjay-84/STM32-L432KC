/*
 * cortex-m4.h
 *
 *  Created on: Jan 28, 2025
 *      Author: mrityunjay
 */

#ifndef INC_CORTEX_M4_H_
#define INC_CORTEX_M4_H_

/* in L432KC, there are 16 programmable priority levels (4 bits of interrupt priority are used)
 * SOURCE -> REFERENCE MANUAL (priority levels) */
#define M4_NO_PR_BITS_IMPLEMENTED 		4


/**********************************************************************************************/
/*                              BASE ADDRESS OF CORE PERIPHERALS                              */
/**********************************************************************************************/
// SOURCE -> GENERIC USER GUIDE (Cortex-M4 Peripherals)

#define SCB 		((__vo uint32_t *)0xE000E008) 		/*!< SyStem Control Block */
#define SYSTICK 	((__vo uint32_t *)0xE000E010)		/*!< System timer */
#define NVIC 		((__vo uint32_t *)0xE000E100)		/*!< Nested Vectored Interrupt Controller */
#define MPU 		((__vo uint32_t *)0xE000ED90) 		/*!< Memory Protection Unit */
#define FPU 		((__vo uint32_t *)0xE000EF30) 		/*!< Floating Point Unit */

/********************************************************************************************/
/*                              BASE ADDRESS OF NVIC REGISTERS                              */
/********************************************************************************************/
// SOURCE -> GENERIC USER GUIDE (Nested Vectored Interrupt Controller)

#define NVIC_ISER0	((__vo uint32_t *)0xE000E100)						/*!< Interrupt Set-enable Registers */
#define NVIC_ICER0	((__vo uint32_t *)0XE000E180)						/*!< Interrupt Clear-enable Registers */
#define NVIC_ISPR0	((__vo uint32_t *)0XE000E200)						/*!< Interrupt Set-pending Registers */
#define NVIC_ICPR0	((__vo uint32_t *)0XE000E280)						/*!< Interrupt Clear-pending Registers */
#define NVIC_IABR0	((__vo uint32_t *)0xE000E300)						/*!< Interrupt Active Bit Registers */
#define NVIC_IPR0	((__vo uint32_t *)0xE000E400)						/*!< Interrupt Priority Registers */
#define STIR		((__vo uint32_t *)0xE000EF00)						/*!< Software Trigger Interrupt Register */

#endif /* INC_CORTEX_M4_H_ */
