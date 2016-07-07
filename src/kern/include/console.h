#pragma once
#include "spinlock.h"

struct {
    struct spinlock lock;
    int locking;
} cons;

void consputc(int);
void panic(char *msg);
void cprintf(char *fmt, ...);
