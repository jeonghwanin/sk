#include "stdint.h"
#include "Usart.h"
#include "HalUsart.h"

extern volatile USART_t* uart5;

/**********************************************/

void usart_init(void)
{
  uart5->usart_cr1.bits.UE = 1;
	uart5->usart_cr1.bits.M = 1;
	uart5->usart_cr2.bits.STOP = 0;
	uart5->usart_brr.bits.DIB_MANTISSA = 53;
	uart5->usart_brr.bits.DIB_FRACTION = 5;
	uart5->usart_cr1.bits.TE = 1;

}

/**********************************************/

int32_t usart_putc(int32_t c)
{
	if((c=='\n')||(c=='\r'))
	{
		while(uart5->usart_sr.bits.TXE);
		uart5->usart_dr.bits.DR = '\r';
		while(uart5->usart_sr.bits.TXE);
		uart5->usart_dr.bits.DR = '\n';
	}
	else
	{
		while(uart5->usart_sr.bits.TXE);
		uart5->usart_dr.bits.DR = (uint8_t)c;
	}
	return c;
}

/**********************************************/

