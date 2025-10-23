// Mutual exclusion spin locks.

#include "kernel/types.h"
#include "user/uspinlock.h"
#include "user/user.h"

void
uinitlock(struct uspinlock *lk, char *name)
{
}

void panic1(char *msg) {
  printf("%s", msg);
  for(;;);
}

// Acquire the lock.
// Loops (spins) until the lock is acquired.
void
uacquire(struct uspinlock *lk)
{
}

// Release the lock.
void
urelease(struct uspinlock *lk)
{
}

int
uholding(struct uspinlock *lk)
{
  return 0;
}