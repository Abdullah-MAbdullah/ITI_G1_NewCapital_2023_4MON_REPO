/*
 * LED_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Osama.Mahmoud
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_



typedef struct {

	u8 LED_PORT;
	u8 LED_PIN;

}LED_t;

void LED_voidInit(LED_t* Ledobj);
void LED_voidTurnOn(LED_t* Ledobj);
void LED_voidTurnOff(LED_t* Ledobj);
//void LED_voidToggle(LED_t* Ledobj);

#endif /* HAL_LED_LED_INTERFACE_H_ */
