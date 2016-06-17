bootblock: bootasm.S bootmain.c
	$(CC) $(CFLAGS) -fno-pic -O -nostdinc -c bootmain.c
	$(CC) $(CFLAGS) -fno-pic -nostdinc -c bootasm.S
	$(LD) $(LDFLAGS) -N -e start -Ttext 0x7C00 -o bootblock.o bootasm.o bootmain.o
	$(OBJCOPY) -S -O binary -j .text bootblock.o bootblock
	$(SCRIPTS)sign.pl bootblock
	cp bootblock $(ROOT)

clean:
	rm -f *.o *.d *.asm bootblock

include ../../../../common.mk
