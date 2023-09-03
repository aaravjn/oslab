Learning Outcomes:-

~ FCFS Scheduling:

Simplest CPU scheduling algorithm that schedules according to arrival times of processes. 
First come first serve scheduling algorithm states that the process that requests the CPU first is allocated the CPU first. 
It is implemented by using the FIFO queue.

~ SJF Scheduling:

The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting 
process with the smallest execution time to execute next. SJN, also known as Shortest Job Next (SJN),
can be preemptive or non-preemptive.

~ RR Scheduling:

Round Robin is a CPU scheduling algorithm where each process is assigned a fixed time slot in a 
cyclic way. It is basically the preemptive version of First come First Serve CPU Scheduling algorithm. 

1. Round Robin CPU Algorithm generally focuses on Time Sharing technique. 
2. The period of time for which a process or job is allowed to run in a pre-emptive method is 
    called time quantum. 
3. Each process or job present in the ready queue is assigned the CPU for that time quantum, 
    if the execution of the process is completed during that time then the process will end else 
    the process will go back to the waiting table and wait for its next turn to complete the execution.

~ MLFQ Scheduling

Multilevel Feedback Queue Scheduling (MLFQ) CPU Scheduling is like Multilevel Queue(MLQ) 
Scheduling but in this process can move between the queues. And thus, much more efficient than 
multilevel queue scheduling.

1. Multiple queues: Similar to MLQ scheduling, MLFQ scheduling divides processes into multiple 
    queues based on their priority levels. However, unlike MLQ scheduling, processes can move 
    between queues based on their behavior and needs.
2. Priorities adjusted dynamically: The priority of a process can be adjusted dynamically based on 
    its behavior, such as how much CPU time it has used or how often it has been blocked. 
    Higher-priority processes are given more CPU time and lower-priority processes are given less.
3. Time-slicing: Each queue is assigned a time quantum or time slice, which determines how much 
    CPU time a process in that queue is allowed to use before it is preempted and moved to a lower 
    priority queue.
4. Feedback mechanism: MLFQ scheduling uses a feedback mechanism to adjust the priority of a 
    process based on its behavior over time. For example, if a process in a lower-priority queue 
    uses up its time slice, it may be moved to a higher-priority queue to ensure it gets more CPU 
    time.
5. Preemption: Preemption is allowed in MLFQ scheduling, meaning that a higher-priority process can 
    preempt a lower-priority process to ensure it gets the CPU time it needs.

~ Lottery Scheduling:

Lottery Scheduling is a type of process scheduling, somewhat different from other Scheduling. 
Processes are scheduled in a random manner. Lottery scheduling can be preemptive or non-preemptive. 
It also solves the problem of starvation. Giving each process at least one lottery ticket guarantees 
that it has a non-zero probability of being selected at each scheduling operation. 
In this scheduling every process has some tickets and the scheduler picks a random ticket and 
process having that ticket is the winner and it is executed for a time slice and then another 
ticket is picked by the scheduler. These tickets represent the share of processes. 
A process having a higher number of tickets give it more chance to get chosen for execution. 