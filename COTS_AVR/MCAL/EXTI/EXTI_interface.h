/*
 * EXTI_interface.h
 *
 *  Created on: Mar 29, 2023
 *      Author:  Osama
 */

#define EXTI_INT0         0
#define EXTI_INT1         1
#define EXTI_INT2         2

#define	LOW_LEVEL         0
#define	ANY_LOGIC_CHANGE  1
#define	FALLING_EDGE      2
#define	RISING_EDGE       3

void EXTI_voidInitPinConnection(u8 Copy_u8InterruptNum);
void EXTI_voidTriggerEdge(u8 Copy_u8InterruptNum,u8 Copy_u8Edge);
void EXTI_voidEnable(u8 Copy_u8InterruptNum);
void EXTI_voidDisable(u8 Copy_u8InterruptNum);
