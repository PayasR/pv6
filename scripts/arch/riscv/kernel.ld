OUTPUT_FORMAT(elf64-littleriscv)
OUTPUT_ARCH(riscv)
OUTPUT(kernel)
ENTRY(_start)

/* TODO: revist this script and remove any unnecessary commands from below */
SECTIONS
{
    /* Code and read-only segment */

    /* beginning of code and text segment */
    . = 0x80000000;

    /* program code segment */
    .text :
    {
        *(.text)
        *(.text.*)
        *(.gnu.linkonce.t.*)
    }

    .rodata :
    {
        *(.rodata)
        *(.rodata.*)
        *(.gnu.linkonce.r.*)
    }

    /* initialized data segment */
    . = ALIGN(16);
    .data :
    {
        *(.data)
    }

    /* uninitialized data segment */
    . = ALIGN(4);
    .bss :
    {
        *(.bss)
    }
}
