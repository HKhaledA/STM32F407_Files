
#include "STM32F407_Interrupt.h"


void EXTINT_Enable(Pins pin_no , IRQn_Type Type , EXTINT_Trig Trig)
{
	switch(Trig)
	{
		case RISING:
									/* Clearing The Falling Prev Selection */
									EXTI ->FallingSelection &=~ (ONE_BIT_CODE<<pin_no);
									/* Setting The Current Trig To Rising */
									EXTI->RisingSelection |= (ONE_BIT_CODE<< pin_no);
									break;
		
		case FALLING:
										/* Clearing The Rising Prev Selection */
									EXTI ->RisingSelection &=~ (ONE_BIT_CODE<<pin_no);
											/* Setting The Current Trig To Rising */
									EXTI ->FallingSelection |= (ONE_BIT_CODE<< pin_no);
									break;
		
		case LOGICALCHANGE:
											/* Setting The Current Trig To Rising & Falling */
										EXTI->RisingSelection |= (ONE_BIT_CODE<< pin_no);
										EXTI ->FallingSelection |= (ONE_BIT_CODE<< pin_no);
										break;
		default:
							return;
	}
	
	
	EXTI ->INTMASK |= (ONE_BIT_CODE << pin_no);
	NVIC_EnableIRQ(Type);
	
}

void EXTINT_Disable(Pins pin_no)
{
	EXTI ->INTMASK &= (uint32) ~(ONE_BIT_CODE<<pin_no);
}

void EXTINT_ClearPending(Pins pin_no)
{
	if ( EXTI ->PendingReg  & (ONE_BIT_CODE << pin_no))
	{
		EXTI ->PendingReg |= (ONE_BIT_CODE << pin_no);
	}
}
