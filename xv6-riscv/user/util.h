
#include "kernel/types.h"
#include "user/user.h"

void delay(uint64 val) {
    for(uint64 i = 0; i < val; i++);
}