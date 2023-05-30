/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   26 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         26 MAR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define     LCD_ALL_OUTPUT     0xFF
#define     EIGHT_BIT_MODE     1
#define     FOUR_BIT_MODE      0

#define     FUNCTION_SET_CMD        0x38 //0b00111000
#define     DISPLAY_ON_OFF_CMD      0x0F
#define     DISPLAY_CLEAR_CMD       0x01

static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif