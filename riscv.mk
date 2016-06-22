# Unlike on x86, we don't generate a bootblock because our simulator doesn't
# expect one. Adding one later would be fairly easy.
archall: kernel

# On RISC-V we use spike rather than QEMU because spike has better support and
# is easier to extend when necessary.
spike:
	spike kernel

spike-debug:
	spike -d kernel
