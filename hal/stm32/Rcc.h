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
} RCC_CFGR_t


/***************************************************/
#endif
