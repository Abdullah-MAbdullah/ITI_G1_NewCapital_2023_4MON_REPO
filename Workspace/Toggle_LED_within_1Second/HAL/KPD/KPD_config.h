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
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#define KPD_ROWS_PORT       DIO_PORTD
#define KPD_COLUMNS_PORT    DIO_PORTD


#define KPD_ROW0_PIN        PIN0
#define KPD_ROW1_PIN        PIN1
#define KPD_ROW2_PIN        PIN2
#define KPD_ROW3_PIN        PIN3

#define KPD_COLUMN0_PIN     PIN4
#define KPD_COLUMN1_PIN     PIN5
#define KPD_COLUMN2_PIN     PIN6
#define KPD_COLUMN3_PIN     PIN7

#define KPD_NOT_PRESSED_VAL 255

#define     KPD_ARR_VAL         {{'1', '2', '3', 'A'},{'4', '5', '6', 'B'},{'7', '8', '9', 'C'},{'*', '0', '#', 'D'}}
#define     KPD_ROWS_NUM        4
#define     KPD_COULMNS_NUM     4

#endif