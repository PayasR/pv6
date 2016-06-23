#include "console.h"
#include "uart.h"

void
kprint(char *msg)
{
    while (*msg != 0) {
        uartputc(*msg);
        msg++;
    }
}
