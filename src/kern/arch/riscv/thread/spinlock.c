#include "proc.h"
#include "spinlock.h"
#include "trap.h"
#include "console.h"
#include "arch/trap.h"

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

    spl_release(&lk->locked);

    popcli();
}

// FIXME: this should be architecture independent, but it can't be until I
// figure out what the deal is with the cpu problem I was encountering
int
holding(struct spinlock *lk)
{
    return lk->locked;
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
