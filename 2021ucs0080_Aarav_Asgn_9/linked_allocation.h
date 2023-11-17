/*
Simply execute `make` in the terminal to compile and run the program
It will give the output in `output.txt`.
*/


#include <bits/stdc++.h>
using namespace std;
#define numOfDiskBlocks 256
#define numOfDirectoryEntry 256


class LinkedAllocation {
    private:
        struct fileBlock {
            int prev = -2; // prev block pointer
            int next = -2; // next block pointer
        };
        struct directoryEntry {
            string fileName = "NULL";
            int fileSize; // in terms of number of blocks
            int firstBlock; // address of first block
        };
        fileBlock Disk[numOfDiskBlocks];
        directoryEntry Directory[numOfDirectoryEntry];

    public:
        void createFile(string file, int size) {
            // find the first empty entry in the directory
            directoryEntry* firstEmpty;
            for(directoryEntry &entry: Directory) {
                if(entry.fileName == "NULL") {
                    firstEmpty = &entry;
                    break;
                }
            }

            firstEmpty->fileName = file;
            firstEmpty->fileSize = size;

            // insert datablocks in first fit manner in the disk
            int diskPtr = 0;
            int prevDiskPtr = -1;
            for(int i = 0;i < size;i++) {
                // find an empty block in the Disk, if empty, the disk block will have prev = -2
                while(Disk[diskPtr].prev != -2) {
                    diskPtr++;
                }

                Disk[diskPtr].prev = prevDiskPtr; // set the prev of new block, prev = -1 represents first block
                Disk[diskPtr].next = -1; // set it's next to null
                if(prevDiskPtr != -1) { // if not the first block, set the next of the prev block
                    Disk[prevDiskPtr].next = diskPtr;
                }
                else {
                    firstEmpty->firstBlock = diskPtr;
                }
                prevDiskPtr = diskPtr;
            }
        }

        void deleteFile(string file) {
            // find the directory block with the given file name
            directoryEntry* fileEntry;
            for(directoryEntry &entry: Directory) {
                if(entry.fileName == file) {
                    fileEntry = &entry;
                    break;
                }
            }
            fileEntry->fileName = "NULL";

            // Traverse the entire linkedlist and make each node null
            fileBlock* block = &Disk[fileEntry->firstBlock];
            while(block->next != -1) {
                block->prev = -2;
                block = &Disk[block->next];
            }
            block->prev = -2;
        }

        void changeFileSize(string file, int newSize) {
            // find the directory block with the given file name
            directoryEntry* fileEntry;
            for(directoryEntry &entry: Directory) {
                if(entry.fileName == file) {
                    fileEntry = &entry;
                    break;
                }
            }
            int changeInCount = fileEntry->fileSize - newSize;
            fileEntry->fileSize = newSize;

            // Traverse the entire linkedlist to get the last block.
            fileBlock* block = &Disk[fileEntry->firstBlock];
            while(block->next != -1) {
                block = &Disk[block->next];
            }

            // After accessing the last block, start truncating/adding the blocks till the newSize is not achieved
            if(changeInCount > 0) {
                // truncate blocks
                for(int i = 0;i < changeInCount;i++) {
                    int prevPtr = block->prev;
                    block->prev = -2;
                    if(prevPtr != -1) {
                        block = &Disk[prevPtr];
                    }
                }
                block->next = -1;
            }
            else {
                // insert datablocks in first fit manner in the disk
                int diskPtr = 0;
                int prevDiskPtr = block - Disk;
                for(int i = 0;i < -changeInCount;i++) {
                    // find an empty block in the Disk
                    while(Disk[diskPtr].prev != -2) {
                        diskPtr++;
                    }

                    Disk[diskPtr].prev = prevDiskPtr; // set the prev of new block, prev = -1 represents first added block
                    Disk[diskPtr].next = -1; // set it's next to null
                    Disk[prevDiskPtr].next = diskPtr; // set the next of the prev block
                    prevDiskPtr = diskPtr;
                }
            }
        }

        void printDiskState() {
            string state = "";
            for(int i = 0;i < numOfDiskBlocks;i++) { // initialize disk state
                state += '*';
            }

            for(directoryEntry &entry: Directory) {
                if(entry.fileName != "NULL") {
                    int first = entry.firstBlock;
                    while(first != -1) {
                        state[first] = entry.fileName[0]; // take the first character of the file
                        first = Disk[first].next; // move to the next block
                    }
                }
            }

            for(int i = 0;i < numOfDiskBlocks;i++) {
                if(i % 16 == 0) cout<<endl;    
                cout<<state[i];
            }
            cout<<endl;
        }
};