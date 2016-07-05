kernel: $(OBJS) kmain io boot trap util
	$(LD) $(LDFLAGS) -T $(SCRIPTS)kernel.ld $(OBJS)
	cp kernel $(ROOT)

# These are all the kernel subsystems along with their files. Any new files
# added to the kernel need to go here, otherwise the build system won't know to
# build them. Variables ending in ARCH contain machine dependent files, while
# those that don't are machine independent (except for KMAIN, which is machine dependent)
# These have to come after the include directive above, otherwise Make gets confused
IOARCH = $(addprefix $(KERNARCH)io/, uart.o uartasm.o console.o)
KMAIN = $(addprefix $(KERNARCH)kmain/, main.o)
ENTRY = $(addprefix $(KERNARCH)boot/, entry.o)
TRAPARCH = $(addprefix $(KERNARCH)trap/, interrupt.o)
UTILARCH = $(addprefix $(KERNARCH)util/, kalloc.o)

OBJS = $(ENTRY) $(KMAIN) $(IOARCH) $(TRAPARCH) $(UTILARCH)
