#include	"stdint.h"
#include	"rcc.h"
#include	"gpio.h"
#include	"afio.h"
#include	"usart.h"

//RCC register
volatile uint32_t* rcc_cfgr = (uint32_t *)(RCC_ADDR + RCC_CFGR);
volatile uint32_t* rcc_cr = (uint32_t *)(RCC_ADDR + RCC_CR);
volatile uint32_t* rcc_apb2enr = (uint32_t *)(RCC_ADDR+RCC_APB2ENR);
volatile uint32_t* rcc_apb1enr = (uint32_t *)(RCC_ADDR+RCC_APB1ENR);

//GPIO register
volatile uint32_t* gpioa_crl = (uint32_t *)(GPIOA_ADDR+GPIO_CRL);
volatile uint32_t* gpioc_crh = (uint32_t *)(GPIOC_ADDR+GPIO_CRH);
volatile uint32_t* gpioc_odr = (uint32_t *)(GPIOC_ADDR+GPIO_ODR);

//AFIO register
volatile uint32_t* afio_mapr = (uint32_t *)(AFIO_ADDR+AFIO_MAPR);

//USART register
volatile uint32_t* usart2_sr = (uint32_t *)(USART2_ADDR+USART_SR);
volatile uint32_t* usart2_dr = (uint32_t *)(USART2_ADDR+USART_DR);
volatile uint32_t* usart2_brr = (uint32_t *)(USART2_ADDR+USART_BRR);
volatile uint32_t* usart2_cr1 = (uint32_t *)(USART2_ADDR+USART_CR1);
volatile uint32_t* usart2_cr2 = (uint32_t *)(USART2_ADDR+USART_CR2);
volatile uint32_t* usart2_cr3 = (uint32_t *)(USART2_ADDR+USART_CR3);
