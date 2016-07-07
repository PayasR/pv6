#include "trap.h"

inline void
cli(void)
{
    asm volatile("cli");
}

inline void
sti(void)
{
    asm volatile("sti");
}
