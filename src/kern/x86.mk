kernel: vectors $(OBJS) $(ENTRY) fs kmain trap io syscall util thread proc vm boot
	$(LD) $(LDFLAGS) -T $(SCRIPTS)kernel.ld $(ENTRY) $(OBJS) -b binary initcode entryother
	cp kernel $(ROOT)

vectors:
	perl $(SCRIPTS)vectors.pl > $(KERNARCH)trap/vectors.S

# These are all the kernel subsystems along with their files. Any new files
# added to the kernel need to go here, otherwise the build system won't know to
# build them. Variables ending in ARCH contain machine dependent files, while
# those that don't are machine independent (except for KMAIN and ENTRY, which
# are machine dependent) These have to come after the include directive above,
# otherwise Make gets confused
FSARCH = $(addprefix $(KERNARCH)fs/, fs.o)
KMAIN = $(addprefix $(KERNARCH)kmain/, main.o mp.o)
TRAPARCH = $(addprefix $(KERNARCH)trap/, ioapic.o lapic.o picirq.o timer.o trap.o trapasm.o vectors.o)
IOARCH = $(addprefix $(KERNARCH)io/, console.o ide.o kbd.o uart.o)
SYSCALLARCH = $(addprefix $(KERNARCH)syscall/, exec.o pipe.o syscall.o sysfile.o sysproc.o)
UTILARCH = $(addprefix $(KERNARCH)util/, string.o kalloc.o asm.o)
THREADARCH = $(addprefix $(KERNARCH)thread/, swtch.o spinlock.o)
PROCARCH = $(addprefix $(KERNARCH)proc/, proc.o)
VMARCH = $(addprefix $(KERNARCH)vm/, vm.o)
ENTRY = $(addprefix $(KERNARCH)boot/, entry.o)

OBJS = $(FS) $(FSARCH) $(KMAIN) $(TRAPARCH) $(IO) $(IOARCH) $(SYSCALLARCH) $(UTIL) $(UTILARCH) $(THREAD) $(THREADARCH) $(PROCARCH) $(VMARCH)
