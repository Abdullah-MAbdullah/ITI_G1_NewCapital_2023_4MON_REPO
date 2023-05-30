/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   30 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         30 MAR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_INTERRUPT_ENABLE      1
#define ADC_INTERRUPT_DISABLE     0

#define ADC_CHANELL_0   0b00000
#define ADC_CHANELL_1   0b00001
#define ADC_CHANELL_2   0b00010
#define ADC_CHANELL_3   0b00011
#define ADC_CHANELL_4   0b00100
#define ADC_CHANELL_5   0b00101
#define ADC_CHANELL_6   0b00110
#define ADC_CHANELL_7   0b00111

void ADC_voidInit(void);
void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus);

#endif