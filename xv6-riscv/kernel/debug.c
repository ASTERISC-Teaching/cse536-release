#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "elf.h"

void print_schedule(struct proc *p, int tid) {
    int is_test1 = strncmp(p->name, "test1-rr", 8) == 0;
    int is_test3 = strncmp(p->name, "test3-priority", 14) == 0;

    if(!is_test1 && !is_test3)
        return;
    
    printf("proc(%s) [PID = %d] scheduling thread [%d]\n", p->name, p->pid, tid);
}