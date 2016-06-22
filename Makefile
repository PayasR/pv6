all: archall

kernel:
	$(MAKE) -C $(KERN) kernel

mkfs:
	$(MAKE) -C $(TOOLS) mkfs

PROGS = $(addprefix $(BIN), $(UPROGS))
fs.img: mkfs README userland $(PROGS)
	./mkfs fs.img README $(UPROGS)

userland:
	$(MAKE) -C $(LIBARCH)
	$(MAKE) -C $(LIB)
	$(MAKE) -C $(BIN)

clean: archclean
	rm -f kernel fs.img mkfs \
	.gdbinit $(UPROGS)
	$(MAKE) -C $(KERN) clean
	$(MAKE) -C $(BIN) clean
	$(MAKE) -C $(TOOLS) clean
	$(MAKE) -C $(LIB) clean
	$(MAKE) -C $(LIBARCH) clean

# run in emulators

.PHONY: kernel userland mkfs archclean

include common.mk

ifeq ($(ARCH), x86)
include x86.mk
endif

ifeq ($(ARCH), riscv)
include riscv.mk
endif
