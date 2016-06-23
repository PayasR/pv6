# This function takes a single byte as input
# void uartputc(char byte)
.globl uartputc
uartputc:
    li t0, 0x40001000 # UART output start
    sb a0, 0(t0) # output argument
    ret
