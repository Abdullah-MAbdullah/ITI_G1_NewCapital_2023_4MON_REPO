/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		07 May, 2023
 * Version:				v1.0
 * Compiler:			GNU AVR-GCC
 * Controller:			ATmega32 (8-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  07 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS      0x40020000

#define GPIOA_MODER         *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_OTYPER        *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_OSPEED        *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR           *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x14))

#define OUTPUT_MODE_BITS 0b01


#endif