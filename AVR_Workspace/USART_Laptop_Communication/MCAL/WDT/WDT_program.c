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
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_voidEnable(void)
{
    /*Set The WDE Bit To Enable The WatchDog Timer*/
    SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_voidSleep(u8 Copy_u8TimeOut)
{
    /*Mask (Clear) The First Three Bits In WDTCR (WDP2:0)*/
    WDTCR &= 0b11111000;
    /*Set The Timout To WDT*/
    WDTCR |= Copy_u8TimeOut;
}

void WDT_voidDisable(void)
{
    /*WDT Disbale Sequence:
    *   1- WDTOE, WDE -> 1 @ The Same Time
    *   2- Write 0 In WDE -> Within The Next Four Clock Cycles */
   WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
   WDTCR = 0;
}