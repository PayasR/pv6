#include "console.h"
#include "spinlock.h"
#include "kalloc.h"
#include "memlayout.h"
#include "string.h"
#include "trap.h"
#include "types.h"
#include "vm.h"

void freerange(void *vstart, void *vend);

struct run {
    struct run *next;
};

struct {
    struct spinlock lock;
    int use_lock;
    struct run *freelist;
} kmem;

void
kinit1(void *vstart, void *vend)
{
    initlock(&kmem.lock, "kmem");
    kmem.use_lock = 0;
    freerange(vstart, vend);
}

void
freerange(void *vstart, void *vend)
{
    cprintf("vstart: %p\n", vstart);
    cprintf("vend: %p\n", vend);
    char *p;
    p = (char *)PGROUNDUP((ulong)vstart);
    for (; p + PGSIZE <= (char*)vend; p += PGSIZE) {
        // TODO: add kfree call
    }
}
