#include "console.h"
#include "kalloc.h"
#include "memlayout.h"
#include "proc.h"
#include "uart.h"
#include "trap.h"

extern char end[]; // first address after kernel loaded from ELF file

// Bootstrap processor starts running C code here.
// Allocate a real stack and switch to it, first
// doing some setup required for memory allocator to work.
int
main()
{
    // This is here temporarily, eventually I'll move it somewhere else
    struct cpu c = {
        .id = 0,
        .scheduler = 0,
        .started = 1,
        .ncli = 0,
        .intena = 0
    };
    cpu = &c;

    cprintf("%d\n", 42);
    cprintf("Hello lowRISC\n");

    for (;;) {
        // loop forever
    }
}
