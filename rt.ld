ENTRY(reset_handler)

initial_sp	=	0x20005000;

MEMORY
{
/*FLASH 64K*/
FLASH	(RX)	:	ORIGIN	=	0x00000000,	LENGTH	=	64K	

/*SRAM 20K, data + bss = 8K, heap + stack = 12K*/
m_data_bss	(RW)	:	ORIGIN	=	0x2000000, LENGTH	=	0x00002000
m_heap_stack	(RW)	:	ORIGIN	=	0x20002000,	LENGTH	=	0x00003000
}

SECTIONS
{
	.text	:
	{
		.	=	ALIGN(4);
		__vector_table_start__	=	.;
		KEEP(*(.vector_table))
		__vector_table_end__	=	.;
		__text_start__	=	.;
		*(.text)
		*(.text*)
		__text_end__	=	.;
	} >FLASH
	
	.rodata	:
	{
		.	=	ALIGN(4);
		__rodata_start__	=	.;
		*(.rodata)
		*(.rodata*)
		__rodata_end__	=	.;
	}	>FLASH

	.data	:
	{
		.	=	ALIGN(4);
		__data_start__	=	.;
		*(.data)
		*(.data*)
		__data_end__	=	.;
	}	>m_data_bss

	.bss	:
	{
		.	=	ALIGN(4);
		__bss_start__	=	.;
		*(.bss)
		*(.bss*)
		__bss_end__	=	.;
	}	>m_data_bss
	
	HEAP_SIZE	=	0x1200;
	.heap	:
	{
		.	=	ALIGN(8);
		__heap_start__	=	.;
		.	+=	HEAP_SIZE;
		__heap_end__	=	.;
	}	>m_heap_stack

	STACK_SIZE	=	0x1800;	
	.stack	:
	{
		.	=	ALIGN(8);
		__stack_start__	=	.;
		.	+=	STACK_SIZE;
		__stack_end__	=	.;
	}	>m_heap_stack
}
