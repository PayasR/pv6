#pragma once
#include "spinlock.h"

struct {
    struct spinlock lock;
    int locking;
} cons;

void kprint(char *msg);
void consputc(int);
void panic(char *msg);

