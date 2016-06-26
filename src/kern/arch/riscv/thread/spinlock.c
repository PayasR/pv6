#include "spinlock.h"

void
acquire(struct spinlock *lk)
{
    pushcli(); // disable interrupts to avoid deadlock
    if (holding(lk)) {
        panic("acquire");
    }

    // TODO acquire the lock

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

    // TODO release the lock

    popcli();
}

// TODO
void
getcallerpcs(void *v, uint pcs[])
{
}

// pushcli and popcli are matched. ie it takes two popcli to undo two pushcli.

// TODO
void
pushcli(void)
{

}

// TODO
void
popcli(void)
{
}
