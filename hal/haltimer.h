#ifndef HAL_HALTIMER_H_
#define	HAL_HALTIMER_H_

void systick_init(void);
void systick_enable(void);
void systick_disable(void);
void SysTick_Handler(void);
uint32_t time_get(void);

#endif
