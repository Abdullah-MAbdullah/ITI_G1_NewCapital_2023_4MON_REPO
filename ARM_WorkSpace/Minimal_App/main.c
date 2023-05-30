#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
extern u8 x;
void main(void)
{
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(MRCC_AHB1, MRCC_GPIOA);
    MGPIO_voidSetPinMode(MGPIO_PORTA, MGPIO_PIN0, MGPIO_OUTPUT);

    MGPIO_voidSetPinValue(MGPIO_PORTA, MGPIO_PIN0, MGPIO_OUTPUT_HIGH);

}