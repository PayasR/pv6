# Disable interrupts
.globl cli
cli:
    csrc sstatus, 0x1
    ret

# Enable interrupts
.globl sti
sti:
    csrs sstatus, 0x1
    ret

# Return 1 if interrupts are enabled, 0 otherwise
.globl is_interruptible
is_interruptible:
    csrr a0, sstatus
    andi a0, a0, 0x1
    ret
