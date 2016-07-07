all: archall

fs:
	$(MAKE) -C $(KERN)fs
	$(MAKE) -C $(KERNARCH)fs

kmain:
	$(MAKE) -C $(KERNARCH)kmain

trap:
	$(MAKE) -C $(KERNARCH)trap

io:
	$(MAKE) -C $(KERNARCH)io
	$(MAKE) -C $(KERN)io

syscall:
	$(MAKE) -C $(KERNARCH)syscall

util:
	$(MAKE) -C $(KERN)util
	$(MAKE) -C $(KERNARCH)util

thread:
	$(MAKE) -C $(KERN)thread
	$(MAKE) -C $(KERNARCH)thread

proc:
	$(MAKE) -C $(KERNARCH)proc

vm:
	$(MAKE) -C $(KERNARCH)vm

boot:
	$(MAKE) -C $(KERNARCH)boot

clean:
	rm -f kernel initcode entryother
	$(MAKE) -C $(KERN)fs clean
	$(MAKE) -C $(KERNARCH)fs clean
	$(MAKE) -C $(KERNARCH)kmain clean
	$(MAKE) -C $(KERNARCH)trap clean
	$(MAKE) -C $(KERNARCH)io clean
	$(MAKE) -C $(KERNARCH)syscall clean
	$(MAKE) -C $(KERN)util clean
	$(MAKE) -C $(KERNARCH)util clean
	$(MAKE) -C $(KERNARCH)thread clean
	$(MAKE) -C $(KERNARCH)proc clean
	$(MAKE) -C $(KERNARCH)vm clean
	$(MAKE) -C $(KERNARCH)boot clean
	$(MAKE) -C $(KERN)io clean
	$(MAKE) -C $(KERN)thread clean

.PHONY: fs kmain trap io syscall util thread proc vm vectors boot

# Architecture independent kernel files get added here
FS = $(addprefix $(KERN)fs/, bio.o file.o log.o)
IO = $(addprefix $(KERN)io/, console.o)
UTIL = $(addprefix $(KERN)util/, string.o)
THREAD = $(addprefix $(KERN)thread/, spinlock.o)

include ../../common.mk
include $(ARCH).mk

