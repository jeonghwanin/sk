#include	"stdint.h"
#include	"halusart.h"

extern volatile uint32_t* rcc_apb2enr;
extern volatile	uint32_t*	rcc_apb1enr;
extern volatile	uint32_t*	afio_mapr;
extern volatile	uint32_t*	gpioa_crl;
extern volatile	uint32_t*	usart2_sr;
extern volatile	uint32_t*	usart2_dr;
extern volatile	uint32_t*	usart2_brr;
extern volatile	uint32_t*	usart2_cr1;
extern volatile	uint32_t*	usart2_cr2;
extern volatile	uint32_t*	usart2_cr3;

void usart_init(void)
{
	*rcc_apb2enr |=	0x00000005;
	*afio_mapr = 0x00000000;
	*rcc_apb1enr |= (1<<17);

	*gpioa_crl |= 0x00004b00;
	*usart2_brr	|= (0x13<<4);
	*usart2_brr	|= 0x08;
	*usart2_cr1 = 0;
	*usart2_cr2 = 0;
	*usart2_cr3 = 0;
   *usart2_cr1 |= 0x0c;
	*usart2_cr1 |= (1<<13);
	
}

int32_t usart_putc(int32_t c)
{
	if((c == '\n')||(c == '\r'))
	{
		while(!(*usart2_sr & (1<<7)));
		*usart2_dr |= '\n';
		while(!(*usart2_sr & (1<<7)));
		*usart2_dr |= '\r';	
	}
	else
	{
		while(!(*usart2_sr & (1<<7)));
		*usart2_dr |= (uint8_t)c;
	}
	return c;
}

int32_t usart_getc(void)
{
	int32_t c;
	while(!(*usart2_sr & (1<<5)));
	c = (int32_t)*usart2_dr;	
	usart_putc(c);
	return c;
}

int32_t usart_getc_nb(void)
{
	uint32_t c;
	if((*usart2_sr & (1<<5)) == 0)
		return -1;
	else
	{
		c	=	*usart2_dr;
		return (int32_t)c;
	}
}

int32_t usart_putstr(int8_t* s)
{
	int32_t count;
	while(*s)
	{
		usart_putc(*s++);
		count++
	}
	return count;	
}

int8_t* usart_getstr(int8_t* s)
{
	int8_t* c;
	c = s;

	*c = (uint8_t)usart_getc();
	while(*c != '\r')
	{
		c++;
		*c = (uint8_t)usart_getc();
	}
	*c = '\0';
	return s;
}

void usart_putclear(void)
{
	usart_putstr("^[[2j");
	usart_putstr("^[[H");
}

void usart_putgoto(int32_t x, int32_t y)
{
	usart_putstr("^[[H");
	for(;y>0;y--)
		usart_putstr("^[[1B");
	for(;x>0;x--)
		usart_putstr("^[[1C");
}

uint32_t usart_printf(const int8_t* format, ...)
{
	__builtin_va_list args;
	__builtin_va_start(args, format);
	vsprintf(printf_buf, format, args);
	__builtin_va_end(args);

	return pustr(printf_buf); 	
}

uint32_t vsprintf(int8_t* buf, const int8_t* format, __builtin_va_list arg)
{
	uint32_t c = 0;
}
















