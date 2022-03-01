#include	"stdint.h"
#include	"halusart.h"

#define	PRINTF_BUF_SIZE	1024

static char printf_buf[PRINTF_BUF_SIZE];

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
		count++;
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

	return usart_putstr(printf_buf); 	
}

uint32_t vsprintf(int8_t* buf, const int8_t* format, __builtin_va_list arg)
{
	uint32_t count = 0;

	int8_t c;
	int8_t* s;
	uint32_t u, x;
	uint32_t i;

	for(i=0; format[i]; i++)
	{
		if(format[i] == '%')
		{
			i++;
			switch(format[i])
			{
			case 'c':
				c = (int8_t)__builtin_va_arg(arg, int32_t);
				buf[count++] = c;
				break;
			case 's':
				s = (int8_t*)__builtin_va_arg(arg, int8_t*);
				if(s == NULL)
				{
					s = "null";
				}
				while(*s)
				{
					buf[count++] = (*s++);
				}
				break;
			case 'u':
				u = (uint32_t)__builtin_va_arg(arg, uint32_t);
				count += utoa(&buf[count], u, 10);
				break;
			case 'x':
				x = (uint32_t)__builtin_va_arg(arg, uint32_t);
				count += utoa(&buf[count], x, 16);
				break;	
			}
		}
		else
		{
			buf[count++] = format[i];
		}
	}

	if(c >=	PRINTF_BUF_SIZE)
	{
		buf[0] = '\0';
		return 0;
	}

	buf[c] = '\0';

	return c; 
}

uint32_t utoa(char* buf, uint32_t val, uint32_t utoa_base)
{
	uint32_t count = 0;
	int32_t idx = 0;
	int8_t tmp[11];

	do
	{
		uint32_t t = val % utoa_base;
		if(t >= 10)
		{
			t += 'A' - '0' -10;
		}
		tmp[idx] = (t + '0');
		val /= utoa_base;
		idx++;
	}while(val);

	idx--;
	while(idx >= 0)
	{
		buf[count++] = tmp[idx];
		idx--;
	}
	return count;	
}
















