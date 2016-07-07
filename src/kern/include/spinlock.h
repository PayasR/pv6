#pragma once

#include "types.h"

// Mutual exclusion lock.
struct spinlock {
  uint locked;       // Is the lock held?

  // For debugging:
  char *name;        // Name of lock.
  struct cpu *cpu;   // The cpu holding the lock.
  uint pcs[10];      // The call stack (an array of program counters)
                     // that locked the lock.
};

void initlock(struct spinlock *lk, char *name);
void acquire(struct spinlock *lk);
void release(struct spinlock *lk);
void getcallerpcs(void *v, uint pcs[]);
void pushcli(void);
void popcli(void);
int holding(struct spinlock *lk);
int spl_try_acquire(uint *lock);
void spl_release(uint *lock);
