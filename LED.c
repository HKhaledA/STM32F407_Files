
#include "LED.h"


void LED_init(volatile GPIO * port , Pins pin_no)
{
	Output_Config(port,pin_no,PUSHPULL,OUT_MEDIUMSPEED,RESISTANCE_DISABLED);
}
void LED_TurnOn(volatile GPIO * port , Pins pin_no)
{
	Output_Write(port,pin_no,HIGH);
}
void LED_TurnOff(volatile GPIO * port , Pins pin_no)
{
	Output_Write(port,pin_no,LOW);
}
void LED_Toggle(volatile GPIO * port , Pins pin_no)
{
	if(Input_Read(port,pin_no) == HIGH)
	{
		Output_Write(port,pin_no,LOW);
	}
	else
	{
		Output_Write(port,pin_no,HIGH);
	}
}
