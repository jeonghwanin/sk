#include "stdint.h"
#include "Uart.h"
#incldue "HalUart.h"

extern volatile USART_t* uart5;

/**********************************************/

void usart_init(void)
{
  uart5->usart_cr1.UE = 1;
	uart5->usart_cr1.M = 1;
	uart5->usart_cr2.STOP = 0;
}

/**********************************************/
