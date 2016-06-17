SRCS = $(wildcard *.c) $(wildcard *.S)
OBJS = $(patsubst %.c,%.o, $(patsubst %.S,%.o,$(SRCS)))

all: $(OBJS)

clean:
	rm -f *.o *.d *.asm

include ../../../../../common.mk
