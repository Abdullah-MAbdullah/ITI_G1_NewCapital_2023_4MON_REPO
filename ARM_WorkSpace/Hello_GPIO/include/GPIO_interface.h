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
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


#define MGPIO_PORTA 0
#define MGPIO_PORTB 1
#define MGPIO_PORTC 2

#define LOW         0
#define HIGH        1

void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Mode);
void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType);
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed);
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);


#endif