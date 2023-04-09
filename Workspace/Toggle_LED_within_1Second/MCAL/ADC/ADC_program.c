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
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

static void (*ADC_pvoidNotificationFunction)(void) = NULL;
volatile u16 ADC_u16DigitalResult = 0;

void ADC_voidInit(void)
{
    /*Check For The ADC Enable*/
    #if ADC_ENABLE  == ENABLE
        SET_BIT(ADCSRA, ADCSRA_ADEN);
    #elif ADC_ENABLE == DISABLE
        CLR_BIT(ADCSRA, ADCSRA_ADEN);
    #else
        #error "Error, ADC_ENABLE Configuration Error"
    #endif

    /*Check For The ADC Interrupt*/ 
    #if ADC_INTERRUPT_STATUS == ENABLE
        SET_BIT(ADCSRA, ADCSRA_ADIE);
    #elif ADC_INTERRUPT_STATUS == DISABLE
        CLR_BIT(ADCSRA, ADCSRA_ADIE);
    #else
        #error("Error, ADC_INTERRUPT_ENABLE Configuration Error")
    #endif

    /*Set The Reference Selection Option Using Bit Masking*/
    ADMUX &= REF_SEL_BIT_MASK;
    ADMUX |= ADC_REFERENCE_SELECTION;

    /*Check For The ADC Adjust Result*/
    #if ADC_ADJUST_RESULT == RIGHT_ADJUST
        CLR_BIT(ADMUX, ADMUX_ADLAR);
    #elif ADC_ADJUST_RESULT == LEFT_ADJUST
        SET_BIT(ADMUX, ADMUX_ADLAR);
    #else
        #error("Error, ADC_ADJUST_RESULT Confiuration Error")
    #endif

    /* Set The Prescaler Values*/
    ADCSRA &= PRES_SEL_MASK;
    ADCSRA |= ADC_PRESCALER_VALUE;
}


void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus)
{
    switch(Copy_u8InterruptStatus)
    {
        case DISABLE:
            CLR_BIT(ADCSRA, ADCSRA_ADIE);
        break;

        case ENABLE:
            SET_BIT(ADCSRA, ADCSRA_ADIE);
        break;

        default:
            /*Do Noting*/
        break;
    }
}

u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber) 
{
    u8 Local_u8DigitalValue;
    /*Set The Channel Of ADC*/
    ADMUX &= CHANNEL_SELECTION_MASK;
    ADMUX |= Copy_u8ChannelNumber;
    
    /*Start The ADC To Convert The Input Analog Signal*/
    SET_BIT(ADCSRA, ADCSRA_ADSC);
    /*Polling (busy wait) till the flag is raised*/
    while(GET_BIT(ADCSRA, ADCSRA_ADIF) == FALSE);
    /*Clear The Flag*/
    SET_BIT(ADCSRA, ADCSRA_ADIF);

    /*Check For Left or Right Adjust*/
    #if ADC_ADJUST_RESULT == LEFT_ADJUST
        Local_u8DigitalValue =  ADCH;
    #elif ADC_ADJUST_RESULT == RIGHT_ADJUST
        Local_u8DigitalValue =  ADCL;
    #endif

    /*Return The Digital Value*/
    return Local_u8DigitalValue;
}


void ADC_voidStartConversionAsynchronous(u8 Copy_u8ChannelNumber, void (*NotifiFunction)(void))
{
    /*Set The Channel Of ADC*/
    ADMUX &= CHANNEL_SELECTION_MASK;
    ADMUX |= Copy_u8ChannelNumber;
    /*Set Callback Functoion in the global pointer to function*/
    ADC_pvoidNotificationFunction = NotifiFunction;
    /*Start The ADC To Convert The Input Analog Signal*/
    SET_BIT(ADCSRA, ADCSRA_ADSC);
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
    ADC_voidInterruptControl(DISABLE);
    ADC_u16DigitalResult = ADCH;
    if(ADC_pvoidNotificationFunction != NULL)
    {
        ADC_pvoidNotificationFunction();
    }
    else
    {
        /* Do Nothing*/
    }
    ADC_voidInterruptControl(ENABLE);
}


