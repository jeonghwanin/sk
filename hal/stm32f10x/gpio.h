#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#define	GPIOA_ADDR	0x40010800
#define	GPIOB_ADDR	0x40010c00
#define	GPIOC_ADDR	0x40011000
#define	GPIOD_ADDR	0x40011400
#define	GPIOE_ADDR	0x40011800
#define	GPIOF_ADDR	0x40011c00
#define	GPIOG_ADDR	0x40012000

#define	GPIO_CRL		0x00
#define	GPIO_CRH		0x04
#define	GPIO_IDR		0x08
#define	GPIO_ODR		0x0c
#define	GPIO_BSRR		0x10
#define	GPIO_BRR		0x14
#define	GPIO_LCKR		0x18

#endif
