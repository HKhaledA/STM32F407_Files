#include  "STM32F407_DIO.h"



void Input_Config(volatile GPIO * port,Pins pin_no,GPIO_inResistance Res)
{
	/* Clearing The Moder  Prev Selection , and set it to input */ 
	port ->GPIO_MODER &= 	(uint32)~(TWO_BIT_CODE << (pin_no*TWO_BIT_SHIFT));
	port ->GPIO_MODER |= 	(INPUTMODE << (pin_no*TWO_BIT_SHIFT));
	
	/* Clearing The PUPDR Prev Selection , and set it to Current Selection */
	port ->GPIO_PUPDR &=  (uint32)~(TWO_BIT_CODE<< (pin_no * TWO_BIT_SHIFT));
	port -> GPIO_PUPDR |= (Res << (pin_no*TWO_BIT_SHIFT) );
	
}
						
									
void Output_Config( volatile GPIO * port, Pins pin_no, OUT_mode Omode, outputspeed Speed, GPIO_inResistance Res)
{
		/* Clearing The Moder  Prev Selection , and set it to OUTPUT */ 
	port ->GPIO_MODER &= 	(uint32)~(TWO_BIT_CODE << (pin_no*TWO_BIT_SHIFT));
	port ->GPIO_MODER |= 	(OUTPUTMODE << (pin_no*TWO_BIT_SHIFT));

	/* Clearing The OMode Prev Selection , and Set Current Selection */
	port ->GPIO_OUTTYPER &= (uint32) ~(ONE_BIT_CODE << pin_no);
	port ->GPIO_OUTTYPER |= (Omode << pin_no);
	
			/* Clearing The Out Speed  Prev Selection , and set it to Current Selection */ 
	port ->GPIO_OUTSPEEDER &= 	(uint32)~(TWO_BIT_CODE << (pin_no*TWO_BIT_SHIFT));
	port ->GPIO_OUTSPEEDER |= 	(Speed << (pin_no*TWO_BIT_SHIFT));

	
		/* Clearing The PUPDR Prev Selection , and set it to Current Selection */
	port ->GPIO_PUPDR &=  (uint32)~(TWO_BIT_CODE<< (pin_no * TWO_BIT_SHIFT));
	port -> GPIO_PUPDR |= (Res << (pin_no*TWO_BIT_SHIFT) );
}

void AFunction_Config(volatile GPIO * port, GPIO_AFcontrol AF_number, Pins pin_no,GPIO_inResistance Res)
{
	
	/* Checking The pin is in AFRL or AFRH */
	if (pin_no >7)
	{
					/* Clearing The ALternate Function   Prev Selection , and set it to Current */ 
					port ->GPIO_AFRH &= 	(uint32)~(FOUR_BIT_CODE << (pin_no*FOUR_BIT_SHIFT));
					port ->GPIO_AFRH |= 	(AF_number << (pin_no*FOUR_BIT_SHIFT));

	}
	else
	{
			/* Clearing The ALternate Function   Prev Selection , and set it to Current */  
					port ->GPIO_AFRL &= 	(uint32)~(FOUR_BIT_CODE << (pin_no*FOUR_BIT_SHIFT));
					port ->GPIO_AFRL |= 	(AF_number << (pin_no*FOUR_BIT_SHIFT));

	}

				/* Clearing The PUPDR Prev Selection , and set it to Current Selection */
	port ->GPIO_PUPDR &=  (uint32)~(TWO_BIT_CODE<< (pin_no * TWO_BIT_SHIFT));
	port -> GPIO_PUPDR |= (Res << (pin_no*TWO_BIT_SHIFT) );
}

void Output_Write(volatile GPIO * port ,Pins pin_no , Dsignals Signal)
{
	if (Signal == HIGH)
	{
		port ->GPIO_ODR |= (ONE_BIT_CODE << pin_no);
	}
	else
	{
		port ->GPIO_ODR &= ~(uint32) (ONE_BIT_CODE << pin_no);
	}
	
}
	
Dsignals Input_Read(volatile GPIO * port ,Pins pin_no)
{
	if( port -> GPIO_IDR & (ONE_BIT_CODE << pin_no))
	{
		return HIGH;
	}
	
	
	return LOW;
}


