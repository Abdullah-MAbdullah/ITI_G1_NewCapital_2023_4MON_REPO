/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   28 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         28 MAR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"




void KPD_voidInit(void)
{
    /* Set Rows Pins To Be Input PulledUp*/
    DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW0_PIN, INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW1_PIN, INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW2_PIN, INPUT);
    DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW3_PIN, INPUT);
    
    DIO_voidSetPinValue(KPD_ROWS_PORT, KPD_ROW0_PIN, PULLUP);
    DIO_voidSetPinValue(KPD_ROWS_PORT, KPD_ROW1_PIN, PULLUP);
    DIO_voidSetPinValue(KPD_ROWS_PORT, KPD_ROW2_PIN, PULLUP);
    DIO_voidSetPinValue(KPD_ROWS_PORT, KPD_ROW3_PIN, PULLUP);

    /* Set Columns Pins To Be Output High*/
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, OUTPUT);

    DIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, HIGH);
}


u8 KPD_u8GetPressedKey(void)
{
    static u8 Local_u8KPDArray[KPD_ROWS_NUM][KPD_COULMNS_NUM] = KPD_ARR_VAL;
    static u8 Local_u8KPDColumnsArray[KPD_COULMNS_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
    static u8 Local_u8KPDRowsArray[KPD_ROWS_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
    u8 Local_u8RowValue;
    u8 Local_u8ColumnsIterator;
    u8 Local_u8RowsIterator;
    u8 Local_u8PressedKey = KPD_NOT_PRESSED_VAL;
    for(Local_u8ColumnsIterator = 0; Local_u8ColumnsIterator < KPD_COULMNS_NUM; Local_u8ColumnsIterator++)
    {
        /*Activate A Column , Activate (Ground)*/
        DIO_voidSetPinValue(KPD_COLUMNS_PORT, Local_u8KPDColumnsArray[Local_u8ColumnsIterator], LOW);
        /*Iterate On The KPD Rows */
        for(Local_u8RowsIterator = 0; Local_u8RowsIterator < KPD_ROWS_NUM; Local_u8RowsIterator++)
        {
            /*Get The Row Value*/
            Local_u8RowValue = DIO_u8GetPinValue(KPD_ROWS_PORT, Local_u8KPDRowsArray[Local_u8RowsIterator]);
            if(Local_u8RowValue == LOW)
            {
                /*Get The Pressed Key*/
                Local_u8PressedKey = Local_u8KPDArray[Local_u8RowsIterator][Local_u8ColumnsIterator];
                /*Polling (busy wait) till the key is released*/
                while(Local_u8RowValue == LOW)
                {
                    Local_u8RowValue = DIO_u8GetPinValue(KPD_ROWS_PORT, Local_u8KPDRowsArray[Local_u8RowsIterator]);
                }
                /*Return The Pressed Key*/
                return Local_u8PressedKey;
            }
        }
        /*Deactivate A Column , Deactivate (VCC)*/
        DIO_voidSetPinValue(KPD_COLUMNS_PORT, Local_u8KPDColumnsArray[Local_u8ColumnsIterator], HIGH);
    }
    /*Return The Default Value*/
    return Local_u8PressedKey;
}