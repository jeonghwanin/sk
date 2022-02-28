#include	"stdint.h"
#include	"halgpio.h"

extern volatile uint32_t* rcc_apb2enr; 
extern volatile uint32_t* gpioc_crh; 
extern volatile uint32_t* gpioc_odr; 

void gpio_init(void)
{
	*rcc_apb2enr	=	(1<<4);
	*gpioc_crh	=	0x00100000;
}

void led_off(void)
{
	*gpioc_odr = (1<<13);
}

void led_on(void)
{
	*gpioc_odr = (0<<13);
}
