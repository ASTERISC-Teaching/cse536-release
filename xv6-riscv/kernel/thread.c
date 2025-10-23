#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"

void thread_init(struct proc *p) {
    for(int i = 0; i < MAXTHREADS; i++) {
        initlock(&p->thread[i].lock, "thread_lock");
        p->thread[i].state = UNUSED;
        p->thread[i].priority = 0;
        p->thread[i].tid = i;
    }

    p->active_threads = 1;
}

void thread_create(uint64 entry_func, uint64 args[], int priority) { 
    // CSE 536: (Task 2.2.2) - Write the thread creation logic

    // find an UNUSED thread

    // set correct user + kernel context
}

void thread_destroy() {
    // CSE 536: (Task 2.2.2) - Reset thread state + yield to scheduler
}

int get_active_threads() {
    // CSE 536: (Task 2.2.2) - Get the total no of RUNNABLE threads of this process
    return 0;
}

int get_tid() {
    // CSE 536: (Task 2.2.2) - Get TID of current thread
    return 0;
}


// CSE 536: (Task 2.2.3) - Implement the scheduling algorithms
void roundRobin(struct proc *p) {
    struct cpu *c = mycpu();
    struct thread *t = &p->thread[0]; // schedule the main thread of this process

    acquire(&t->lock);
    if(t->state == RUNNABLE) {
        t->state = RUNNING;
        c->proc = p;
        c->thread = t;
        c->tid = t->tid;

        print_schedule(p, t->tid);

        swtch(&c->context, &t->context);
        c->proc = 0;
        c->thread = 0;
        c->tid = -1;
    }
    release(&t->lock);
}

void priorityScheduling(struct proc *p) {
}