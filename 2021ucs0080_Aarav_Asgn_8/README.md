You need to implement variable partitioning memory management. We shall assume that `500 MB` memory is available and each program requires an integer multiple of `1 MB` memory Memory manager receives requests for memory allocation for programs. 

This sequence needs to be read from a file called req.txt. File contains a sequence of tuples `<process size, execution time>` 
where size is a positive integer. These tuples are separated by comma. A `-1` at the end indicates the termination of sequence.
So a sequence <31, 12>, <34, 7>, -1 means that 2 processes need to be loaded and these require 31 MB and 34 MB respectively. 
First process can be completed in 12 time units and second in 7 time units respectively. CPU scheduling is `FCFS`.
So space reserved by a process is marked free once it's execution is completed.

Memory manager as per allocation policy `(First fit, Best fit, Worst fit, Next fit)` shall allocate and free space. 
If a process can not be allocated space, it shall be queued in waiting. After all requests are served, print the output of waiting queue for each management policy.