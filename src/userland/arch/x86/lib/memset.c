#include "types.h"
#include "x86.h"

void *
memset(void *dst, int c, uint n)
{
    stosb(dst, c, n);
    return dst;
}
