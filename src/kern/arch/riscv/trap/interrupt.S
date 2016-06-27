# Disable interrupts
.globl cli
cli:
    csrc sstatus, 0x1

# Enable interrupts
.globl sti
sti:
    csrs sstatus, 0x1
