#pragma once
// This is 64 bit ELF (not RISCV specific, but I wasn't sure where else to put
// it)

#include "types.h"

#define ELF_MAGIC 0X464C457FU

struct elfhdr {
    uint magic;         // must equal ELF_MAGIC
    uchar elf[12];      // ABI and unused fields
    ushort type;        // relocatable, excutable, shared, or core
    ushort machine;     // ISA
    uint version;
    ulong entry;        // memory address of process's entry point
    ulong phoff;        // points to start of program header table
    ulong shoff;        // points to start of section header table
    uint flags;
    ushort ehsize;      // size of this header (elfhdr) should be 64 bytes
    ushort phentsize;   // size of program header table entry
    ushort phnum;       // number of entries in program header table
    ushort shentsize;   // size of section header table entry
    ushort shnum;       // number of entries in the section header table
    ushort shstrndx;    // index of the section header table entry containing section names
};

struct proghdr {
    uint type;
    ulong off;
    ulong vaddr;
    ulong paddr;
    ulong filesz;
    ulong memsz;
    uint flags;
    ulong align;
};

// Value for proghdr->type
#define ELF_PROG_LOAD       1

// Flag bits for proghdr->flags
#define ELF_PROG_FLAG_EXEC  1
#define ELF_PROG_FLAG_WRITE 2
#define ELF_PROG_FLAG_READ  4
