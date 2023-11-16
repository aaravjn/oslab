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