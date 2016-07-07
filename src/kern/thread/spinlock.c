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

