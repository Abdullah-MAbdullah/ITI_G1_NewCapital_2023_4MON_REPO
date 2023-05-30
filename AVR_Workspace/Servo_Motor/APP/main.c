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
	/*Intialize Timer 1*/
	TIMER1_voidInit();
	/*Set PD5 To Be Output Pin*/
	DIO_voidSetPinDirection(DIO_PORTD, PIN5, OUTPUT);
	/*Set The Period Time ICR1 = 20000*/
	TIMER1_voidSetICR1Value(20000);
    while (1)
    {
    	/* Set The On Time OCR = 220 ~ 2750 */
    	TIMER1_voidSetOCR1AValue(1000);
    }
}
