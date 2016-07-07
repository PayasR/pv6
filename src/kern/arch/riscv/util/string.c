#include "types.h"
#include "trap.h"
#include "console.h"

// This is a simple implementation. There are much trickier versions of memset
// out there. Technically this implementation is portable so it doesn't need to
// go in the RISC-V tree, but the x86 version uses assembly so I decided to put
// this version here. (This implementation also uses ulong instead of uint for
// the type of n because ulong is 64 bits on RISC-V while uint is only 32.
void *
memset(void *dst, int c, ulong n)
{
    if (c < 0) {
        panic("memset argument invalid\n");
    }

    char *buf = dst;
    while (c--) {
        *buf++ = (char)c;
    }

    return dst;
}
