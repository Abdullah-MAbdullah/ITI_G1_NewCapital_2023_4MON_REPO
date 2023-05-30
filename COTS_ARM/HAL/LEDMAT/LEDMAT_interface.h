/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		14 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  14 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef LEDMAT_INTERFACE_H
#define LEDMAT_INTERFACE_H


void HLEDMAT_voidInit(void);
void HLEDMAT_voidDisplay(u8 * Copy_pu8Data);
static void voidDisableAllColumns(void);

#endif