#include "uart.h"

// the spike 8250 UART is missing a lot of functionality, so we don't need to
// do anything here for now.
void
uartinit(void)
{
    char *p;
    // Announce that we're here
    for (p = "pv6 uart enabled\n"; *p; p++) {
        uartputc(*p);
    }
}
