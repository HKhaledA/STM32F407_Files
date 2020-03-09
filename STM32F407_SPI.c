
#include "STM32F407_SPI.h"



void SPI_Disable(volatile SPI_Module  *  Spi_toDis)
{
	/* Disable Spi , it can be reenabled by Spi_init */
	Spi_toDis ->SPI_CR1 &= (uint16) ~(1<<6);
}
void SPI_init(
								volatile SPI_Module  *  Spi_toEn,
								SPI_OpMode OpMode,
								SPI_Prescaler Prescale,
								SPI_DataMode DataMode,
								SPI_DataFrame DFrame,
								SPI_ClkMode	ClkMode,
								SPI_Interrupts Interrupt)
								{
									/* Clear All Prev Settings  , Except CRC Settings*/
									Spi_toEn ->SPI_CR1 &= 0x3000 ;
									
									/* Clear All Prev Settings , Except Reserved Bits for Ensuring Compitability */
									Spi_toEn ->SPI_CR2 &= 0xF7; 
									
									/* Setting The Control Registers For The New Settings */
									Spi_toEn ->SPI_CR1 |= OpMode | Prescale | DataMode | DFrame | ClkMode ;
									Spi_toEn ->SPI_CR2 |= Interrupt;
									
									/* Enables SPI */
										Spi_toEn ->SPI_CR1 |= (1<<6);
									
								}

void SPI_CRC_Control (volatile SPI_Module  *  Spi_CR , SPI_CRC Statues )
{
			/* Clear Prev Selection of CRC */
			Spi_CR ->SPI_CR1 &= (uint16) ~ 0x3000;
	
			/* Set New Selection */
			Spi_CR ->SPI_CR1 |= Statues;
}

uint16 SPI_ReadErrorFlags(	volatile SPI_Module  *  Spi_CR)
{
				/* if it's  A Non - Zero Value This  indicates That an Error has Occured,
					 And Can be checked when Comparing to Error Flags enum */ 
	
				/* Zero Value means No Error */
					return Spi_CR ->SPI_SREG & SPI_ALL_ERR_FLAGS;
		
}


uint16 SPI_Exc_Data_MasterOnly(volatile SPI_Module  *  Spi_num ,uint16 Data , SPI_Handling Handle_case)
{
	
	if(Handle_case == polling)
	{
		
	/* Make Sure That There is No Data At The Tx Buffer */
		while (  Spi_num ->SPI_SREG & SPI_TX_BUFFER_EMPTY){}
	
	}
	/* Start Sending By Setting The Data to Tx Reg */
	Spi_num ->SPI_DREG = Data;
	
	if (Handle_case != polling)
	{
		/* will let the interrupt handle when to Rcv Data , Accep this Function return , only in ISR Code */
			return 0;
	}
	
	/* Wait until The Rx Data become Available , if You're Interrupting The Cpu When Rx Comment This Line  */
	while ( ! Spi_num ->SPI_SREG & SPI_RX_BUFFER_HAVEDATA ){}
	/* Return Recivied Value */
	return Spi_num -> SPI_DREG;
	
	
}
void 	SPI_WriteData( volatile SPI_Module  *  Spi_num ,uint16 Data ,SPI_Handling Handle_case)
{
	if(Handle_case == polling)
	{
		
	/* Make Sure That There is No Data At The Tx Buffer */
		while (  Spi_num ->SPI_SREG & SPI_TX_BUFFER_EMPTY){}
	
	}
	/* Start Sending By Setting The Data to Tx Reg */
	Spi_num ->SPI_DREG = Data;

}
uint16 SPI_ReadData_polling(volatile SPI_Module  *  Spi_num ,SPI_Handling Handle_case)
{
		
	if (Spi_num ->SPI_CR1 & SPI_MASTER)
	{
			/* -1 is Dummy Data in order ro init Clock  , only in Master Case  */
			Spi_num -> SPI_DREG = 0 ;
	}

	/* Wait until The Rx Data become Available , if You're Interrupting The Cpu When Rx Comment This Line  */
	while ( ! Spi_num ->SPI_SREG & SPI_RX_BUFFER_HAVEDATA ){}
	/* Return Recivied Value */
	return Spi_num -> SPI_DREG;
	
}
								
uint16 SPI_ReadData_ForISRs(volatile SPI_Module  *  Spi_num ,SPI_Handling Handle_case)
{
		
	/* Return Recivied Value */
	return Spi_num -> SPI_DREG;
	
}

void SPI_NSS_Control(volatile SPI_Module * Spi_CR , Dsignals State_NSS)
{
	/* this Acutally Might be used with Master as it's Recommended that it's kept High in master Mode */
	
	 if ( Spi_CR ->SPI_CR1 & 0x0200)
	 {
		 Spi_CR ->SPI_CR1 |= 0x0200;
	 }
	 
	 if (State_NSS ) 
	 {
		 Spi_CR ->SPI_CR1 |= 0x0100;
	 }
	 else
	 {
		 Spi_CR ->SPI_CR1 &= (uint16) ~ 0x0100;
	 }
}

void SPI_ChangeDataFrame( volatile SPI_Module  *  Spi_num ,SPI_DataFrame  Setting)
{
	Spi_num -> SPI_CR1 =   (Spi_num ->SPI_CR1 & ~(0x0880)) | Setting ;
	
}


void SPI_Interrupt_Control(volatile SPI_Module  *  Spi_num ,SPI_Interrupts Interrupt)
{
	
	Spi_num -> SPI_CR2 = (Spi_num ->SPI_CR2 & (~(0x70))) | Interrupt ;
}

