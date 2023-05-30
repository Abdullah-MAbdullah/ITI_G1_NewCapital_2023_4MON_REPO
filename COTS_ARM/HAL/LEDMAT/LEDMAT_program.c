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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMAT_interface.h"
#include "LEDMAT_private.h"
#include "LEDMAT_config.h"

void HLEDMAT_voidInit(void)
{
    /*Initialize Row Pins To Be Output Pins*/
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R0_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R1_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R2_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R3_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R4_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R5_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R6_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT, HLEDMAT_R7_PIN, MGPIO_OUTPUT);
    
    /*Initialize Column Pins To Be Output Pins*/
    MGPIO_voidSetPinMode(HLEDMAT_COLS_PORT, HLEDMAT_C0_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLS_PORT, HLEDMAT_C1_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLS_PORT, HLEDMAT_C2_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLS_PORT, HLEDMAT_C3_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLS_PORT, HLEDMAT_C4_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLS_PORT, HLEDMAT_C5_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLS_PORT, HLEDMAT_C6_PIN, MGPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COLS_PORT, HLEDMAT_C7_PIN, MGPIO_OUTPUT);
    /*Disbale All Columns*/
    voidDisableAllColumns();
}


void HLEDMAT_voidDisplay(u8 * Copy_pu8Data)
{
    u8 Local_u8ColumnIndex = 0;
    u8 Local_u8RowIndex = 0;
    u8 Local_u8Bit = 0;
    static u8 RowsArray[8] =  {HLEDMAT_R0_PIN,
                        HLEDMAT_R1_PIN, 
                        HLEDMAT_R2_PIN, 
                        HLEDMAT_R3_PIN, 
                        HLEDMAT_R4_PIN, 
                        HLEDMAT_R5_PIN, 
                        HLEDMAT_R6_PIN, 
                        HLEDMAT_R7_PIN};

    static u8 ColumnsArray[8] =  { HLEDMAT_C0_PIN,
                            HLEDMAT_C1_PIN, 
                            HLEDMAT_C2_PIN, 
                            HLEDMAT_C3_PIN, 
                            HLEDMAT_C4_PIN, 
                            HLEDMAT_C5_PIN, 
                            HLEDMAT_C6_PIN, 
                            HLEDMAT_C7_PIN};

    for(Local_u8ColumnIndex = 0; Local_u8ColumnIndex < 8; Local_u8ColumnIndex++)
    {
        voidDisableAllColumns();
        for(Local_u8RowIndex = 0; Local_u8RowIndex < 8; Local_u8RowIndex++)
        {
            Local_u8Bit = GET_BIT(Copy_pu8Data[Local_u8ColumnIndex], Local_u8RowIndex);
            MGPIO_voidSetPinValue(HLEDMAT_ROWS_PORT, RowsArray[Local_u8RowIndex], Local_u8Bit);
        }
        MGPIO_voidSetPinValue(HLEDMAT_COLS_PORT, ColumnsArray[Local_u8ColumnIndex], MGPIO_OUTPUT_LOW);
        MSTK_voidSetBusyWait(2500);
    }
}



static void voidDisableAllColumns(void)
{
    MGPIO_voidSetPinValue(HLEDMAT_C0_PIN, MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C1_PIN, MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C2_PIN, MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C3_PIN, MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C4_PIN, MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C5_PIN, MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C6_PIN, MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C7_PIN, MGPIO_OUTPUT_HIGH);
    
}