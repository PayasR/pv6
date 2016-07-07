#include "console.h"
#include "uart.h"
#include "trap.h"

#define BACKSPACE 0X100

extern int panicked;

void
consputc(int c)
{
    if (panicked) {
        cli();
        for (;;)
            ;
    }

    if (c == BACKSPACE) {
        uartputc('\b');
        uartputc(' ');
        uartputc('\b');
    } else {
        uartputc(c);
    }
}
