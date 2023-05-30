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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"





void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Mode)
{
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        GPIOA_MODER |= OUTPUT_MODE_BITS << (Copy_u8PinNumber * 2);
        break;

    case MGPIO_PORTB:
        break;

    case MGPIO_PORTC:
        break;
    }
}

void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputType)
{
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        CLR_BIT(GPIOA_OTYPER, Copy_u8PinNumber);
        break;

    case MGPIO_PORTB:
        break;

    case MGPIO_PORTC:
        break;
    }
}

void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed)
{
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
            GPIOA_OSPEED |= 0b00 << (Copy_u8PinNumber * 2);
        break;

    case MGPIO_PORTB:
        break;

    case MGPIO_PORTC:
        break;
    }
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch(Copy_u8PortName)
    {
    case MGPIO_PORTA:
            switch(Copy_u8PinValue)
            {
                case HIGH:
                    SET_BIT(GPIOA_ODR, Copy_u8PinNumber);
                break;
                case LOW:
                    CLR_BIT(GPIOA_ODR, Copy_u8PinNumber);
                break;
            }
        break;

    case MGPIO_PORTB:
        break;

    case MGPIO_PORTC:
        break;
    }
}