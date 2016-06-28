#include "spinlock.h"

void
acquire(struct spinlock *lk)
{
    pushcli(); // disable interrupts to avoid deadlock
    if (holding(lk)) {
        panic("acquire");
    }

    while(spl_try_acquire(&lk->locked) != 0)
        ;

    lk->cpu = cpu;
    getcallerpcs(&lk, lk->pcs);
}

void
release(struct spinlock *lk)
{
    if (!holding(lk)) {
        panic("release");
    }

    lk->pcs[0] = 0;
    lk->cpu = 0;

    spl_release(&lk->locked) != 0)

    popcli();
}

// TODO
void
getcallerpcs(void *v, uint pcs[])
{
}

// pushcli and popcli are matched. ie it takes two popcli to undo two pushcli.

void
pushcli(void)
{
    int interruptible = is_interruptible();
    cli();
    if (cpu->ncli++ == 0) {
        cpu->intena = interruptible;
    }
}

void
popcli(void)
{
    // TODO
    if (is_interruptible()) {
        panic("popcli - interruptible");
    }
    if (--cpu->ncli < 0) {
        panic("popcli");
    }
    if (cpu->ncli == 0 && cpu->intena) {
        sti();
    }
}
