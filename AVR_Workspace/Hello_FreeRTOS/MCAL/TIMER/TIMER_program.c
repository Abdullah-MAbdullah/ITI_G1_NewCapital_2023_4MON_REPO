/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   09 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         09 APR, 2023    Abdullah M. Abdullah          Initial Creation
 * v2.0         12 APR, 2023    Abdullah M. Abdullah          Add ICU APIs
*********************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*Global_pvOVFNotificationFunction)(void) = NULL;
static void (*Global_pvOCNotificationFunction)(void) = NULL;
static void (*ICU_NotificationFunction)(void) = NULL;

void TIMER0_voidInit(void)
{
	/*Set The Mode To Be CTC Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

	/*Set The Prescaler to be 64*/
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
}

void TIMER1_voidInit(void)
{
	/*Set Timer1 Mode To Be Normal Mode*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);

	/*Set The Prescaler To Be 8*/
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);

}

void TIMER1_voidSetICR1Value(u16 Copy_u16ICRValue)
{
	ICR1 = Copy_u16ICRValue;
}

void TIMER1_voidSetOCR1AValue(u16 Copy_u16OCR1AValue)
{
	OCR1A = Copy_u16OCR1AValue;
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



u16 ICU_u16GetICRRegister(void)
{
	return ICR1;
}

void ICU_voidSetTriggerSignal(u8 Copy_u8TriggerSignal)
{
	switch(Copy_u8TriggerSignal)
	{
		case ICU_RISING_EDGE:
		/* Set The Input Capture Edge Select Bit To Choose the Trigger Edge To Be Rising Edge*/
			SET_BIT(TCCR1B, TCCR1B_ICES1);
		break;

		case ICU_FALLING_EDGE:
		/* Clear The Input Capture Edge Select Bit To Choose the Trigger Edge To Be Falling Edge*/
			CLR_BIT(TCCR1B, TCCR1B_ICES1);
		break;
	}
}

void ICU_voidInterruptControl(u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case ICU_ENABLE:
		/*Set The Input Capture Interrupt Enable Bit To Enable The Interrupt*/
			SET_BIT(TIMSK, TIMSK_TICIE1);
		break;

		case ICU_DISABLE:
		/*Clear The Input Capture Interrupt Enable Bit To Disbale The Interrupt*/
			CLR_BIT(TIMSK, TIMSK_TICIE1);
		break;
	}
}

void ICU_voidSetCallback(void (*NotifiFunction) (void))
{
	ICU_NotificationFunction = NotifiFunction;
}

// ISR For Input Capture Unit (ICU)
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_NotificationFunction != NULL)
	{
		ICU_NotificationFunction();
	}
	else
	{
		// Do Nothing
	}
}

// ISR For CTC Mode
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(Global_pvOCNotificationFunction != NULL)
	{
		Global_pvOCNotificationFunction();
	}
	else
	{
		// Do Nothing
	}
}