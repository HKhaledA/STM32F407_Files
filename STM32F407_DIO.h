#ifndef _STM32F407_DIO_
	#define _STM32F407_DIO_
	
	

	#include "STD_TYPES.h"
	#include "STM32F407_uC.h"
	#include "CORE_STM32F407.h"
	
	/* These Defines Are Used when Seting , Clearing Bits in Regs */
				#define ONE_BIT_CODE (0x1)
				#define TWO_BIT_CODE (0x3)
				#define FOUR_BIT_CODE (0xF)

				#define ONE_BIT_SHIFT	 (0x1)
				#define TWO_BIT_SHIFT (2)
				#define FOUR_BIT_SHIFT (4)
		
	


		
		
		/* GPIO Declaration */
		#define GPIOA ((volatile GPIO *)GPIOA_BASE)
		#define GPIOB ((volatile GPIO *)GPIOB_BASE)
		#define GPIOC ((volatile GPIO *)GPIOC_BASE)
		#define GPIOD ((volatile GPIO *)GPIOD_BASE)
		#define GPIOE ((volatile GPIO *)GPIOE_BASE)
		#define GPIOF ((volatile GPIO *)GPIOF_BASE)
		#define GPIOG ((volatile GPIO *)GPIOG_BASE)
		#define GPIOH ((volatile GPIO *)GPIOH_BASE)
		#define GPIOI ((volatile GPIO *)GPIOI_BASE)


typedef struct
{
	/* Moder Used To Select The IO Type "INPUT , Output , AF , Analog"
		 Each pin Corresponds to 2-bit */
	volatile uint32 GPIO_MODER;
	/* Out Typer is Used To Sepicifiy The output Mode " push Pull , open Drain " */
	volatile uint32 GPIO_OUTTYPER;
	/* Speeder  is used to Select The Output Speed " Low , Med , High , VHigh "  */
	volatile uint32 GPIO_OUTSPEEDER;
		/* PUPDR is used to Enable/Disable Pull up/Down Resisitance at all modes */
	volatile uint32 GPIO_PUPDR;
	/* IDR is used to Read incoming Digital input  signals  */
	volatile uint32 GPIO_IDR;
	/* ODR is used To Control Digital Output signals */
	volatile uint32 GPIO_ODR;
	/* SET/RESET Reg is used to Set , Reset a Digital Output pin , IDK why */
	volatile uint32 GPIO_SETRESET;
	/* Locker Reg is used to provide protection for GPIO bit Config Settings
		 if a Bit is Locked then it's setting will not be reconfig tell a new reset for MCU or peripheral*/
	volatile uint32 GPIO_LOCKER;
	/* Alternate Function low Reg is Used to Enable / Disable  Alternate Functions "4-bits"
			Only Control The first 8- pins in a PORT*/
	volatile uint32 GPIO_AFRL;
	/* Alternate Function High Reg is Used to Enable / Disable  Alternate Functions "4-bits"
			Only Control The Last 8- pins in a PORT*/
	volatile uint32 GPIO_AFRH;
	
}GPIO;

	/* The Enums for LOCKER and SETREST isnot Done Yet */
typedef enum 
{
	INPUTMODE,
	OUTPUTMODE,
	ALTERNATEMODE,
	ANALOGMODE,
}IO_mode;

typedef enum 
{
	PUSHPULL,
	OPENDRAIN,
}OUT_mode;
typedef enum 
{
	OUT_LOWSPEED,
	OUT_MEDIUMSPEED,
	OUT_HIGHSPEED,
	OUT_VERYHIGHSPEED,
}outputspeed;

typedef enum 
{
	RESISTANCE_DISABLED,
	RESISTANCE_PULLUP,
	RESISTANCE_PULLDOWN,
}GPIO_inResistance;

typedef enum 
{
	LOW,
	HIGH,
}Dsignals;

typedef enum
{
	AF0,AF1,AF2,AF3,
	AF4,AF5,AF6,AF7,
	AF8,AF9,AF10,AF11,
	AF12,AF13,AF14,AF15
}GPIO_AFcontrol;


typedef enum 
{
	GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,
	GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7,
	GPIO_PIN8,GPIO_PIN9,GPIO_PIN10,GPIO_PIN11,
	GPIO_PIN12,GPIO_PIN13,GPIO_PIN14,GPIO_PIN15,
}Pins;

void Input_Config(
									volatile GPIO * port,
									Pins pin_no,
									GPIO_inResistance Res);
									
void Output_Config(
									volatile GPIO * port,
									Pins pin_no,
									OUT_mode Omode,
									outputspeed Speed,
									GPIO_inResistance Res);
									
void AFunction_Config(
									volatile GPIO * port,
									GPIO_AFcontrol AF_number,
									Pins pin_no,
									GPIO_inResistance Res);
//void Analog_Config();

void Output_Write(volatile GPIO * port ,Pins pin_no , Dsignals Signal);
	
Dsignals Input_Read(volatile GPIO * port ,Pins pin_no);
									

#endif
