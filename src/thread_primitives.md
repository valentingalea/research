#### common thread *synchronization primitives*

1. *CompareAndSwap* instructions - atomic (that is no other thread can preempt it) only writes after the compare with a known value is true
2. *Mutex* - locking mechanism used to synchronize access to a resource. only one "thing" at a time can acquire the mutex and the same "thing" must release it -- thus OWNERSHIP property
3. *Semaphore* - generalized mutex based on counting. NO ownership property, multiple threads can increase/decrease, when 0 it waits
4. *Condition Variable* - used for signalling/event passing
5. *Memory Fence* - a class of instructions that mean memory read/writes occur in the order you expect -- for example a 'full fence' means all read/writes before the fence are committed before those after the fence.
