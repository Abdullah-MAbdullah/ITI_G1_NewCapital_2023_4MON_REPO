/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   12 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         12 APR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/
#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H


// #define SLEEP_16_3MS        0b000

#define     WDTCR           *((volatile u8 *)0x41)          // WatchDog Timer Control Register
#define     WDTCR_WDP0      0                               // WatchDog Timer Prescaler Bit 0
#define     WDTCR_WDP1      1                               // WatchDog Timer Prescaler Bit 1
#define     WDTCR_WDP2      2                               // WatchDog Timer Prescaler Bit 2
#define     WDTCR_WDE       3                               // WatchDog Timer Enable Bit
#define     WDTCR_WDTOE     4                               // WatchDog Timer Turn-Off Enable Bit



#endif