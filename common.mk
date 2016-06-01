# TOOLPREFIX =
# ARCH = x86
QEMU = qemu-system-i386
TARGET = xv6.img
CPUS = 2
ROOT := $(PWD)/

CC = $(TOOLPREFIX)gcc
AS = $(TOOLPREFIX)gas
LD = $(TOOLPREFIX)ld
OBJCOPY = $(TOOLPREFIX)objcopy
OBJDUMP = $(TOOLPREFIX)objdump
#CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -O2 -Wall -MD -ggdb -m32 -Werror -fno-omit-frame-pointer
CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -fvar-tracking -fvar-tracking-assignments -O0 -g -Wall -MD -gdwarf-2 -m32 -Werror -fno-omit-frame-pointer -I$(INCLUDE)
CFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)
ASFLAGS = -m32 -gdwarf-2 -Wa,-divide -I$(INCLUDE)
# FreeBSD ld wants ``elf_i386_fbsd''
LDFLAGS += -m $(shell $(LD) -V | grep elf_i386 2>/dev/null)

SOURCE = $(ROOT)pv6/kern/source/
SCRIPTS = $(ROOT)
INCLUDE = $(ROOT)pv6/kern/include/
UBIN = $(ROOT)pv6/userspace/bin/

UPROGS = _cat _echo _forktest _grep _init _kill _ln _ls _mkdir _rm _sh\
		 _stressfs _usertests _wc _zombie

# Prevent deletion of intermediate files, e.g. cat.o, after first build, so
# that disk image changes after first build are persistent until clean.  More
# details:
# http://www.gnu.org/software/make/manual/html_node/Chained-Rules.html
.PRECIOUS: %.o

-include *.d
