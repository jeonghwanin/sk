#ifndef HAL_HALUSART_H_
#define HAL_HALUSART_H_

void usart_init(void);
int32_t usart_putc(int32_t c);
int32_t usart_getc(void);

#endif
