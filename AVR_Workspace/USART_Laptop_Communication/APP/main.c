#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/DIO/DIO_interface.h"


int main(void)
{
	u8 Local_u8ReceivedData;
	/*Set LED Pin (PA0) To Be Output*/
	DIO_voidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
	/*Set Tx (PD1) Pin To Be Output Pin*/
	DIO_voidSetPinDirection(DIO_PORTD, PIN1, OUTPUT);
	/*Set Rx (PD0) Pin To Be Input Pin*/
	DIO_voidSetPinDirection(DIO_PORTD, PIN0, INPUT);

	UART_voidInit();

	while(1)
	{
		/*Receive One Character From UART*/
		UART_voidReceiveDataSynchronous(&Local_u8ReceivedData);
		/*Transmit the Received Character From UART*/
		UART_voidTransmitDataSynchronous(Local_u8ReceivedData);
		if(Local_u8ReceivedData == 'A')
		{
			/*Turn On The LED*/
			DIO_voidSetPinValue(DIO_PORTA, PIN0, HIGH);
		}
		else if(Local_u8ReceivedData == 'B')
		{
			/*Turn Off The LED*/
			DIO_voidSetPinValue(DIO_PORTA, PIN0, LOW);
		}
		else
		{
			/* Do Nothing */
		}
	}
}
