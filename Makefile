ARCH	=	armv7-m
MCPU	=	cortex-m3

CC	=	arm-none-eabi-gcc
AS	=	arm-none-eabi-as
LD	=	arm-none-eabi-ld
OC	=	arm-none-eabi-objcopy

LINKER_SCRIPT	=	./rt.ld
MAP_FILE	=	build/rt.map
INC_DIRS	=	-I	include

ASM_SRCS	=	$(wildcard	boot/*.S)
ASM_OBJS	=	$(patsubst	boot/%.S,	build/%.os, $(ASM_SRCS))

C_SRCS	=	$(wildcard	boot/*.c)
C_OBJS	=	$(patsubst	boot/%.c,	build/%.o, $(C_SRCS))

rt	=	build/rt.axf
rt_bin	=	build/rt.bin

.PHONE:	all	clean	run	debug	gdb

all:	$(rt)

clean:
	@rm	-rf	build

run:	$(rt)
	qemu-system-arm	-M	lm3s6965evb	-kernel	$(rt)

debug:	$(rt)
	qemu-system-arm	-M	lm3s6965evb	-kernel	$(rt)	-S	-gdb	tcp::1234,ipv4

gdb:
	arm-multiarch

$(rt):	$(ASM_OBJS)	$(C_OBJS)	$(LINKER_SCRIPT)
	$(LD)	-n	-T	$(LINKER_SCRIPT)	-o	$(rt)	$(ASM_OBJS)	$(C_OBJS)	-Map=$(MAP_FILE)
	$(OC)	-O	binary	$(rt)	$(rt_bin)

build/%.os:	$(ASM_SRCS)	
	mkdir	-p	$(shell	dirname	$@)
	$(CC)	-march=$(ARCH)	-mcpu=$(MCPU)	$(INC_DIRS) -c	-g	-o	$@	$<	

build/%.o:	$(C_SRCS)
	mkdir	-p	$(shell	dirname	$@)
	$(CC)	-march=$(ARCH)	-mcpu=$(MCPU)	$(INC_DIRS) -c	-g	-o	$@	$<	