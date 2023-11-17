You need to implement a toy file management system.  Disk has `256` blocks (so each block shall require 1-byte address). Directory size shall be `256` entries, each entry shall be name of file  (2 bytes), size of file (in terms of number of blocks) 1 byte, address of first block (1 byte). So size of directory shall be 256 x 4 bytes = 1024 bytes = 1 KB. We are assuming that filename is almost two characters and is case-sensitive. You can represent this file system as a directory (an array of 256 entries) and an array to represent 256 blocks.   In this array, you should be able to identify if a block is occupied (by some file) or empty (available for allocation).

(A) **`Linked allocation`**: here each block keeps information about `next block` and `previous block` (last two bytes keep these pointers and -1 represents NULL)

(B) **`Linked Indexed allocation`**: Each file shall consist of `Index block` and `data blocks`; index block shall keep pointers to data blocks (data blocks of a file are linked together through a double linked file; each data block shall have pointer to next block and last data block should point to NULL). Directory shall keep name of file and pointer to Index block.

Simulation set up
User requests shall be read from a file "input.dat". This file consists of multiple lines; each line corresponds to a request. Each line has following information
Name of File,  D (deletion)/ C (creation)/ M (modification), Size of file (number of blocks)
So a sample file is as follows:
```
A   C  20     // Create a file A and allocate 20 blocks 
B   C  10     // Create a file B and allocate 10 blocks
C   C  50     // Create a file C  and allocate 50 blocks 
D   C  24     // Create a file D and allocate 24 blocks 
A   M  16     // Change size of file A to 16 blocks
B   M  15     // Change size of file B to 15 blocks 
C   D  0      // Delete file C; here size field does not matter
```

So your program should apply any of first fit mechanism to allocate blocks to the file. After every request, the program should print the disk status as 256 characters where for each allocated block it should print name of file else "*" for unallocated block. For better representation, present this data as 16 blocks per line. So output would appear as follows
AAA\*\*\*\*\*\*\*\*\*BBBB <br>
BB\*\*\*\*\*\*\*\*\*\*\*\*\*\* <br>
If file A is allocated 3 blocks, then 9 blocks are empty and 6 blocks are allocated to B.

Index block should be represented by # in your output.

A -1 in the "input.dat" should indicate the end of file.