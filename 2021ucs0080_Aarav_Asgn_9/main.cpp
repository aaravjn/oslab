#include <bits/stdc++.h>
#define numOfDiskBlocks 256
#define numOfDirectoryEntry 256

using namespace std;


class LinkedAllocation {
    private:
        struct fileBlock {
            int prev; // prev block pointer
            int next; // next block pointer
        };
        struct directoryEntry {
            string fileName;
            int fileSize; // in terms of number of blocks
            int firstBlock; // address of first block
        };
        fileBlock Disk[numOfDiskBlocks];
        directoryEntry Directory[numOfDirectoryEntry];

    public:
        void createFile(string file, int size) {
            // find the first empty entry in the directory
            directoryEntry* firstEmpty;
            for(directoryEntry entry: Directory) {
                if(entry.fileName != "NULL") {
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
            for(directoryEntry entry: Directory) {
                if(entry.fileName != "NULL") {
                    fileEntry = &entry;
                    break;
                }
            }

            // Traverse the entire linkedlist and make each node null
            fileBlock* block = &Disk[fileEntry->firstBlock];
            while(block->next != -1) {
                block->prev = -2;
                block = &Disk[block->next];
            }
        }

        void changeFileSize(string file, int newSize) {
            // find the directory block with the given file name
            directoryEntry* fileEntry;
            for(directoryEntry entry: Directory) {
                if(entry.fileName != "NULL") {
                    fileEntry = &entry;
                    break;
                }
            }
            int changeInCount = fileEntry->fileSize - newSize;

            // Traverse the entire linkedlist to get the last block.
            fileBlock* block = &Disk[fileEntry->firstBlock];
            while(block->next != -1) {
                block->prev = -2;
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
            }
            else {
                // insert datablocks in first fit manner in the disk
                int diskPtr = 0;
                int prevDiskPtr = -1;
                for(int i = 0;i < -changeInCount;i++) {
                    // find an empty block in the Disk
                    while(Disk[diskPtr].prev != -2) {
                        diskPtr++;
                    }

                    Disk[diskPtr].prev = prevDiskPtr; // set the prev of new block, prev = -1 represents first added block
                    Disk[diskPtr].next = -1; // set it's next to null
                    if(prevDiskPtr != -1) { // if not the first block, set the next of the prev block
                        Disk[prevDiskPtr].next = diskPtr;
                    }
                    else {
                        block->next = diskPtr;
                        Disk[diskPtr].prev = block - Disk; // index of the lask block
                    }
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
                int first = entry.firstBlock;
                while(first != -1) {
                    state[first] = entry.fileName[0]; // take the first character of the file
                    first = Disk[first].next;
                }
            }

            cout<<state<<endl;
        }
};


class LinkedIndexedAllocation {
    private:
        struct fileBlock {
            bool isIndexBlock; // bool to check if it is index block or data block
            int next; // if is data block, it will have a valid next pointer
            vector<int> dataBlockLocations; // if it is index block, it will have pointers to all the data blocks
        };
        struct directoryEntry {
            string fileName;
            int fileSize; // in terms of number of blocks
            int indexBlock; // address of index block
        };
        fileBlock Disk[numOfDiskBlocks];
        fileBlock Directory[numOfDirectoryEntry];

    
    public:
        void createFile(string file, int size) {
            ;
        }
        void deleteFile(string file) {
            ;
        }
        void changeFile(string file, int newSize) {
            ;
        }
        void printDiskState() {
            ;
        }
};


int main() {
    ifstream newfile("input.dat");
    
    while(1) {
        string file; newfile>>file;
        if(file == "-1") {
            break;
        }
        char operation; newfile>>operation;
        int size; newfile>>size;

        // Do some operation using a filesystem of your choice
    }
}