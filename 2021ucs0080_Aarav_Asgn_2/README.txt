Learning Outcomes:

The Fork system call is used for creating a new process in Linux, and Unix systems, 
which is called the child process, which runs concurrently with the process that makes the 
fork() call (parent process). After a new child process is created, both processes will execute 
the next instruction following the fork() system call.

Below are different values returned by fork().

    Negative Value: The creation of a child process was unsuccessful.
    Zero: Returned to the newly created child process.
    Positive value: Returned to parent or caller. The value contains the process ID of the newly created child process.

Thread: Thread is the segment of a process which means a process can have multiple threads 
and these multiple threads are contained within a process. The thread takes less time to 
terminate as compared to the process but unlike the process, threads do not isolate. 

Difference between Threads and Processes:-

~ Process means any program is in execution and threads means a segment of a process.
~ The Processes are isolated whereas threads share memory.
~ Changes to the parent process do not affect child processes. On the other hand all threads of 
  the same process share address space and other resources so any changes to the main thread 
  may affect the behavior of the other threads of the process.