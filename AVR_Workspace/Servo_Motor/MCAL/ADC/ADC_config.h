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
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*Options: 
        LEFT_ADJUST
        RIGHT_ADJUST
*/
#define     ADC_ADJUST_RESULT           LEFT_ADJUST

/*Options:
        AREF
        AVCC
        INTERNAL_2v56
*/
#define     ADC_REFERENCE_SELECTION     AREF
/*Options:
                PRE_DIV_BY_2  
                PRE_DIV_BY_4  
                PRE_DIV_BY_8  
                PRE_DIV_BY_16 
                PRE_DIV_BY_32 
                PRE_DIV_BY_64 
                PRE_DIV_BY_128
*/
#define     ADC_PRESCALER_VALUE         PRE_DIV_BY_128

/*Options:
        ENABLE
        DISBALE
*/
#define     ADC_INTERRUPT_STATUS        ENABLE

/*Options:
        ENABLE
        DISBALE
*/
#define     ADC_ENABLE                  ENABLE


#endif