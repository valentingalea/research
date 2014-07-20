#### Multi-Threading problems

##### Race conditions
where the output is dependent on the sequence or timing of other uncontrollable events. It becomes a bug when events don't happen in the order that the programmer intended

##### Deadlock
a situation in which 2 or more competing threads are waiting on each other to finish, and thus neither one advances. Ex: 2 threads wait on each other to release acquired resources

##### Livelock
similar to deadlock but instead of waiting, they change state in regard to eachother - none progressing. 

A real-world example of livelock occurs when two people meet in a narrow corridor, and each tries to be polite by moving aside to let the other pass, but they end up swaying from side to side without making any progress because they both repeatedly move the same way at the same time.

##### Starvation
is where a process is perpetually denied the necessary resources.

Starvation is often caused by errors in a scheduling algorithm, but can also be caused by resource leaks, and can be intentionally caused via a denial-of-service attack such as a fork bomb.

##### Priority inversion
is a problematic scenario in scheduling in which a high priority task is indirectly preempted by a medium priority task effectively "inverting" the relative priorities of the two tasks.

![](../src/priority_inversion.png)
