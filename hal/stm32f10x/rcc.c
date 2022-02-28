#include "stdint.h"
#include "halrcc.h"

extern volatile uint32_t* rcc_cfgr; 
extern volatile uint32_t* rcc_cr;

void rcc_init(void)
{
	*rcc_cfgr	= 0x001f8402;
	*rcc_cr = 0x01010082;
}
