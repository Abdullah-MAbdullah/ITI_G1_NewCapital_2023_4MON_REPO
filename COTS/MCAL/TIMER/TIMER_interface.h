/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   09 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         09 APR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/


#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#define NORMAL_MODE  0
#define CTC_MODE     1


void TIMER0_voidInit(void);

void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value);

void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void));

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time);
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
