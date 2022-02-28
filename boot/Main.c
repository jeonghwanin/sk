#include	"stdint.h"
#include	"halrcc.h"
#include	"halgpio.h"
#include	"halusart.h"

void main(void)
{

	rcc_init();
	gpio_init();
	usart_init();
	
	while(1)
	{
		usart_getc();
;	}
}
