/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		30 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  30 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void MSPI1_voidInit(void)
{

}


u8 MSPI1_u8Tranceive(u8 Copy_u8Data)
{
    /*Set The Data To Be Transmit In DR Register*/
    SPI1 -> DR = Copy_u8Data;
    /*Wait For SPI1 Not Busy*/
    while(GET_BIT(SPI1->SR, 7) == 1);
    /*Return The Received Data*/
    return (SPI1 -> DR);
}