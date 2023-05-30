/*
 * AVR.c
 *
 * Created: 7/4/2022 1:58:41 PM
 * Author : Osama
 */


#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"



int main(void)
{
	/* Set The PA0 PToggle_LED_within_1Secondin To Be Output Pin => LED */
	DIO_voidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
	/* Initiate The Timer */
	TIMER0_voidInit();

    while (1)
    {
    	/* Set The PA0 Be To High*/
    	DIO_voidSetPinValue(DIO_PORTA, PIN0, HIGH);
    	/* Wait For 1 Second (Busy Wait)*/
    	TIMER0_voidSetBusyWait_OCMode(1000);
    	/* Set The PA0 Be To Low*/
		DIO_voidSetPinValue(DIO_PORTA, PIN0, LOW);
		/* Wait For 1 Second (Busy Wait)*/
		TIMER0_voidSetBusyWait_OCMode(1000);
    }
}
