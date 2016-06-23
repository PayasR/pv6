#include "console.h"
#include "uart.h"

// Bootstrap processor starts running C code here.
// Allocate a real stack and switch to it, first
// doing some setup required for memory allocator to work.
int
main()
{
    uartinit();
    kprint("Hello lowRISC\n");

    for (;;) {
        // loop forever
    }
}

void
panic()
{
    // disable interrupts
    // print why we're panicking
}
