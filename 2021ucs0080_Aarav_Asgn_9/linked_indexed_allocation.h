#include <bits/stdc++.h>
using namespace std;

#define numOfDiskBlocks 256
#define numOfDirectoryEntry 256

class LinkedIndexedAllocation {
    private:
        struct fileBlock {
            bool isIndexBlock; // bool to check if it is index block or data block
            int next = -2; // if is data block, it will have a valid next pointer
            vector<int> dataBlockLocations; // if it is index block, it will have pointers to all the data blocks
        };
        struct directoryEntry {
            string fileName = "NULL";
            int fileSize; // in terms of number of blocks
            int indexBlock; // address of index block
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

            // search for space to fit index block
            fileBlock* indexBlock = NULL;
            for(fileBlock &block : Disk) {
                if(block.next == -2) {
                    firstEmpty->indexBlock = &block - Disk;
                    block.next = -1;
                    block.isIndexBlock = 1;
                    indexBlock = &block;
                    break;
                }
            }

            // insert datablocks in first fit manner in the disk
            int diskPtr = 0;
            int prevDiskPtr = -1;
            for(int i = 0;i < size;i++) {
                // find an empty block in the Disk, if empty, the disk block will have next = -2
                while(Disk[diskPtr].next != -2) {
                    diskPtr++;
                }
                
                Disk[diskPtr].next = -1; // set it's next to null
                indexBlock->dataBlockLocations.push_back(diskPtr);
                if(prevDiskPtr != -1) { // if not the first block, set the next of the prev block
                    Disk[prevDiskPtr].next = diskPtr;    
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
            fileBlock* index = &Disk[fileEntry->indexBlock];

            // Traverse over the list of data block locations
            for(int idx : index->dataBlockLocations) {
                Disk[idx].next = -2;
            }
            index->next = -2; // make the index block null
            index->dataBlockLocations.clear(); // delete the indices
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
            fileBlock* index = &Disk[fileEntry->indexBlock];

            // Start truncating/adding the blocks till the newSize is not achieved
            if(changeInCount > 0) {
                // truncate blocks
                for(int i = 0;i < changeInCount;i++) {
                    int idx = index->dataBlockLocations.back();
                    index->dataBlockLocations.pop_back();
                    Disk[idx].next = -2;
                }
            }
            else {
                // insert datablocks in first fit manner in the disk
                int diskPtr = 0;
                int prevDiskPtr = index->dataBlockLocations.size() > 0 ? index->dataBlockLocations.back() : -1;

                for(int i = 0;i < -changeInCount;i++) {
                    // find an empty block in the Disk
                    while(Disk[diskPtr].next != -2) {
                        diskPtr++;
                    }

                    Disk[diskPtr].next = -1; // set it's next to null
                    if(prevDiskPtr != -1) { // if not the first block, set the next of the prev block
                        Disk[prevDiskPtr].next = diskPtr;
                    }
                    index->dataBlockLocations.push_back(diskPtr);
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
                    fileBlock* index = &Disk[entry.indexBlock];
                    state[entry.indexBlock] = entry.fileName[0] > 96 ? entry.fileName[0] - 32 : entry.fileName[0] + 32;
                    for(int idx : index->dataBlockLocations) { // get the indices of data blocks from index block
                        state[idx] = entry.fileName[0];
                    }
                }
            }
            /*
            Writing the output of the code in a file.
            lower case letters in the ouptut represent index block of that particular file
            Uppercase letters represent data block of the file 
            */
            for(int i = 0;i < numOfDiskBlocks;i++) {
                if(i % 16 == 0) cout<<endl;    
                cout<<state[i];
            }
            cout<<endl;
        }
};