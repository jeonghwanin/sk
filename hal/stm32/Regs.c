#include "stdint.h"
#include "Usart.h"
#include "Rcc.h"
#include "Gpio.h"

volatile USART_t* uart5 = (USART_t*)UART5_BASE_ADD;
volatile RCC_t* rcc = (RCC_t*)RCC_BASE_ADD;
volatile GPIO_t* gpioc = (GPIO_t*)GPIOC_BASE_ADD;
