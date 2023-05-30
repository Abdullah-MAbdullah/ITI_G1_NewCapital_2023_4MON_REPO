#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "FreeRTOS.h"
#include "task.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"

void Led1_Task(void * pvParam);
void Led2_Task(void * pvParam);

void main(void)
{
	DIO_voidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, PIN1, OUTPUT);
	UART_voidInit();

	xTaskCreate(&Led1_Task, "Task 1", configMINIMAL_STACK_SIZE, NULL, 0, NULL);
	xTaskCreate(&Led2_Task, "Task 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	vTaskStartScheduler();
	while(1)
	{
		;
	}
}

void Led1_Task(void * pvParam)
{
	while(1)
	{
		static u8 Local_u8PinState = 0;
		Local_u8PinState ^=1;
		DIO_voidSetPinValue(DIO_PORTA, PIN0, Local_u8PinState);
		UART_voidSendString("Hello From Task 1\r\n");
//		_delay_ms(1000);
		vTaskDelay(1000);
	}
}

void Led2_Task(void * pvParam)
{
	while(1)
	{
		static u8 Local_u8PinState = 0;
		Local_u8PinState ^=1;
		DIO_voidSetPinValue(DIO_PORTA, PIN1, Local_u8PinState);
		UART_voidSendString("Hello From Task 2\r\n");
//		_delay_ms(1000);
		vTaskDelay(2000);
	}
}





