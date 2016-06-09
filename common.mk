# TOOLPREFIX =
ARCH = x86
TARGET = xv6.img
CPUS = 2
ROOT = $(PWD)/

ifeq ($(ARCH), x86)
QEMU = qemu-system-i386
ARCHFLAGS = -m32
ARCHLDFLAGS = -m elf_i386
endif

ifeq ($(ARCH), riscv)
QEMU = qemu-system-riscv
TOOLPREFIX = riscv64-unknown-elf-
endif

CC = $(TOOLPREFIX)gcc
LD = $(TOOLPREFIX)ld
OBJCOPY = $(TOOLPREFIX)objcopy
OBJDUMP = $(TOOLPREFIX)objdump
CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -fvar-tracking -fvar-tracking-assignments -O0 -g -Wall -MD -gdwarf-2 $(ARCHFLAGS) -Werror -fno-omit-frame-pointer -I$(INC) -I$(ARCHINC)
CFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)
ASFLAGS = $(ARCHFLAGS) -gdwarf-2 -Wa,-divide -I$(INC) -I$(ARCHINC)
LDFLAGS += $(ARCHLDFLAGS)

SRC = $(ROOT)src/
KERN = $(SRC)kern/
KERNARCH = $(KERN)arch/$(ARCH)/
SOURCE = $(KERN)source/
SCRIPTS = $(ROOT)scripts/arch/$(ARCH)/
INC = $(KERN)include/
ARCHINC = $(KERN)arch/$(ARCH)/include/
BOOT = $(SRC)boot/arch/$(ARCH)/
TOOLS = $(SRC)tools/
USERLAND = $(SRC)userland/
BIN = $(USERLAND)bin/
LIB = $(USERLAND)lib/
LIBARCH = $(USERLAND)arch/$(ARCH)/lib/

UPROGS = _cat _echo _forktest _grep _init _kill _ln _ls _mkdir _rm _sh\
		 _stressfs _usertests _wc _zombie

# Prevent deletion of intermediate files, e.g. cat.o, after first build, so
# that disk image changes after first build are persistent until clean.  More
# details:
# http://www.gnu.org/software/make/manual/html_node/Chained-Rules.html
.PRECIOUS: %.o

-include *.d
