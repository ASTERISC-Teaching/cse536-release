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

void thread_func(uint64 a, uint64 b, uint64 c, uint64 d, uint64 e, uint64 f) {
    if(a == 10 && b == -60 && c == 20 && d == -50 && e == 30 && f == -40)
        printf("TEST PASSED\n");
    else {
        printf("TEST FAILED\n");
        printf("a = %d, b = %d, c = %d, d = %d, e = %d, f = %d\n", a, b, c, d, e, f);
    }
    thread_destroy();
}

void thread_join() {
    while(get_active_threads() != 1);
}

int
main(int argc, char *argv[])
{
    printf("[*] Running Test-2 args\n");

    /* Create a user-level thread */
    uint64 args[6] = {10,-60,20,-50,30,-40};    
    thread_create((uint64) thread_func, (uint64) args, 0);
    
    thread_join();

    return 0;
}
