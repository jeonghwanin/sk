#ifndef HAL_STM32_USART_H_
#define HAL_STM32_USART_H_
/*************************************************/

#define UART5_BASE_ADD 0x40005000

/*************************************************/

typedef union USART_SR_t
{
// Reset value 00 1100 0000
  uint32_t all;
  struct{
		uint32_t PE:1;	// 0
		uint32_t FE:1;	// 1
		uint32_t NE:1;	// 2
		uint32_t ORE:1;	// 3
		uint32_t IDLE:1;	// 4 
    uint32_t RXNE:1;	// 5
		uint32_t TC:1;	// 6	
		uint32_t TXE:1;	// 7
    uint32_t LBD:1; // 8
    uint32_t CTS:1;	// 8
		uint32_t reserved:22;
	} bits;
} USART_SR_t;

typedef union USART_DR_t
{ 
// Reset value : 0 0000 0000
  uint32_t all;
  struct{
		uint32_t DR:9;	// 8:0
		uint32_t reserved:23;
	} bits;
} USART_DR_t;

typedef union USART_BRR_t
{
// Reset value : 0000 0000 0000 0000
  uint32_t all;
  struct{
    uint32_t DIB_FRACTION:4;	// 3:0
		uint32_t DIB_MANTISSA:12;	// 15:4
		uint32_t reserved:16;
	} bits;
} USART_BRR_t;

typedef union USART_CR1_t
{
	uint32_t all;
  struct{
		uint32_t SBK:1;	// 0
		uint32_t RWU:1; // 1 
    uint32_t RE:1;	// 2
		uint32_t TE:1;	// 3
    uint32_t IDLEIE:1;	// 4
		uint32_t RXNEIE:1;	// 5
		uint32_t TCIE:1;	// 6
		uint32_t TSEIE:1;	// 7
		uint32_t PEIE:1;	// 8
		uint32_t PS:1;	// 9
    uint32_t PCE:1;	//	10
    uint32_t WAKE:1;	// 11
		uint32_t M:1;		// 12
		uint32_t UE:1;	// 13
    uint32_t reserved:18;
  } bits;
} USART_CR1_t;

typedef union USART_CR2_t
{
  uint32_t all;
  struct{
		uint32_t ADD:4;	// 3:0
		uint32_t reserved1:1;
		uint32_t LBDL:1;	// 5
		uint32_t LBDIE:1;	// 6
		uint32_t reserved2:1;
		uint32_t LBCL:1;	// 8
		uint32_t CPHA:1;	// 9
		uint32_t CPOL:1;	// 10
		uint32_t CLKEN:1;	// 11	
		uint32_t STOP:2;	// 13:12
		uint32_t LINEN:1;	//14
		uint32_t reserved:17;
  } bits;
} USART_CR2_t;

typedef union USART_CR3_t
{
	uint32_t all;
	struct{
		uint32_t EIE:1;	// 0
		uint32_t IREN:1;	// 1
		uint32_t IRLP:1;	// 2
		uint32_t HDSEL:1;	// 3
		uint32_t NACK:1;	// 4
		uint32_t SCEN:1;	// 5
		uint32_t DMAR:1;	// 6
		uint32_t DMAT:1;	// 7
		uint32_t RTSE:1;	// 8
		uint32_t CTSE:1;	// 9
		uint32_t CTSIE:1;	// 10
		uint32_t reserved:21;
	} bits;
} USART_CR3_t;

typedef union USART_GTPR
{
	uint32_t all;
	struct{
		uint32_t PSC:8;	// 7:0
		uint32_t GT:8;	// 15:8
		uint32_t reserved:16;
	} bits;
} USART_GTPR_t;

typedef struct USART_t
{
	USART_SR_t usart_sr;	//0x00
	USART_DR_t usart_dr;	//0x04
	USART_BRR_t usart_brr;	//0x08
	USART_CR1_t	usart_cr1;	//0x0c
	USART_CR2_t usart_cr2;	//0x10
	USART_CR3_t usart_cr3;	//0x14
	USART_GTPR_t usart_gtpr;	//0x18
} USART_t;


/*************************************************/
#endif























