/*
 * EXTI_private.h
 *
 *  Created on: Mar 29, 2023
 *      Author: Osama
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

/* Pins Connections on Hardware */
#define EXTI0_PORT   DIO_PORTD
#define EXTI0_PIN    PIN2

/* Pins Connections on Hardware */
#define EXTI1_PORT   DIO_PORTD
#define EXTI1_PIN    PIN3

/* Pins Connections on Hardware */
#define EXTI2_PORT   DIO_PORTB
#define EXTI2_PIN    PIN2

#define INTERNAL_PULLUP    0
#define EXTERNAL_PULLUP    1
#define EXTERNAL_PULLDOWN   2
/*
 * MCU Control Register
 */
#define MCUCR   *( (volatile u8*) 0x55)
#define MCUCR_ISC11   3
#define MCUCR_ISC10   2
#define MCUCR_ISC01   1
#define MCUCR_ISC00   0

/*
 * MCU Control and Status Register
 */
#define MCUCSR  *( (volatile u8*) 0x54)
#define MCUCSR_ISC2  	6

/*
 * General Interrupt Control Register
 */
#define GICR    *( (volatile u8*) 0x5B)
#define GICR_INT1   	7
#define GICR_INT0  	    6
#define GICR_INT2  	    5


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
