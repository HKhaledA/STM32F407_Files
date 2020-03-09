#ifndef __LED__H_
	#define __LED__H_
	
	#include "STM32F407_DIO.h"
	
	#define Board_GreenLED   GPIO_PIN12
	#define Board_OrangeLED  GPIO_PIN13
	#define Board_RedLED 		 GPIO_PIN14
	#define Board_BlueLED		 GPIO_PIN15
	
	#define Board_LEDPORT    (GPIOD)
	
	void LED_init(volatile GPIO * port , Pins pin_no);
	void LED_TurnOn(volatile GPIO * port , Pins pin_no);
	void LED_TurnOff(volatile GPIO * port , Pins pin_no);
	void LED_Toggle(volatile GPIO * port , Pins pin_no);

#endif
