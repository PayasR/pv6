.globl _start
_start:
    csrc sstatus, 0x1 # clear interrupts
    li sp, 0x80010000
    call main
