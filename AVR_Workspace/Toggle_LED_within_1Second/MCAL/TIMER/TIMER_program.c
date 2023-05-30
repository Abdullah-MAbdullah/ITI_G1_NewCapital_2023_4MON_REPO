/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   09 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         09 APR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*Global_pvOVFNotificationFunction)(void) = NULL;
static void (*Global_pvOCNotificationFunction)(void) = NULL;

void TIMER0_voidInit(void)
{
	/* Set Normal Mode for timer0 */
	//CLR_BIT(TCCR0,TCCR0_WGM00);
	//CLR_BIT(TCCR0,TCCR0_WGM01);

	/* Set CTC Mode for timer0 */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Set The Prescaler to be 8*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
}

void TIMER0_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOVFNotificationFunction = pvNotificationFunction;
}
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOCNotificationFunction = pvNotificationFunction;
}

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		SET_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		SET_BIT(TIMSK,TIMSK_OCIE0);
	}
}
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		CLR_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		CLR_BIT(TIMSK,TIMSK_OCIE0);
	}
}

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time)
{
	/*Set The Prescaler to be 8*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	TIMER0_voidSetPreloadValue(6);
	u32 Number_of_OVF = ((u32)(Copy_u32Time*1000)) / 250;

	u32 Counter = 0;

	while(Counter < Number_of_OVF)
	{
		while(GET_BIT(TIFR , TIFR_OCF0) == 0);
		SET_BIT(TIFR , TIFR_OCF0);
		Counter++;
		TIMER0_voidSetPreloadValue(6);
	}
}
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time)
{
	/*Set The Prescaler to be 8*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	TIMER0_voidSetOCMatchValue(250);
	/*You should cast the constants, i.e., 1000 and 250 to unsigned long (u32) and compute the multiplication operation first before the division */
	//u32 Number_of_OCFlags = ((u32)(Copy_u32Time*1000)) / 250;
	u32 Number_Of_OCF = ((u32)Copy_u32Time * 1000UL) / 250UL;

	u32 Local_u32Counter = 0;

	while(Local_u32Counter <= Number_Of_OCF)
	{
		while(GET_BIT(TIFR , TIFR_OCF0) == 0);
		SET_BIT(TIFR , TIFR_OCF0);
		Local_u32Counter++;
	}
}
