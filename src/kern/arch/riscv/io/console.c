#include "console.h"
#include "uart.h"

void
kprint(char *msg)
{
    char *p = msg;
    while (*p != 0) {
        uartputc(*p);
        p++;
    }
}
