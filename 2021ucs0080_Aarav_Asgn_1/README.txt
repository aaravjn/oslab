Learning Outcomes:

READ/WRITE functions will only read/write 'char' datatype. Fails to write 'int' datatype in terminal. 
Same is the case with READ. It takes the file descriptor, memory buffer, and number of bytes to read/write. 
File descriptor for our standard output device(screen) is '1', '0' for our standard input device(keyboard).

OPEN function provides a file descriptor which is a unique integer to identify any open file.

DUP function provides the lowest unused file descriptor from an old file descriptor. It duplicates the old file descriptor.
If the copy is successfully created, then the original and copy file descriptors may be used interchangeably.

LSEEK function repositions the pointer to read/write a file by a certain offset. It takes file descriptor,
number of offset bytes, and reference point of the movement as it's input, eg: 'SEEK_CUR'.

FORK is used to create a new thread from the same program called a 'child process'. It helps in processing independent processes
simultaneously. After the fork instruction, both the processes will simultaneously run the next lines
of the same code.
It returns 3 types of values:
    Negative: Creating the new fork was Unsuccesfull.
    Zero: Returned to the newly created child process.
    Positive: Returned to parent.

ORPHAN process is a type of process whose parent process has terminated.