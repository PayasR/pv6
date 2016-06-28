# try to acquire the lock
# a0 - (&lk->locked), should be 0 before calling
# returns 0 if successful, 1 otherwise
.globl spl_try_acquire
spl_try_acquire:
    li t0, 1
    amoswap.d.aq t0, t0, (a0)
    ret

# release the lock
# a0 - (&lk->locked), should be 1 before calling, will be 0 afterwards
.globl spl_release
spl_release:
    amoswap.d.rl x0, x0, (a0)
    ret
