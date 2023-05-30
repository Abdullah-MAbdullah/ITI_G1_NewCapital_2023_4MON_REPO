#include "../SERVICES/RTOS/RTOS_interface.h"



void LED1_Task(void);
void LED2_Task(void);
void LED3_Task(void);


void main(void)
{
    RTOS_voidCreateTask(0, 1000, &LED1_Task);
    RTOS_voidCreateTask(1, 2000, &LED2_Task);
    RTOS_voidCreateTask(2, 3000, &LED3_Task);

    RTOS_voidInit();

    while(1);
}

void LED1_Task(void)
{
    static u8 Local_u8PinState = 0;
    Local_u8PinState ^= 1;
    DIO_voidSetPinValue(PORTA, PIN0, Local_u8PinState);
}

void LED2_Task(void)
{

}

void LED3_Task(void)
{

}
