all: entry.o

entryother:
	$(CC) $(CFLAGS) -fno-pic -nostdinc -c entryother.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7000 -o bootblockother.o entryother.o
	$(OBJCOPY) -S -O binary -j .text bootblockother.o entryother

initcode:
	$(CC) $(CFLAGS) -nostdinc -c initcode.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0 -o initcode.out initcode.o
	$(OBJCOPY) -S -O binary initcode.out initcode

clean:
	rm -f *.o *.d *.asm initcode entryother initcode.out

include ../../../../../common.mk
