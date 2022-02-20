#ifndef HAL_STM32_RCC_
#define HAL_STM32_RCC_
/***************************************************/

#define RCC_BASE_ADD 0X40021000

/***************************************************/

typedef union RCC_CR_t
{
	uint32_t all;
	struct{
		uint32_t HSION:1;	// 0
		uint32_t HSIRDY:1;	//1
		uint32_t reserved1:1;	//2
		uint32_t HSITRIM:5;	//7:3
		uint32_t HSICAL:8;	//15:8
		uint32_t HSEON:1;		//16
		uint32_t HSERD:1;		//17
		uint32_t HSEBYP:1;	//18
		uint32_t CSSON:1;		//19
		uint32_t reserved2:4;	//23:20
		uint32_t PLLON:1;	//24
		uint32_t PLLRDY:1;	//25
		uint32_t reserved3;	//31:26
	} bits;
} RCC_CR_t;

typedef union RCC_CFGR_t
{
  uint32_t all;
	struct{
		uint32_t SW:2;	//1:0
		uint32_t SWS:2;	//3:2
		uint32_t HPRE:4;	//7:4
		uint32_t PPRE1:3;	//10:8
		uint32_t PPRE2:3;	//13:11
		uint32_t ADCPRE:2;	//15:14
		uint32_t PLLSRC:1;	//16
		uint32_t PLLXTPRE:1;	//17
		uint32_t PLLMUL:4;	//21:18
		uint32_t USBPRE:1;	//22
		uint32_t reserved1:1;	//23
		uint32_t MCO:3;		//26:24
		uint32_t reserved2:5;	//31:27
	} bits;
} RCC_CFGR_t;

typedef union RCC_CIR_t
{
	uint32_t all;
	struct{
		uint32_t LSIRDYF:1;	//0
		uint32_t LSERDYF:1;	//1
		uint32_t HSIRDYF:1;	//2
		uint32_t HSERDYF:1;	//3
		uint32_t PLLRDYF:1;	//4
		uint32_t PLL2RDYF:1;	//5
		uint32_t PLL3RDYF:1;	//6
		uint32_t CSSF:1;		//7
		uint32_t LSIRDYIE:1;	//8
		uint32_t LSERDYIE:1;	//9
		uint32_t HSIRDYIE:1;	//10
		uint32_t HSERDYIE:1;	//11
		uint32_t PLLRDYIE:1;	//12
		uint32_t PLL2RDYIE:1;	//13
		uint32_t PLL3RDYIE:1;	//14
		uint32_t reserved:1;	//15
		uint32_t LSIRDYC:1;		//16
		uint32_t LSERDYC:1;		//17
		uint32_t HSIRDYC:1;		//18
		uint32_t HSERDYC:1;		//19
		uint32_t PLLRDYC:1;		//20
		uint32_t PLL2RDYC:1;	//21
		uint32_t PLL3RDYC:1;	//22
		uint32_t CSSC:1;			//23
		uint32_t reserved2:8;	//31:24
	}	bits;
} RCC_CIR_t;

typedef union RCC_APB2RSTR_t
{
	uint32_t all;
	struct{
		uint32_t AFIORST:1;	//0
		uint32_t reserved1:1;	//1
		uint32_t IOPASRST:1;	//2
		uint32_t IOPBRST:1;		//3
		uint32_t IOPCRST:1;		//4
		uint32_t IOPDRST:1;		//5
		uint32_t IOPERST:1;		//6
		uint32_t reserved2:2;	//8:7
		uint32_t ADC1RST:1;		//9
		uint32_t ADC2RST:1;		//10
		uint32_t TIM1RST:1;		//11
		uint32_t SPI1RST:1;		//12
		uint32_t reserved3:1;	//13
		uint32_t USART1RST:1;	//14
		uint32_t reserved4:17;	//31:15
	} bits;
} RCC_APB2RSTR_t;

typedef union RCC_APB1ENR_t
{
	uint32_t all;
	struct{
		uint32_t TIM2EN:1;		//0
		uint32_t TIM3EN:1;		//1
		uint32_t TIM4EN:1;		//2
		uint32_t TIM5EN:1;		//3
		uint32_t TIM6EN:1;		//4
		uint32_t TIM7EN:1;		//5
		uint32_t reserved1:5;	//10:6
		uint32_t WWDGRST:1;		//11
		uint32_t reserved:2;	//13:12
		uint32_t SPI2RST:1;		//14
		uint32_t SPI3RST:1;		//15
		uint32_t reserved3:1;	//16
		uint32_t USART2RST:1;	//17
		uint32_t USART3RST:1;	//18
		uint32_t UART4RST:1;	//19
		uint32_t UART5RST:1;	//20
		uint32_t I2CIRST:1;		//21
		uint32_t I2C2RST:1;		//22
		uint32_t reserved4:2;	//24:23
		uint32_t CAN1RST:1;		//25
		uint32_t CAN2RST:1;		//26
		uint32_t BKPRST:1;		//27
		uint32_t PWRRST:1;		//28
		uint32_t DACRST:1;		//29
		uint32_t reserved5:2;	//31:30
	} bits;
} RCC_APB1RSTR_t;

typedef union RCC_AHBENR_t
{
	uint32_t all;
	struct{
		uint32_t DM1AEN:1;	//0
		uint32_t DM2AEN:1;	//1
		uint32_t SRAMEN:1;	//2
		uint32_t reserved1:1;	//3
		uint32_t FLITFEN:1;	//4
		uint32_t reserved2:1;	//5
		uint32_t CRCEN:1;		//6
		uint32_t reserved3:5;	//11:7
		uint32_t OTGFSEN:1;		//12
		uint32_t reserved4:1;	//13
		uint32_t ETHMACEN:1;	//14
		uint32_t ETHMACTXEN:1;	//15
		uint32_t ETHMACRXEN:1;	//16
		uint32_t reserved5:15;		//31:17
	} bits;
} RCC_AHBENR_t;

typedef union RCC_APB2ENR_t
{
	uint32_t all;
	struct{
		uint32_t AFIOEN:1;	//0
		uint32_t reserved1:1;	//1
		uint32_t IOPAEN:1;	//2
		uint32_t IOPBEN:1;	//3
		uint32_t IOPCEN:1;	//4
		uint32_t IOPDEN:1;	//5
		uint32_t IOPEEN:1;	//6
		uint32_t reserved2:2;	//8:7
		uint32_t ADC1EN:1;	//9
		uint32_t ADC2EN:1;	//10
		uint32_t TIM1EN:1;	//11
		uint32_t SPI1EN:1;	//12
		uint32_t reserved3:1;	//13
		uint32_t USART1EN:1;	//14
		uint32_t reserved4:17;	//31:15
	} bits;
} RCC_APB2ENR_t;

typedef union RCC_APB1ENR
{
	uint32_t all;
	struct{
		uint32_t TIM2EN:1;	//0
		uint32_t TIM3EN:1;	//1
		uint32_t TIM4EN:1;	//2
		uint32_t TIM5EN:1;	//3
		uint32_t TIM6EN:1;	//4
		uint32_t TIM7EN:1;	//5
		uint32_t reserved1:5;	//10:6
		uint32_t WWDGEN:1;	//11
		uint32_t reserved2:6;	//12:13;
		uint32_t SPI2EN:1;	//14
		uint32_t SPI3EN:1;	//15
		uint32_t reserved3:1;	//16
		uint32_t USART2EN:1;	//17
		uint32_t USART3EN:1;	//18
		uint32_t UART4EN:1;		//19
		uint32_t UART5EN:1;		//20
		uint32_t I2C1EN:1;		//21
		uint32_t I2C2EN:1;		//22
		uint32_t USBEN:1;			//23
		uint32_t reserved4:1;	//24
		uint32_t CANEN:1;			//25
		uint32_t reserved5:1;	//26
		uint32_t BKPEN:1;			//27
		uint32_t PWREN:1;			//28
		uint32_t DACEN:1;			//29
		uint32_t reserved6:2;	//31:30
	} bits;
} RCC_APB1ENR_t;

typedef union RCC_BDCR_t
{
	uint32_t all;
	struct{
		uint32_t LSEON:1;	//0
		uint32_t LSERDY:1;	//1
		uint32_t LSEBYP:1;	//2
		uint32_t reserved1:5;	//7:3
		uint32_t RTCSEL:2;		//9:8
		uint32_t reserved2:5;	//14:10
		uint32_t RTCEN:1;			//15
		uint32_t BDRST:1;			//16
		uint32_t reserved3:15;	//31:17
	} bits;
} RCC_BDCR_t;

typedef union RCC_CSR_t
{
	uint32_t all;
	struct{
		uint32_t LSION:1;	//0
		uint32_t	LSIRDY:1;	//1
		uint32_t reserved1:22;	//23:2
		uint32_t RMVF:1;		//24
		uint32_t reserved2:1;		//25
		uint32_t PINRSTF:1;		//26
		uint32_t PORRSTF:1;		//27
		uint32_t SFTRSTF:1;		//28
		uint32_t IWDGRSTF:1;	//29
		uint32_t WWDGRSTF:1;	//30
		uint32_t LPWRSTF:1;		//31
	} bits;
} RCC_CSR_t;

typedef struct RCC_t
{
	RCC_CR_t rcc_cr;		//0x00
	RCC_CFGR_t rcc_cfgr;	//0x04
	RCC_CIR_t rcc_cir;		//0x08
	RCC_APB2RSTR_t rcc_apb2rstr;	//0x0c
	RCC_APB1RSTR_t rcc_apb1rstr;	//0x10
	RCC_AHBENR_t rcc_ahbenr;			//0x14
	RCC_APB2ENR_t rcc_apb2enr;		//0x18
	RCC_APB1ENR_t rcc_apb1enr;		//0x1c
	RCC_BDCR_t rcc_bdcr;					//0x20
	RCC_CSR_t rcc_csr;						//0x24
} RCC_t;
/***************************************************/
#endif
