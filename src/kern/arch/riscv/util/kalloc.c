#include "kalloc.h"
#include "string.h"

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
    char *p;
    p = (char *)PGROUNDUP((ulong)vstart);
    for (; p + PGSIZE <= (char*)vend; p += PGSIZE) {
        kfree(p);
    }
}

void
kfree(char *v)
{
    struct run *r;

    if ((ulong)v % PGSIZE || v < end || v2p(v) >= PHYSTOP) {
        panic("kfree");
    }

    // Fill with junk to catch dangling refs
    memset(v, 1, PGSIZE);

    if (kmem.use_lock) {
        acquire(&kmem.lock);
    }

    r = (struct run *)v;
    r->next = kmem.freelist;
    kmem.freelist = r;

    if (kmem.use_lock) {
        release(&kmem.lock);
    }
}
