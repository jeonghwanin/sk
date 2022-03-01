#include "stdint.h"
#include "haltimer.h"
#include "timer.h"

uint32_t tick = 0;

volatile uint32_t* syst_csr = (uint32_t *)SYST_CSR;
volatile uint32_t* syst_rvr = (uint32_t *)SYST_RVR;
volatile uint32_t* syst_cvr = (uint32_t *)SYST_CVR;
volatile uint32_t* syst_calib = (uint32_t *)SYST_CALIB;

void systick_init(void)
{
	*syst_rvr &= 0xff000000;
	*syst_rvr |= 36*1000000/1000 - 1;
	*syst_cvr = 0x00000000;
	*syst_csr &= 0x00000000;
	*syst_csr |= 0x00000004;
}
void systick_enable(void)
{
	*syst_csr |= 0x00000007;
}
void systick_disable(void)
{
	*syst_csr &= 0xfffffffc;
}
void SysTick_Handler(void)
{
	tick++;
}
uint32_t time_get(void)
{
	return tick;
}
