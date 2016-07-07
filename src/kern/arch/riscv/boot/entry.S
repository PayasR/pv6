#include "param.h"

.globl _start
_start:
    csrc sstatus, 0x1 # clear interrupts
    # TODO turn on paging
    li sp, 0x80100000 # TODO: detect how much memory we have and start stack there
    call main
