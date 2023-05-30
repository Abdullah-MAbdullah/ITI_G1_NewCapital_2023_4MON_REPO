/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		18 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  18 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
    #define SCB_AIRCR   *(volatile u32 *)0xE000ED0C
    SCB_AIRCR = (AIRCR_VECTKEY << 16) | (NVIC_PRIORITY_BITS_DISTRBUTION << 8);
}

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralName)
{
    u8 Local_u8PeripheralIndex;
    /*Check if the Peripheral Name (ID) is more than 240, because we have only 240 External peripheral (0 to 239)*/
    if(Copy_u8PeripheralName > 240)
    {
        return;
    }
    else
    {
        Local_u8PeripheralIndex = Copy_u8PeripheralName / 32;
        NVIC -> ISER[Local_u8PeripheralIndex] = (1 << Copy_u8PeripheralName);
    }
}

void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralName)
{
    u8 Local_u8PeripheralIndex;
    /*Check if the Peripheral Name (ID) is more than 240, because we have only 240 External peripheral (0 to 239)*/
    if(Copy_u8PeripheralName > 240)
    {
        return;
    }
    else
    {
        /*Calculate the Interrupt Clear Enable Register Index*/
        Local_u8PeripheralIndex = Copy_u8PeripheralName / 32;
        /*Set The Peripheral Bit To 1 To Enable Its Interrupt*/
        NVIC -> ICER[Local_u8PeripheralIndex] = (1 << Copy_u8PeripheralName);
    }
}

void MNVIC_voidSetPeripheralInterruptPriority(u8 Copy_u8PeripheralName, u8 Copy_u8Prioirty)
{
    /*Check if the Peripheral Name (ID) is more than 240, because we have only 240 External peripheral (0 to 239)*/
    if(Copy_u8PeripheralName > 240 || Copy_u8Prioirty > 15)
    {
        return;
    }
    else
    {
        /*Set The Interrupt Peripheral Priority*/
        NVIC -> IPR[Copy_u8PeripheralName] = Copy_u8Prioirty << 4;
    }
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralName)
{
    u8 Local_u8PeripheralIndex;
    /*Check if the Peripheral Name (ID) is more than 240, because we have only 240 External peripheral (0 to 239)*/
    if(Copy_u8PeripheralName > 240)
    {
        return;
    }
    else
    {
        /*Calculate the Interrupt Clear Enable Register Index*/
        Local_u8PeripheralIndex = Copy_u8PeripheralName / 32;
        /*Set The Peripheral Bit To 1 To Enable Its Interrupt*/
        NVIC -> ISPR[Local_u8PeripheralIndex] = (1 << Copy_u8PeripheralName);
    }
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralName)
{
    u8 Local_u8PeripheralIndex;
    /*Check if the Peripheral Name (ID) is more than 240, because we have only 240 External peripheral (0 to 239)*/
    if(Copy_u8PeripheralName > 240)
    {
        return;
    }
    else
    {
        /*Calculate the Interrupt Clear Enable Register Index*/
        Local_u8PeripheralIndex = Copy_u8PeripheralName / 32;
        /*Set The Peripheral Bit To 1 To Enable Its Interrupt*/
        NVIC -> ICPR[Local_u8PeripheralIndex] = (1 << Copy_u8PeripheralName);
    }
}

u8 MNVIC_voidGetActiveFlag(u8 Copy_u8PeripheralName)
{
    u8 Local_u8PeripheralIndex;
    u8 Local_u8ActiveFlag;
    /*Check if the Peripheral Name (ID) is more than 240, because we have only 240 External peripheral (0 to 239)*/
    if(Copy_u8PeripheralName > 240)
    {
        return;
    }
    else
    {
        /*Calculate the Interrupt Clear Enable Register Index*/
        Local_u8PeripheralIndex = Copy_u8PeripheralName / 32;
        /*Set The Peripheral Bit To 1 To Enable Its Interrupt*/
        Local_u8ActiveFlag = NVIC -> IABR[Local_u8PeripheralIndex];
    }
    return Local_u8ActiveFlag;
}

