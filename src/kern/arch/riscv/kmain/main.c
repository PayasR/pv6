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
    kinit1(end, P2V(4*1024*1024));
    cprintf("Hello lowRISC\n");
    for (;;) {
        // loop forever
    }
}
