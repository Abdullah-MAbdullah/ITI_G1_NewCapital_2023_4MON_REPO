#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"


void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_GPIOA);
	MGPIO_voidSetPinMode(MGPIO_PORTA, 0, 1);
	MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, 0, 0);
	MGPIO_voidSetPinOutputType(MGPIO_PORTA, 0, 0);
	while(1)
	{
		MGPIO_voidSetPinValue(MGPIO_PORTA, 0, LOW);
		MGPIO_voidSetPinValue(MGPIO_PORTA, 0, HIGH);
	}
}
