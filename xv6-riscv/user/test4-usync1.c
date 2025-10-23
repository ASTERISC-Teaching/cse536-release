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

int data = 0;
// struct uspinlock data_lock;

void inc(void) {
    // uacquire(&data_lock);
    data++;
    // urelease(&data_lock);
}

void thread_func(int iter) {
    // Simulate enough delay so that the other threads call inc() concurrently
    delay(100000000);

    for(int i = 0; i < iter; i++)
        inc();

    thread_destroy();
}

void thread_join() {
    while(get_active_threads() != 1);
}

int
main(int argc, char *argv[])
{
    printf("[*] Running Test 4 - userspace synchronization 1\n");
    
    // uinitlock(&data_lock, "data_lock");

    int iter = 30000;

    /* Create a user-level thread */
    uint64 args[6] = {iter,0,0,0,0,0};    
    thread_create((uint64) thread_func, (uint64) args, -1);
    thread_create((uint64) thread_func, (uint64) args, -1);
    thread_create((uint64) thread_func, (uint64) args, -1);
    
    thread_join();

    if(data == iter*3)
        printf("[*] Test PASSED, data = %d\n", data);
    else
        printf("[*] Test FAILED, data = %d\n", data);
    return 0;
}