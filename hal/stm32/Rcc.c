#include "stdint.h"
#include "Rcc.h"
#include "HalRcc.h"

extern volatile RCC_t* rcc;

/*******************************************************/

void rcc_init(void)
{
// HSI SYSCLK = 64MHz APB1 = 32MHz APB2 = 64MHz
	rcc->rcc_cfgr.bits.PLLSRC = 0;
	rcc->rcc_cfgr.bits.PLLMUL = 0xf;
	rcc->rcc_cfgr.bits.SW = 0x2;
	rcc->rcc_cfgr.bits.HPRE = 0;
  rcc->rcc_cfgr.bits.PPRE1 = 0x4;
  rcc->rcc_cfgr.bits.PPRE2 = 0;
  rcc->rcc_cfgr.bits.ADCPRE = 0x2;

	rcc->rcc_cr.all = 0x01000041;
}



/*******************************************************/
