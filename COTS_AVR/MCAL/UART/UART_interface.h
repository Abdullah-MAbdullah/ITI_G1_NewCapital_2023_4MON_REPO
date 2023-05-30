/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   17 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         17 APR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);
void UART_voidTransmitData(u8 Copy_u8Data);
void UART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData);



#endif