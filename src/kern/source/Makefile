OBJS = bio.o console.o exec.o file.o fs.o ide.o ioapic.o kalloc.o kbd.o\
	   lapic.o log.o main.o mp.o picirq.o pipe.o proc.o spinlock.o string.o\
	   swtch.o syscall.o sysfile.o sysproc.o timer.o trapasm.o trap.o uart.o\
	   vectors.o vm.o\

kernel: $(OBJS) entry.o entryother initcode
	$(LD) $(LDFLAGS) -T $(SCRIPTS)kernel.ld -o kernel entry.o $(OBJS) -b binary initcode entryother
	cp kernel $(ROOT)

entryother: entryother.S
	$(CC) $(CFLAGS) -fno-pic -nostdinc -c entryother.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother

initcode: initcode.S
	$(CC) $(CFLAGS) -nostdinc -c initcode.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(OBJCOPY) -S -O binary initcode.out initcode

vectors.S:
	perl $(SCRIPTS)vectors.pl > vectors.S

clean:
	rm -f *.o *.asm *.d *.sym entryother initcode initcode.out kernel

include ../../../common.mk
