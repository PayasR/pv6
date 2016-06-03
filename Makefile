xv6.img: bootblock kernel fs.img
	dd if=/dev/zero of=xv6.img count=10000
	dd if=bootblock of=xv6.img conv=notrunc
	dd if=kernel of=xv6.img seek=1 conv=notrunc

bootblock:
	$(MAKE) -C $(BOOT) bootblock

kernel:
	$(MAKE) -C $(SOURCE) kernel

mkfs:
	$(MAKE) -C $(TOOLS) mkfs

PROGS = $(addprefix $(BIN), $(UPROGS))
fs.img: mkfs README userland $(PROGS)
	./mkfs fs.img README $(UPROGS)

userland:
	$(MAKE) -C $(LIB)
	$(MAKE) -C $(BIN)

clean:
	rm -f *.asm *.sym vectors.S bootblock entryother \
	kernel xv6.img fs.img mkfs \
	.gdbinit $(UPROGS)
	$(MAKE) -C $(SOURCE) clean
	$(MAKE) -C $(BIN) clean
	$(MAKE) -C $(BOOT) clean
	$(MAKE) -C $(TOOLS) clean
	$(MAKE) -C $(LIB) clean

# run in emulators

# try to generate a unique GDB port
GDBPORT = $(shell expr `id -u` % 5000 + 25000)
# QEMU's gdb stub command line changed in 0.11
QEMUGDB = $(shell if $(QEMU) -help | grep -q '^-gdb'; \
	then echo "-gdb tcp::$(GDBPORT)"; \
	else echo "-s -p $(GDBPORT)"; fi)
QEMUOPTS = -hdb fs.img xv6.img -smp $(CPUS) -m 512 $(QEMUEXTRA)

qemu: fs.img xv6.img
	$(QEMU) -serial mon:stdio $(QEMUOPTS)

qemu-nox: fs.img xv6.img
	$(QEMU) -nographic $(QEMUOPTS)

.gdbinit: .gdbinit.tmpl
	sed "s/localhost:1234/localhost:$(GDBPORT)/" < $^ > $@

qemu-gdb: fs.img xv6.img .gdbinit
	@echo "*** Now run 'gdb'." 1>&2
	$(QEMU) -serial mon:stdio $(QEMUOPTS) -S $(QEMUGDB)

qemu-nox-gdb: fs.img xv6.img .gdbinit
	@echo "*** Now run 'gdb'." 1>&2
	$(QEMU) -nographic $(QEMUOPTS) -S $(QEMUGDB)

# these all need to be phony because they're built by stubs that just call into
# another Makefile
.PHONY: bootblock kernel userland mkfs

include common.mk
