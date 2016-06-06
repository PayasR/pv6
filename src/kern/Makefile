kernel: vectors $(OBJS) entry.o entryother initcode fs kmain trap io syscall util thread proc vm
	$(LD) $(LDFLAGS) -T $(SCRIPTS)kernel.ld -o kernel entry.o $(OBJS) -b binary initcode entryother
	cp kernel $(ROOT)

fs:
	$(MAKE) -C $(KERN)fs
	$(MAKE) -C $(KERNARCH)fs

kmain:
	$(MAKE) -C $(KERNARCH)kmain

trap:
	$(MAKE) -C $(KERNARCH)trap

io:
	$(MAKE) -C $(KERNARCH)io

syscall:
	$(MAKE) -C $(KERNARCH)syscall

util:
	$(MAKE) -C $(KERNARCH)util

thread:
	$(MAKE) -C $(KERNARCH)thread

proc:
	$(MAKE) -C $(KERNARCH)proc

vm:
	$(MAKE) -C $(KERNARCH)vm

entryother: entryother.S
	$(CC) $(CFLAGS) -fno-pic -nostdinc -c entryother.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother

initcode: initcode.S
	$(CC) $(CFLAGS) -nostdinc -c initcode.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(OBJCOPY) -S -O binary initcode.out initcode

vectors:
	perl $(SCRIPTS)vectors.pl > $(KERNARCH)trap/vectors.S

clean:
	rm -f kernel initcode initcode.out entryother *.o *.d
	$(MAKE) -C $(KERN)fs clean
	$(MAKE) -C $(KERNARCH)fs clean
	$(MAKE) -C $(KERNARCH)kmain clean
	$(MAKE) -C $(KERNARCH)trap clean
	$(MAKE) -C $(KERNARCH)io clean
	$(MAKE) -C $(KERNARCH)syscall clean
	$(MAKE) -C $(KERNARCH)util clean
	$(MAKE) -C $(KERNARCH)thread clean
	$(MAKE) -C $(KERNARCH)proc clean
	$(MAKE) -C $(KERNARCH)vm clean

.PHONY: fs kmain trap io syscall util thread proc vm vectors

include ../../common.mk

# These are all the kernel subsystems along with their files. Any new files
# added to the kernel need to go here, otherwise the build system won't know to
# build them. Variables ending in ARCH contain machine dependent files, while
# those that don't are machine independent (except for KMAIN, which is machine dependent)
# These have to come after the include directive above, otherwise Make gets confused
FS = $(addprefix $(KERN)fs/, bio.o file.o log.o)
FSARCH = $(addprefix $(KERNARCH)fs/, fs.o)
KMAIN = $(addprefix $(KERNARCH)kmain/, main.o mp.o)
TRAPARCH = $(addprefix $(KERNARCH)trap/, ioapic.o lapic.o picirq.o timer.o trap.o trapasm.o vectors.o)
IOARCH = $(addprefix $(KERNARCH)io/, console.o ide.o kbd.o uart.o)
SYSCALLARCH = $(addprefix $(KERNARCH)syscall/, exec.o pipe.o syscall.o sysfile.o sysproc.o)
UTILARCH = $(addprefix $(KERNARCH)util/, string.o kalloc.o)
THREADARCH = $(addprefix $(KERNARCH)thread/, swtch.o spinlock.o)
PROCARCH = $(addprefix $(KERNARCH)proc/, proc.o)
VMARCH = $(addprefix $(KERNARCH)vm/, vm.o)

OBJS = $(FS) $(FSARCH) $(KMAIN) $(TRAPARCH) $(IOARCH) $(SYSCALLARCH) $(UTILARCH) $(THREADARCH) $(PROCARCH) $(VMARCH)

