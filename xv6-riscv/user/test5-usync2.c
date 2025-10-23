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
#include "user/util.h"

#include <stdarg.h>

void thread_func1(int iter) {
    // Simulate enough delay so that the other threads call inc() concurrently
    delay(100000000);

    printf("Hello from thread 1\n");
    printf("Goodbye from thread 1\n");

    thread_destroy();
}

void thread_func2(int iter) {
    // Simulate enough delay so that the other threads call inc() concurrently
    delay(100000000);

    printf("Hello from thread 2\n");
    printf("Goodbye from thread 2\n");

    thread_destroy();
}

void thread_func3(int iter) {
    // Simulate enough delay so that the other threads call inc() concurrently
    delay(100000000);

    printf("Hello from thread 3\n");
    printf("Goodbye from thread 3\n");

    thread_destroy();
}

void thread_join() {
    while(get_active_threads() != 1);
}

int
main(int argc, char *argv[])
{
    printf("[*] Running Test 5 - userspace synchronization 2\n");
    
    /* Create a user-level thread */
    uint64 args[6] = {0,0,0,0,0,0};    
    thread_create((uint64) thread_func1, (uint64) args, -1);
    thread_create((uint64) thread_func2, (uint64) args, -1);
    thread_create((uint64) thread_func3, (uint64) args, -1);
    
    thread_join();

    return 0;
}