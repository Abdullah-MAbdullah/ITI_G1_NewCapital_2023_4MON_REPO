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
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define     RIGHT_ADJUST            0
#define     LEFT_ADJUST             1

// #define     AREF                    0
// #define     AVCC                    1
// #define     INTERNAL_2v56           2

#define AREF                0b00000000
#define AVCC                0b01000000
#define INTERNAL_2v56       0b11000000

#define REF_SEL_BIT_MASK        0b00111111 
#define PRES_SEL_MASK           0b11111000
#define CHANNEL_SELECTION_MASK  0b11100000

#define PRE_DIV_BY_2        0b00000000
#define PRE_DIV_BY_4        0b00000010
#define PRE_DIV_BY_8        0b00000011
#define PRE_DIV_BY_16       0b00000100
#define PRE_DIV_BY_32       0b00000101
#define PRE_DIV_BY_64       0b00000110
#define PRE_DIV_BY_128      0b00000111

#define     DISABLE                 0
#define     ENABLE                  1


/****************************Register Description***********************************/
#define     ADMUX           *((volatile u8 *)0x27)  // ADC Multiplixer Selection Register
#define     ADMUX_MUX0      0                       // ADC Muliplixer Bit 0
#define     ADMUX_MUX1      1                       // ADC Muliplixer Bit 1
#define     ADMUX_MUX2      2                       // ADC Muliplixer Bit 2
#define     ADMUX_MUX3      3                       // ADC Muliplixer Bit 3
#define     ADMUX_MUX4      4                       // ADC Muliplixer Bit 4
#define     ADMUX_ADLAR     5                       // ADC Left Adjust Result
#define     ADMUX_REFS0     6                       // ADC Reference Selection Bit 0
#define     ADMUX_REFS1     7                       // ADC Reference Selection Bit 1

#define     ADCSRA           *((volatile u8 *)0x26)  // ADC Control and Status Register
#define     ADCSRA_ADPS0     0                       // ADC Prescaler Selection bit 0 
#define     ADCSRA_ADPS1     1                       // ADC Prescaler Selection bit 1
#define     ADCSRA_ADPS2     2                       // ADC Prescaler Selection bit 2
#define     ADCSRA_ADIE      3                       // ADC Interrupt Enable Bit
#define     ADCSRA_ADIF      4                       // ADC Interrupt Flag Bit
#define     ADCSRA_ADATE     5                       // ADC Auto Trigger Enable bit
#define     ADCSRA_ADSC      6                       // ADC Start Conversion bit
#define     ADCSRA_ADEN      7                       // ADC Enable Bit

#define     ADCH             *((volatile u8 *)0x25)  // ADC High Register (8-bit)
#define     ADCL             *((volatile u8 *)0x24)  // ADC Low Register  (8-bit)
#define     ADC              *((volailte u16 *)0x24) // ADC Register      (16-bit)


#endif