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
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#define WDT_SLEEP_16_3_MS       0b000
#define WDT_SLEEP_32_5_MS       0b001
#define WDT_SLEEP_65_0_MS       0b010

void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidSleep(u8 Copy_u8TimeOut);


#endif