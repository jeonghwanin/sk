#include	"stdint.h"
#include	"halrcc.h"
#include	"halgpio.h"
#include	"halusart.h"
#include	"haltimer.h"

static void print_test(void);

void main(void)
{

	rcc_init();
	gpio_init();
	usart_init();
	systick_init();
	systick_enable();

	uint32_t time;
	while(1)
	{
			usart_printf("now   %u seconds\n", time_get());
	}

}

static void print_test(void)
{
	int8_t* str = "hello str\n";
	int8_t* n = 0;
	uint32_t i = 5;

	usart_printf("%s\n", "test");
	usart_printf("str = %s", str);
	usart_printf("%s is null, %u number %x number \n", n, i, i);
}
