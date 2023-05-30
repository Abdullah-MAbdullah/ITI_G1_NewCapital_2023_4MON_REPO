/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   20 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         20 APR, 2023    Abdullah M. Abdullah          Initial Creation
 *********************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/TIMER/TIMER_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

void RTOS_voidInit(void)
{
    /*Set The Compare Match Value To 125 To Make CTC Event every 1msec*/
    TIMER0_voidSetOCMatchValue(125);
    /*Set The Callback For Timer0 To Call Scheduler Function For Each Interrupt*/
    TIMER0_voidSetOCCallBack(&voidScheduler);
    /*Enable The CTC Mode Interrupt*/
    TIMER0_voidEnableInterrupt(CTC_MODE);
    /*Enable The Global Interrupt*/
    GIE_voidEnableGlobalInterrupt();
    /*Set The CTC Mode, Prescaler = 64*/
    TIMER0_voidInit();
}

void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*TaskFunction)(void), u16 Copy_u16FirstDelay)
{
    // SystemTasks[Copy_u8Priority].Priority = Copy_u8Priority;
    SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
    SystemTasks[Copy_u8Priority].TaskFunc = TaskFunction;
    SystemTasks[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
    // SystemTasks[Copy_u8Priority].State = READY;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
    SystemTasks[Copy_u8Priority].TaskFunc = NULL;
    // SystemTasks[Copy_u8Priority].State = DELETED;
}

static void voidScheduler(void)
{
    /*Algorithm = Priority Based*/
    u8 Local_u8LoopCounter;
    for (Local_u8LoopCounter = 0; Local_u8LoopCounter < NUMBER_OF_TASKS; Local_u8LoopCounter++)
    {
        if (SystemTasks[Local_u8LoopCounter].TaskFunc != NULL)
        {
            /*Algorithm Code*/
            if (SystemTasks[Local_u8LoopCounter].FirstDelay == 0)
            {
                /*Dispatcher Code*/
                /*update the first delay parameter value*/
                SystemTasks[Local_u8LoopCounter].FirstDelay = SystemTasks[Local_u8LoopCounter].Periodicity - 1;
                /*Execute The Task Function*/
                SystemTasks[Local_u8LoopCounter].TaskFunc();
            }
            else
            {
                /*Decrement the first delay value by 1*/
                SystemTasks[Local_u8LoopCounter].FirstDelay--;
            }
        }
    }
}
