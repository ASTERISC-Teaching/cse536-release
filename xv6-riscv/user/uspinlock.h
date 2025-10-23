// Mutual exclusion lock.
struct uspinlock {
  uint locked;       // Is the lock held?

  // For debugging:
  char *name;        // Name of lock.
  int tid;          // thread ID
}__attribute((aligned(4)));