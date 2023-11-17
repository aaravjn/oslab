#include <bits/stdc++.h>
#include <linked_allocation.h>
#include <linked_indexed_allocation.h>

using namespace std;

int main() {
    // Do some operation using a filesystem of your choice
    // LinkedIndexedAllocation* fs = new LinkedIndexedAllocation();
    LinkedAllocation* fs = new LinkedAllocation();

    ifstream newfile("input.dat");
    
    while(1) {
        string file; newfile>>file;
        if(file == "-1") {
            break;
        }
        char operation; newfile>>operation;
        int size; newfile>>size;

        if(operation == 'C') { // Create a file
            fs->createFile(file, size);
        }
        else if(operation == 'M') { // Modify a file
            fs->changeFileSize(file, size);
        }
        else if(operation == 'D') { // Delete a file
            fs->deleteFile(file);
        }
        fs->printDiskState();   
    }
}