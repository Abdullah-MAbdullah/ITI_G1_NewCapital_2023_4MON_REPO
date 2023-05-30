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
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

void RTOS_voidInit(void);
void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*TaskFunction)(void));
void RTOS_voidDeleteTask(u8 Copy_u8Priority);

#endif