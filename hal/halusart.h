#ifndef	HAL_HALUSART_H_
#define HAL_HALUSART_H_

void usart_init(void);
int32_t usart_putc(int32_t c);
int32_t usart_getc(void);
int32_t usart_getc_nb(void);
int32_t usart_putstr(int8_t* s);
int8_t* usart_getstr(int8_t* s);
void usart_putclear(void);
void usart_putgoto(int32_t x, int32_t y);
uint32_t usart_printf(const int8_t* format, ...);
uint32_t vsprintf(int8_t* buf, const int8_t* format, __builtin_va_list arg);


#endif
