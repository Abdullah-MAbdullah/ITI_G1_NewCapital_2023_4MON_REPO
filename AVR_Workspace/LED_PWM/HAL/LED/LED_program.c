/*
 * LED_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Osama.Mahmoud
 */


#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void LED_voidInit(LED_t* Ledobj)
{
	DIO_voidSetPinDirection(Ledobj->LED_PORT , Ledobj->LED_PIN , OUTPUT);
}
void LED_voidTurnOn(LED_t* Ledobj)
{
	DIO_voidSetPinValue(Ledobj->LED_PORT , Ledobj->LED_PIN , HIGH);
}
void LED_voidTurnOff(LED_t* Ledobj)
{
	DIO_voidSetPinValue(Ledobj->LED_PORT , Ledobj->LED_PIN , LOW);
}
/*void LED_voidToggle(LED_t* Ledobj)
{
	DIO_voidTogPinValue(Ledobj->LED_PORT , Ledobj->LED_PIN);
}*/
