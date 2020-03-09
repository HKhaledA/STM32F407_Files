#ifndef _STM32F407_ucConfig_h_
#define _STM32F407_ucConfig_h_




	/* Memory Map of The STm32F407  @ P64/P1747*/
	/* Peripheral Buss Address @ P65 */
		#define PERIPH_BASE           0x40000000U 	/*!< Peripheral base address in the alias region                                */
		#define APB1PERIPH_BASE       PERIPH_BASE
		#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000U)
		#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000U)
		#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000U)
		
		/*!< APB1 peripherals */
		#define TIMER2_BASE							(APB1PERIPH_BASE + 0x0000U)
		#define TIMER3_BASE							(APB1PERIPH_BASE + 0x0400U)
		#define TIMER4_BASE							(APB1PERIPH_BASE + 0x0800U)
		#define TIMER5_BASE							(APB1PERIPH_BASE + 0x0C00U)
		#define TIMER6_BASE						 	(APB1PERIPH_BASE + 0x1000U)
		#define TIMER7_BASE						  (APB1PERIPH_BASE + 0x1400U)
		#define TIMER12_BASE						(APB1PERIPH_BASE + 0x1800U)
		#define TIMER13_BASE						(APB1PERIPH_BASE + 0x1C00U)
		#define TIMER14_BASE						(APB1PERIPH_BASE + 0x2000U)
		
		#define RTC_BKP_BASE						(APB1PERIPH_BASE + 0x2800U)
		#define WWDG_BASE								(APB1PERIPH_BASE + 0x2C00U)
		#define IWDG_BASE								(APB1PERIPH_BASE + 0x3000U)
		#define I2SNEXT_BASE						(APB1PERIPH_BASE + 0x3400U)
		#define SPI2_BASE								(APB1PERIPH_BASE + 0x3800U)
		#define I2S2_BASE								(APB1PERIPH_BASE + 0x3800U)
		#define SPI3_BASE								(APB1PERIPH_BASE + 0x3C00U)
		#define I2S3_BASE								(APB1PERIPH_BASE + 0x3C00U)
		
		/*!< APB2 peripherals */
		#define TIMER1_BASE							(APB2PERIPH_BASE + 0x00000U)
		#define TIMER8_BASE							(APB2PERIPH_BASE + 0x00400U)
		#define USART1_BASE							(APB2PERIPH_BASE + 0x01000U)
		#define USART6_BASE							(APB2PERIPH_BASE + 0x01400U)
		#define ADC_1_2_3_BASE					(APB2PERIPH_BASE + 0x02000U)
		#define SDIO_BASE								(APB2PERIPH_BASE + 0x02C00U)
		#define SPI1_BASE								(APB2PERIPH_BASE + 0x03000U)
		#define SPI4_BASE								(APB2PERIPH_BASE + 0x03000U)
		#define SYSCFG_BASE							(APB2PERIPH_BASE + 0x03800U)
		#define EXTI_BASE             	(APB2PERIPH_BASE + 0x03C00U)
		
		
		/*!< AHB1 peripherals */
		#define GPIOA_BASE						(AHB1PERIPH_BASE + 0x0000 )
		#define GPIOB_BASE						(AHB1PERIPH_BASE + 0x0400 )
		#define GPIOC_BASE						(AHB1PERIPH_BASE + 0x0800 )
		#define GPIOD_BASE						(AHB1PERIPH_BASE + 0x0c00 )
		#define GPIOE_BASE						(AHB1PERIPH_BASE + 0x1000 )
		#define GPIOF_BASE						(AHB1PERIPH_BASE + 0x1400 )
		#define GPIOG_BASE						(AHB1PERIPH_BASE + 0x1800 )
		#define GPIOH_BASE						(AHB1PERIPH_BASE + 0x1c00 )
		#define GPIOI_BASE						(AHB1PERIPH_BASE + 0x2000 )
		#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800U)
		
		
		
				#define RCC		((volatile RCC__ *)RCC_BASE)
					
typedef struct 
{
	/*!< RCC clock control register,     			  Address offset: 0x00 */
	volatile uint32 RCC_ControlReg;	
	/*!< RCC PLL configuration register,  		  Address offset: 0x04 */	
  volatile uint32 RCC_PLLCFGR;
	/*!< RCC clock configuration register,	  	Address offset: 0x08 */	
  volatile uint32 RCC_CFGR;
	/*!< RCC clock interrupt register      	    Address offset: 0x0C */	
  volatile uint32 RCC_CIR;
	/*!< RCC AHB1 peripheral reset register,		Address offset: 0x10 */	
  volatile uint32 RCC_AHB1RSTR;    
	/*!< RCC AHB2 peripheral reset register,		Address offset: 0x14 */  
  volatile uint32 RCC_AHB2RSTR;      
	/*!< RCC AHB3 peripheral reset register,    Address offset: 0x18 */
  volatile uint32 RCC_AHB3RSTR;     
	/*!< Reserved, 0x1C */
  uint32      RESERVED0;     
	/*!< RCC APB1 peripheral reset register,    Address offset: 0x20 */
  volatile uint32 RCC_APB1RSTR;
  /*!< RCC APB2 peripheral reset register,    Address offset: 0x24 */	
  volatile uint32 RCC_APB2RSTR;     
	/*!< Reserved, 0x28-0x2C */
  uint32      RESERVED1[2];                                                          
	
	/*!< RCC AHB1 peripheral clock register,    Address offset: 0x30 */
  volatile uint32 RCC_AHB1ENR;   
	/*!< RCC AHB2 peripheral clock register,    Address offset: 0x34 */
  volatile uint32 RCC_AHB2ENR;      
	  /*!< RCC AHB3 peripheral clock register,  Address offset: 0x38 */
  volatile uint32 RCC_AHB3ENR;     
	/*!< Reserved, 0x3C  */
  uint32      RESERVED2;     
	
	/*!< RCC APB1 peripheral clock enable register,   Address offset: 0x40 */
  volatile uint32 RCC_APB1ENR;  
	 /*!< RCC APB2 peripheral clock enable register,  Address offset: 0x44 */
  volatile uint32 RCC_APB2ENR;      
	
  uint32      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  
	volatile uint32 RCC_AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile uint32 RCC_AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile uint32 RCC_AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  
	uint32      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  
	volatile uint32 RCC_APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile uint32 RCC_APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  
	uint32      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  
	volatile uint32 RCC_BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile uint32 RCC_CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  
	uint32      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  
	volatile uint32 RCC_SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile uint32 RCC_PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */

}RCC__;


typedef enum 
{
	RCC_HSI  					 = 0x0000001,
	RCC_HSE0 					 = 0x0008000,
	RCC_HSE_BYPASS     = 0x0020000,
	RCC_CLKSEC_SYSTEM  = 0x0040000,
	RCC_PLL            = 0x0800000,
	RCC_PLLI2S         = 0x2000000,
	
}RCC_ClockControl;

typedef enum 
{
	GPIOA_RESET=0x0001,
	GPIOB_RESET=0x0002,
	GPIOC_RESET=0x0004,
	GPIOD_RESET=0x0008,
	GPIOE_RESET=0x0010,
	GPIOF_RESET=0x0020,
	GPIOG_RESET=0x0040,
	GPIOH_RESET=0x0080,
	GPIOI_RESET=0x0100,
	GPIOJ_RESET=0x0200,
	GPIOK_RESET=0x0400,
	CRC_RESET=0x1000,
	DMA1_RESET=0x10000,
	DMA2_RESET=0x20000,
	DMA2D_RESET=0x40000,
	ETHMAC_RESET=0x80000,	
}RCC_AHB1_Reset;

typedef enum 
{
	GPIOA_CLOCK=0x0001,
	GPIOB_CLOCK=0x0002,
	GPIOC_CLOCK=0x0004,
	GPIOD_CLOCK=0x0008,
	GPIOE_CLOCK=0x0010,
	GPIOF_CLOCK=0x0020,
	GPIOG_CLOCK=0x0040,
	GPIOH_CLOCK=0x0080,
	GPIOI_CLOCK=0x0100,
	GPIOJ_CLOCK=0x0200,
	GPIOK_CLOCK=0x0400,
	CRC_CLOCK=0x1000,
	DMA1_CLOCK=0x10000,
	DMA2_CLOCK=0x20000,
	DMA2D_CLOCK=0x40000,	
}RCC_AHB1_CLOCK;


typedef  enum 
{
	TIMER2_CLOCK	=	0x00000001U,
	TIMER3_CLOCK	=	0x00000002U,
	TIMER4_CLOCK	=	0x00000004U,
	TIMER5_CLOCK	=	0x00000008U,
	TIMER6_CLOCK	=	0x00000010U,
	TIMER7_CLOCK	=	0x00000020U,
	TIMER12_CLOCK	=	0x00000040U,
	TIMER13_CLOCK	=	0x00000080U,
	TIMER14_CLOCK	=	0x00000100U,
	RESERVED1			=	0x00000200U,
	RESERVED2			=	0x00000400U,
	WWDG_CLOCK		=	0x00000800U,
	RESERVED3			=	0x00001000U,
	RESERVED4			=	0x00002000U,
	SPI2_CLOCK		=	0x00004000U,
	SPI3_CLOCK		=	0x00008000U,
	
	RESERVED5			=	0x00010000U,
	USART2_CLOCK	=	0x00020000U,
	USART3_CLOCK	=	0x00040000U,	
	USART4_CLOCK	=	0x00080000U,
	USART5_CLOCK	=	0x00100000U,
	I2C1_CLOCK		=	0x00200000U,
	I2C2_CLOCK		=	0x00400000U,
	I2C3_CLOCK		=	0x00800000U,
	RESERVED6			=	0x01000000U,
	CAN1_CLOCK		=	0x02000000U,
	CAN2_CLOCK		=	0x04000000U,
	RESERVED7			=	0x08000000U,
	PWR_CLOCK			=	0x10000000U,
	DAC_CLOCK			=	0x20000000U,
	UART7_CLOCK		=	0x40000000U,
	UART8_CLOCK		=	0x80000000U,
}RCC_APB1_CLOCK;


static inline void CLOCK_Enable_AHB1(RCC_AHB1_CLOCK E_CLK)
{
	RCC ->RCC_AHB1ENR |= E_CLK;
}

static inline void CLOCK_Disable_AHB1(RCC_AHB1_CLOCK D_CLK)
{
	RCC ->RCC_AHB1ENR &= (uint32)~D_CLK;
}

static inline void CLOCK_Enable_APB1(RCC_APB1_CLOCK E_CLK)
{
	RCC ->RCC_APB1ENR |= E_CLK;
}

static inline void CLOCK_Disable_APB1(RCC_APB1_CLOCK D_CLK)
{
	RCC ->RCC_APB1ENR &= (uint32)~D_CLK;
}


static inline void Reset_Peripheral_AHB1(RCC_AHB1_Reset R_Per)
{
	RCC ->RCC_AHB1RSTR |= R_Per;
	/* Some Kind of Delay Should Be Here */
	RCC ->RCC_AHB1RSTR &= (uint32)~R_Per;
}














#endif
