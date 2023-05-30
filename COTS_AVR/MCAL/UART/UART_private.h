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
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define         UDR             *((volatile u8 *)0x2C)          // USART Data Register

#define         UCSRA           *((volatile u8 *)0x2B)          // USART Control and Status Register A
#define         UCSRA_MPCM      0                               // MultiProcessing Communication
#define         UCSRA_U2X       1                               // USART Double Speed Mode Bit
#define         UCSRA_PE        2                               // Parity Error Flag Bit
#define         UCSRA_DOR       3                               // Data OverRun Flag Bit
#define         UCSRA_FE        4                               // Frame Error Flag Bit
#define         UCSRA_UDRE      5                               // UDR Register Empty Flag Bit
#define         UCSRA_TXC       6                               // Transmission Complete Flag Bit
#define         UCSRA_RXC       7                               // Receiption Complete Flag Bit


#define         UCSRB           *((volatile u8 *)0x2A)          // USART Control and Status Register B
#define         UCSRB_TXB8      0                               // Transmitted Data 9th Bit 
#define         UCSRB_RXB8      1                               // Received Data 9th Bit
#define         UCSRB_UCSZ2     2                               // USART Character Size Select Bit 2
#define         UCSRB_TXEN      3                               // Transmiter Enable
#define         UCSRB_RXEN      4                               // Receive Enable
#define         UCSRB_UDRIE     5                               // UDR Register Empty Interrupt Enable
#define         UCSRB_TXCIE     6                               // Transmission Complete Interrupt Enable
#define         UCSRB_RXCIE     7                               // Receiption Complete Interrupt Enable


#define         UCSRC           *((volatile u8 *)0x40)          // USART Control and Status Register C
#define         UCSRC_UCPOL     0                               // USART Clock Polarity
#define         UCSRC_UCSZ0     1                               // USART Character Size Select Bit 0
#define         UCSRC_UCSZ1     2                               // USART Character Size Select Bit 1
#define         UCSRC_USBS      3                               // USART Stop Bit Select
#define         UCSRC_UPM0      4                               // USART Parity Mode Select Bit 0
#define         UCSRC_UPM1      5                               // USART Parity Mode Select Bit 1
#define         UCSRC_UMSEL     6                               // USART Mode Select
#define         UCSRC_URSEL     7                               // USART Register Select


#define         UBRRL           *((volatile u8 *)0x29)          // USART BaudRate Register Low
#define         UBRRH           *((volatile u8 *)0x40)          // USART BaudRate Register High
#define         UBRRH_URSEL     7                               // USART Register Select


#endif