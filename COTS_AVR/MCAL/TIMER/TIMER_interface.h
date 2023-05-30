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

#define NORMAL_MODE         0
#define CTC_MODE            1


#define ICU_RISING_EDGE     1
#define ICU_FALLING_EDGE    0

#define ICU_ENABLE          1
#define ICU_DISABLE         0

void TIMER0_voidInit(void);
void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value);
void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void));
void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time);
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time);
void TIMER1_voidInit(void);
void TIMER1_voidSetICR1Value(u16 Copy_u16ICRValue);
void TIMER1_voidSetOCR1AValue(u16 Copy_u16OCR1AValue);
void ICU_voidSetCallback(void (*NotifiFunction) (void));
void ICU_voidSetTriggerSignal(u8 Copy_u8TriggerSignal);
void ICU_voidInterruptControl(u8 Copy_u8InterruptState);
u16  ICU_u16GetICRRegister(void);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
