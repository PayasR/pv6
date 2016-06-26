#include "proc.h"
#include "spinlock.h"
#include "types.h"

void
initlock(struct spinlock *lk, char *name)
{
    lk->name = name;
    lk->locked = 0;
    lk->cpu = 0;
}

// Check whether this cpu is holding the lock
int
holding(struct spinlock *lk)
{
    return lk->locked && lk->cpu == cpu;
}
