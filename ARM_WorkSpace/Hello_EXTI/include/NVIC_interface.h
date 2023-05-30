/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		18 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  18 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define     MNVIC_EXTI0     6
#define     MNVIC_EXTI1     7

void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralName);
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralName);
void MNVIC_voidSetPeripheralInterruptPriority(u8 Copy_u8PeripheralName, u8 Copy_u8Prioirty);
void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralName);
void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralName);
u8 MNVIC_voidGetActiveFlag(u8 Copy_u8PeripheralName);

#endif
