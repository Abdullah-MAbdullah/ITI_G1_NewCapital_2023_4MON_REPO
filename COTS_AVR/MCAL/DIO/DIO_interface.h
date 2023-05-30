/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   25 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         25 MAR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_


#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define OUTPUT      1
#define INPUT       0

#define LOW         0
#define HIGH        1

#define PULLUP      1
#define NO_PULLUP   0

void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Direction);
u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState);
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortValue);
void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
