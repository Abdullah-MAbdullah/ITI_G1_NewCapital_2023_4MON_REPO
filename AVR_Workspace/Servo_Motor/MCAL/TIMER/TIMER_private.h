/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   11 APR, 2023
 * Version:         v2.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         09 APR, 2023    Abdullah M. Abdullah          Initial Creation
 * v2.0         11 APR, 2023    Abdullah M. Abdullah          Add Timer1 APIs
*********************************************/

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

/****************************************** TIMER 0 REGISTERS *************************************/
#define     TCCR0		      *((volatile u8 *)(0x53))		// Timer/Counter0 Control Register
#define     TCCR0_FOC0        7								// Force On Compare
#define     TCCR0_WGM00       6                             // Wave Generation Mode 0
#define     TCCR0_COM01       5                             // Compare match output mode 1
#define     TCCR0_COM00       4                             // Compare match output mode 0
#define     TCCR0_WGM01       3                             // Wave Generation Mode 1
#define     TCCR0_CS02        2                             // Clock Select 02
#define     TCCR0_CS01        1                             // Clock Select 01
#define     TCCR0_CS00        0                             // Clock Select 00

#define     TCNT0		      *((volatile u8 *)(0x52))		// Timer/Counter0 Register

#define     OCR0		      *((volatile u8 *)(0x5C))		// Output Compare0 Register

#define     TIMSK		      *((volatile u8 *)(0x59))		// Timer0 Mask Register
#define     TIMSK_TOIE0       0								// Timer Overflow Interrupt Enable
#define     TIMSK_OCIE0       1                             // Timer On Compare Interrupt Enable

#define     TIFR              *((volatile u8 *)(0x58))		// Timer/Counter0 Interrupt Flag
#define     TIFR_TOV0         0								// Timer/Counter0 Overflow flag
#define     TIFR_OCF0         1                             // Timer/Counter0 Output Compare flag
/****************************** TIMER 1 ***************************************/
#define     TCCR1A              *((volatile u8 *)(0x4F))		// Timer/Counter1 A Control Register
#define     TCCR1A_WGM10        0                               // WaveGeneration Mode Bit 0
#define     TCCR1A_WGM11        1                               // WaveGeneration Mode Bit 1
#define     TCCR1A_FOC1B        2                               // Force Output Compare 1 Channel B
#define     TCCR1A_FOC1A        3                               // Force Output Compare 1 Channel A
#define     TCCR1A_COM1B0       4                               // Compare Output Mode 1 Channel B Bit 0
#define     TCCR1A_COM1B1       5                               // Compare Output Mode 1 Channel B Bit 1
#define     TCCR1A_COM1A0       6                               // Compare Output Mode 1 Channel A Bit 0
#define     TCCR1A_COM1A1       7                               // Compare Output Mode 1 Channel A Bit 1

#define     TCCR1B              *((volatile u8 *)(0x4E))		// Timer/Counter 1 B Control Register
#define     TCCR1B_CS10         0                               // Timer/Counter 1 Clock Selection Bit 0
#define     TCCR1B_CS11         1                               // Timer/Counter 1 Clock Selection Bit 1
#define     TCCR1B_CS12         2                               // Timer/Counter 1 Clock Selection Bit 2
#define     TCCR1B_WGM12        3                               // WaveGeneration Mode Bit 0
#define     TCCR1B_WGM13        4                               // WaveGeneration Mode Bit 1
#define     TCCR1A_ICES1        6                               // Timer/Counter 1 Input Capture Edge Selection
#define     TCCR1A_ICNC1        7                               // Timer/Counter 1 Input Capture Noise Cancellation

#define     TCNT1               *((volatile u16 *)0x4C)         // Timer/Counter 1 Regsiter
#define     OCR1A               *((volatile u16 *)0x4A)         // Timer/Counter 1 Output Compare Regsiter Channel A
#define     OCR1B               *((volatile u16 *)0x48)         // Timer/Counter 1 Output Compare Regsiter Channel B
#define     ICR1                *((volatile u16 *)0x46)         // Timer/Counter 1 Input Capture Register



#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
