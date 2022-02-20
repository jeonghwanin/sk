#ifndef	HAL_STM32_GPIO_H_
#define HAL_SEM32_GPIO_H_
/*************************************************/

#define GPIOC_BASE_ADD 0x40011000

/*************************************************/
typedef union GPIOX_CRL_t
{
	uint32_t all;
	struct{
		uint32_t MODE0:2;	//1:0
		uint32_t CNF0:2;	//3:2
		uint32_t MODE1:2;		//5:4
		uint32_t CNF1:2;	//7:6
		uint32_t MODE2:2;	//9:8
		uint32_t CNF2:2;	//11:10
		uint32_t MODE3:2;	//13:12
		uint32_t CNF3:2;	//15:14
		uint32_t MODE4:2;	//17:16
		uint32_t CNF4:2;	//19:18
		uint32_t MODE5:2;	//21:20
		uint32_t CNF5:2;	//23:22
		uint32_t MODE6:2;	//25:24
		uint32_t CNF6:2;	//27:26
		uint32_t MODE7:2;	//29:28
		uint32_t CNF7:2;	//31:30
	} bits;
} GPIOX_CRL_t;

typedef union GPIOX_CRH_t
{
	uint32_t all;
	struct{
		uint32_t MODE8:2;	//1:0
		uint32_t CNF8:2;	//3:2
		uint32_t MODE9:2;	//5:4
		uint32_t CNF9:2;	//7:6
		uint32_t MODE10:2;	//9:8
		uint32_t CNF10:2;	//11:10
		uint32_t MODE11:2;	//13:12
		uint32_t CNF11:2;		//15:14
		uint32_t MODE12:2;	//17:16
		uint32_t CNF12:2;		//19:18
		uint32_t MODE13:2;		//21:20
		uint32_t CNF13:2;			//23:22
		uint32_t MODE14:2;		//25:24
		uint32_t CNF14:2;			//27:26
		uint32_t MODE15:2;		//29:28
		uint32_t CNF15:2;			//31:30
	} bits;
} GPIOX_CRH_t;

typedef union GPIOX_IDR_t
{
	uint32_t all;
	struct{
		uint32_t IDR0:1;
		uint32_t IDR1:1;
		uint32_t IDR2:1;
		uint32_t IDR3:1;
		uint32_t IDR4:1;
		uint32_t IDR5:1;
		uint32_t IDR6:1;
		uint32_t IDR7:1;
		uint32_t IDR8:1;
		uint32_t IDR9:1;
		uint32_t IDR10:1;
		uint32_t IDR11:1;
		uint32_t IDR12:1;
		uint32_t IDR13:1;
		uint32_t IDR14:1;
		uint32_t IDR15:1;
		uint32_t reserved:16;	//31:16
	} bits;
} GPIOX_IDR_t;

typedef union GPIOX_ODR_t
{
	uint32_t all;
	struct{
		uint32_t ODR0:1;
		uint32_t ODR1:1;
		uint32_t ODR2:1;
		uint32_t ODR3:1;
		uint32_t ODR4:1;
		uint32_t ODR5:1;
		uint32_t ODR6:1;
		uint32_t ODR7:1;
		uint32_t ODR8:1;
		uint32_t ODR9:1;
		uint32_t ODR10:1;
		uint32_t ODR11:1;
		uint32_t ODR12:1;
		uint32_t ODR13:1;
		uint32_t ODR14:1;
		uint32_t ODR15:1;
		uint32_t reserved:16;	//31:16
	} bits;
} GPIOX_ODR_t;

typedef struct GPIO_t
{
	GPIOX_CRL_t gpio_crl;	//0x00
	GPIOX_CRH_t gpio_crh;	//0x04
	GPIOX_IDR_t gpio_idr;	//0x08
	GPIOX_ODR_t gpio_odr;	//0x0c
} GPIO_t;

#endif
