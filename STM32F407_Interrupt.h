
#ifndef _interrupt_Stm32F407_
	#define _interrupt_Stm32F407_
	
#include "STM32F407_DIO.h"
#include "CORE_STM32F407.h"
#include "STM32F407_uC.h"
#include "STD_TYPES.h"


	#define EXTI ( (volatile EXTI_Regs *  ) EXTI_BASE)
	/* Interrupt Reg Definition */


typedef struct 
			{
				volatile uint32 INTMASK;
				volatile uint32 EventMASK;
				volatile uint32 RisingSelection;
				volatile uint32 FallingSelection;
				volatile uint32 SW_Interrupt;
				volatile uint32 PendingReg;
				
			}EXTI_Regs;

			



typedef enum 
{
	MR0=0x000000,
	MR1=0x000001, MR2=0x000002, MR3=0x000004, MR4=0x000008,
	MR5=0x000010, MR6=0x000020, MR7=0x000040, MR8=0x000080,
	MR9=0x000100, MR10=0x000200,MR11=0x000400,MR12=0x000800,
	MR13=0x001000,MR14=0x002000,MR15=0x004000,MR16=0x008000,
	MR17=0x010000,MR18=0x020000,MR19=0x040000,MR20=0x080000,
	MR21=0x100000,MR22=0x200000,
	
}EXINT_MaskRegs;

typedef enum 
{
	RISING,
	FALLING,
	LOGICALCHANGE,
	
}EXTINT_Trig;

void EXTINT_Enable(Pins pin_no , IRQn_Type Type , EXTINT_Trig Trig);

void EXTINT_Disable(Pins pin_no );

void EXTINT_ClearPending(Pins pin_no);


#endif 
