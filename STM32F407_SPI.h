#ifndef  	_STM32_F407_SPI_H_
	#define	_STM32_F407_SPI_H_

	#include "STM32F407_DIO.h"
	#include "STD_TYPES.h"
	#include "STM32F407_uC.h"
	#include "STM32F407_Interrupt.h"
	
	
	#define SPI1 ((volatile SPI_Module * ) SPI1_BASE)
	#define SPI2 ((volatile SPI_Module * ) SPI2_BASE)
	#define SPI3 ((volatile SPI_Module * ) SPI3_BASE)
	#define SPI4 ((volatile SPI_Module * ) SPI4_BASE)

typedef struct 
{
	volatile uint32 SPI_CR1;
	volatile uint32 SPI_CR2;
	volatile uint32 SPI_SREG;
	volatile uint32 SPI_DREG;
	volatile uint32 SPI_CRC_PR;
	volatile uint32 SPI_RX_CRC;
	volatile uint32 SPI_TX_CRC;
	volatile uint32 SPI_I2S_CFGR;
	volatile uint32 SPI_I2S_PR;
	
}SPI_Module;


typedef enum 
{
	SPI_MASTER=0x0004,
	SPI_SLAVE_SW_MANGMENT=0x0200,
	SPI_SLAVE_MANUAL_MANGMENT=0x0000,
	
	
}SPI_OpMode;

typedef enum 
{
	SPI_BIDIR_FULL_DUBLEX=0x000,
	SPI_BIDIR_RXONLY=0x0400,
	SPI_HALF_DUBLEX_RXEN=0x8000,
	SPI_HALF_DUBLEX_TXEN=0xC000,
	
}SPI_DataMode;

typedef enum 
{
	SPI_CRC_DISABLED,
	SPI_CRC_ENABLED=0x2000,
}SPI_CRC;

typedef enum 
{
	SPI_8BIT_DATA_LSBFIRST=0x0080,
	SPI_8BIT_DATA_MSBFIRST=0x0000,
	SPI_16BIT_DATA_LSBFIRST=0x0880,
	SPI_16BIT_DATA_MSBFIRST=0x0800,
}SPI_DataFrame;

typedef enum
{
	SPI_CLKMODE0=0x0000,
	SPI_LEAD_FALL_SETUP=0x0000,
	
	SPI_CLKMODE1=0x0001,
	SPI_LEAD_RISE_SETUP=0x0001,
	
	SPI_CLKMODE2=0x0002,
	SPI_LEAD_FALL_SAMPLE=0x0002,
	
	SPI_CLKMODE3=0x0003,
	SPI_LEAD_RISE_SAMPLE=0x0002,
	
}SPI_ClkMode;

typedef enum
{
	SPI_PRESCALE_2  = 0x0000,
	SPI_PRESCALE_4  = 0x0008,
	SPI_PRESCALE_8  = 0x0010,
	SPI_PRESCALE_16 = 0x0018,
	SPI_PRESCALE_32 = 0x0020,
	SPI_PRESCALE_64 = 0x0028,
	SPI_PRESCALE_128= 0x0030,
	SPI_PRESCALE_256= 0x0038,
	
}SPI_Prescaler;

typedef enum 
{
	
	SPI_INT_DISABLE=0x00,
	SPI_TX_BUFF_EMPTY_INT=0x80,
	SPI_RX_DATAPRESENT_INT=0x40,
	SPI_ERROR_INT=0x20,
	
	SPI_TX_RX_INT=0xc0,
	SPI_TX_ERROR_INT=0xA0,
	SPI_RX_ERROR_INT=0x60,
	
	SPI_TX_RX_ERROR_INT=0xE0,
	
}SPI_Interrupts;



typedef enum 
{
	SPI_RX_BUFFER_HAVEDATA 	= 0x0001,
	SPI_TX_BUFFER_EMPTY			=	0x0002,
	SPI_CHSIDE_FLAG   			=	0x0004,
	SPI_UNDERRUN_FLAG 			=	0x0008,
	SPI_CRCERROR_FLAG 			= 0x0010,
	SPI_MODEFAULT_FLAG			=	0x0020,
	SPI_OVERRUN_FLAGG				=	0x0040,
	SPI_BUSY_FLAG						=	0x0080,
	SPI_FRAME_ERROR_FLAG		=	0x0100,
	SPI_ALL_ERR_FLAGS 			=	0x01FC,
}SPI_StatusREg;

typedef enum 
{
	polling,
	interrupting,
}SPI_Handling;
void SPI_init(
								volatile SPI_Module  *  Spi_toEn,
								SPI_OpMode OpMode,
								SPI_Prescaler Prescale,
								SPI_DataMode DataMode,
								SPI_DataFrame DFrame,
								SPI_ClkMode	ClkMode,
								SPI_Interrupts Interrupt);

void SPI_CRC_Control (volatile SPI_Module  *  Spi_CR , SPI_CRC Statues );

void SPI_NSS_Control(volatile SPI_Module * Spi_CR , Dsignals State_NSS);
								
uint16 SPI_ReadErrorFlags(	volatile SPI_Module  *  Spi_CR);

uint16 SPI_Exc_Data_MasterOnly(volatile SPI_Module  *  Spi_num ,uint16 Data ,SPI_Handling Handle_case );
void 	SPI_WriteData( volatile SPI_Module  *  Spi_num ,uint16 Data,SPI_Handling Handle_case);
uint16 SPI_ReadData(volatile SPI_Module  *  Spi_num ,SPI_Handling Handle_case);
	
void SPI_Disable(volatile SPI_Module  *  Spi_toDis);
								
void SPI_Interrupt_Control( volatile SPI_Module  *  Spi_num ,SPI_Interrupts Interrupt);
void SPI_ChangeDataFrame( volatile SPI_Module  *  Spi_num ,SPI_DataFrame  Setting);
								
#endif
