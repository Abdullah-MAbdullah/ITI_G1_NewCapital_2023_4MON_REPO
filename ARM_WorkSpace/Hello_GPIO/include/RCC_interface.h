/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		02 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  02 May, 2023	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define     RCC_AHB1        0
#define     RCC_AHB2        1
#define     RCC_APB1        2
#define     RCC_APB2        3

#define     RCC_GPIOA       0
#define     RCC_GPIOB       1
#define     RCC_GPIOC       2

void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID);
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID);

#endif