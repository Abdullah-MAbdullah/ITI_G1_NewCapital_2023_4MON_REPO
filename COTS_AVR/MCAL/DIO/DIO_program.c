/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   22 MAR, 2023
 * Version:         v2.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         22 MAR, 2023    Abdullah M. Abdullah          Initial Creation
 * v2.0         26 MAR, 2023    Abdullah M. Abdullah          Add SetPortDirection & SetPortValue
*********************************************/
/*Library Inclusions*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*Lower Layer Inclusions*/

/*Self Files Inclusions*/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Direction)
{
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRA, Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLR_BIT(DDRA, Copy_u8PinNumber);
			}
			else
			{
				// Do Nothing
			}
		break;
		case DIO_PORTB:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRB, Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLR_BIT(DDRB, Copy_u8PinNumber);
			}
			else
			{
				// Do Nothing
			}
		break;
		case DIO_PORTC:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRC, Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLR_BIT(DDRC, Copy_u8PinNumber);
			}
			else
			{
				// Do Nothing
			}
		break;
		case DIO_PORTD:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRD, Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLR_BIT(DDRD, Copy_u8PinNumber);
			}
			else
			{
				// Do Nothing
			}
		break;
		default:
			// Do Nothing
		break;
	}
}


void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState)
{
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
			switch(Copy_u8PinState)
			{
				case LOW:
					CLR_BIT(PORTA, Copy_u8PinNumber);
				break;

				case HIGH:
					SET_BIT(PORTA, Copy_u8PinNumber);
				break;
			}
		break;
		
		case DIO_PORTB:
			switch(Copy_u8PinState)
			{
				case LOW:
					CLR_BIT(PORTB, Copy_u8PinNumber);
				break;

				case HIGH:
					SET_BIT(PORTB, Copy_u8PinNumber);
				break;
			}
		break;

		case DIO_PORTC:
			switch(Copy_u8PinState)
			{
				case LOW:
					CLR_BIT(PORTC, Copy_u8PinNumber);
				break;

				case HIGH:
					SET_BIT(PORTC, Copy_u8PinNumber);
				break;
			}
		break;

		case DIO_PORTD:
			switch(Copy_u8PinState)
			{
				case LOW:
					CLR_BIT(PORTD, Copy_u8PinNumber);
				break;

				case HIGH:
					SET_BIT(PORTD, Copy_u8PinNumber);
				break;
			}
		break;
		default:
			// Do Nothing
		break;
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	u8 Local_u8PinValue = 0;
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
			Local_u8PinValue = GET_BIT(PINA, Copy_u8PinNumber);
		break;
		
		case DIO_PORTB:
			Local_u8PinValue = GET_BIT(PINB, Copy_u8PinNumber);
		break;
		
		case DIO_PORTC:
			Local_u8PinValue = GET_BIT(PINC, Copy_u8PinNumber);
		break;

		case DIO_PORTD:
			Local_u8PinValue = GET_BIT(PIND, Copy_u8PinNumber);
		break;
		default:
			/* Do Nothing*/
		break;
	}
	return Local_u8PinValue;
}

void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection)
{
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
			// DDRA = Copy_u8SpecificDirection;
			SET_REG(DDRA, Copy_u8SpecificDirection);
		break;
		case DIO_PORTB:
			SET_REG(DDRB, Copy_u8SpecificDirection);
		break;
		case DIO_PORTC:
			SET_REG(DDRC, Copy_u8SpecificDirection);
		break;
		case DIO_PORTD:
			SET_REG(DDRD, Copy_u8SpecificDirection);
		break;
		default:
			/* Do Nothing*/
		break;
	}
}
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
			// PORTA = Copy_u8PortValue;
			SET_REG(PORTA, Copy_u8PortValue);
		break;
		case DIO_PORTB:
			SET_REG(PORTB, Copy_u8PortValue);		
		break;
		case DIO_PORTC:
			SET_REG(PORTC, Copy_u8PortValue);
		break;
		case DIO_PORTD:
			SET_REG(PORTD, Copy_u8PortValue);
		break;
	}
}