#include "stdint.h"
#include "HalRcc.h"
#include "HalGpio.h"
#include "HalUsart.h"

//static void hw_init(void);

void main(void)
{

//	hw_init();
	rcc_init();
	while(1){
		gpio_enable();
	}

}

/***************************************/

static void hw_init(void)
{
//	usart_init();
}

/***************************************/
