#include "stdint.h"
#include "HalGpio.h"
#include "Gpio.h"

extern volatile GPIO_t* gpioc;

void gpio_enable()
{
	gpioc->gpio_crh.bits.CNF13 = 0;
	gpioc->gpio_crh.bits.MODE13 = 1;
	gpioc->gpio_odr.bits.ODR13 = 1;
}
