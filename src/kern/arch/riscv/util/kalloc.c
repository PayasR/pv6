#include "console.h"
#include "spinlock.h"
#include "kalloc.h"
#include "memlayout.h"
#include "string.h"
#include "trap.h"
#include "types.h"
#include "vm.h"

void freerange(void *vstart, void *vend);
extern char end[]; // first address after kernel loaded from ELF file

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
    // TODO: complete this
}
