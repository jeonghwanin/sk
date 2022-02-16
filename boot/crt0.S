.global	vector
.section	.vector_table
	vector:
	.word	initial_sp
	.word	reset_handler

.text
.syntax	unified
.thumb
.thumb_func
.align	2
.global reset_handler
.type	reset_handler,	%function
	reset_handler:
		ldr r1, =__bss_start__
		ldr	r2,	=__bss_end__
		movs	r0,	#0
		.bss_init:
			cmp	r1,	r2
			itt	lt
			strlt	r0,	[r1],	#4
			blt	.bss_init

		bl	main 
