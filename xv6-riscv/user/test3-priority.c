#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"
#include "user/uspinlock.h"

#include <stdarg.h>


void thread_func1(void) {
    /* Start the thread here. */
    for (uint64 i = 0; i < (uint64)1*100000000; i++);

    /* Notify for a thread exit. */
    thread_destroy();
}

void thread_func2(void) {
    /* Start the thread here. */
    for (uint64 i = 0; i < (uint64)2*1000000000; i++);

    /* Notify for a thread exit. */
    thread_destroy();
}

void thread_func3(void) {
    /* Start the thread here. */
    for (uint64 i = 0; i < (uint64)3*1000000000; i++);

    /* Notify for a thread exit. */
    thread_destroy();
}

void thread_func4(void) {
    /* Start the thread here. */
    for (uint64 i = 0; i < (uint64)4*1000000000; i++);

    /* Notify for a thread exit. */
    thread_destroy();
}

void thread_join() {
    while(get_active_threads() != 1);
}

int
main(int argc, char *argv[])
{
    /* Create a user-level thread */
    uint64 args[6] = {0,0,0,0,0,0};    
    thread_create((uint64) thread_func1, (uint64) args, 10);
    thread_create((uint64) thread_func2, (uint64) args, 20);
    thread_create((uint64) thread_func3, (uint64) args, 30);
    thread_create((uint64) thread_func4, (uint64) args, 40);
    
    thread_join();

    return 0;
}
