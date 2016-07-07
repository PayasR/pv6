#pragma once

#include "param.h"
#include "types.h"

struct cpu {
    uchar id;                   // index into cpus[] below
    struct context *scheduler;  // swtch() here to enter scheduler
    volatile uint started;      // has the CPU started?
    int ncli;                   // depth of pushcli nesting
    int intena;                 // were interrupts enabled before puscli?
};

extern struct cpu cpus[NCPU];
extern int ncpu;

// Per-CPU variables
struct cpu *cpu;
struct proc *proc;

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

struct context {
};

struct proc {
    uint sz;                    // size of process memory (bytes)
    pde_t *pgdir;               // page table
    char *kstack;               // bottom of kernel stack for this process
    enum procstate state;       // process state
    int pid;                    // process ID
    struct proc *parent;        // parent process
    struct trapframe *tf;       // trap frame for current syscall
    struct context *context;    // swtch() here to run process
    void *chan;                 // if non-zero, sleeping on chan
    int killed;                 // if non-zero, have been killed
    struct file *ofile[NOFILE]; // open files
    struct inode *cwd;          // current directory
    char name[16];              // process name (debugging)
};

// Process memory is laid out continguously, low addresses first:
//  text
//  original data and bss
//  fixed-size stack
//  expandable heap
