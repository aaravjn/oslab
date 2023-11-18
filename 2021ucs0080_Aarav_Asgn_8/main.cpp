#include <bits/stdc++.h>
#define mem_size 500
using namespace std;

struct job {
    int id;
    int execution_time;
    int required_memory;
};
struct allocation {
    int start;
    int end;
    int process_id;
};

bool comp (const allocation &a, const allocation &b) {
    if(a.start == b.start) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

set<allocation, bool (*)(const allocation &, const allocation &)> memory_allocation_table(comp);
queue<pair<int, int>> ready_queue; // <process_id, time_remaining>
queue<job> processes;
int timer = 0; // CPU timer
bool should_allocate = 1;


pair<int, int> firstFit(job a) {
    pair<int, int> prev = {-1, -1}; // <start, end>
    for(auto it = memory_allocation_table.begin();it != memory_allocation_table.end();it++) {
        int curr_empty_size = it->start - prev.second - 1;
        if(curr_empty_size >= a.required_memory) {
            return {prev.second + 1, prev.second + a.required_memory};
        }
        prev = {it->start, it->end}; 
    }
    if(mem_size - prev.second >= a.required_memory) {
        return {prev.second + 1, prev.second + a.required_memory};
    }
    return {-1, -1};
}

pair<int, int> bestFit(job a) {
    pair<int, int> max_block = {-1, -1};
    
    pair<int, int> prev = {-1, -1}; // <start, end>
    for(auto it = memory_allocation_table.begin();it != memory_allocation_table.end();it++) {
        int curr_empty_size = it->start - prev.second - 1;
        if(curr_empty_size >= a.required_memory) {
            max_block = min(max_block, {prev.second + 1, prev.second + a.required_memory});
        }
        prev = {it->start, it->end}; 
    }
    if(mem_size - prev.second >= a.required_memory) {
        max_block = min(max_block, {prev.second + 1, prev.second + a.required_memory});
    }

    if(max_block.first != -1) {
        return max_block;
    }
    return {-1, -1};
}

pair<int, int> worstFit(job a) {
    pair<int, int> max_block = {-1, -1};
    
    pair<int, int> prev = {-1, -1}; // <start, end>
    for(auto it = memory_allocation_table.begin();it != memory_allocation_table.end();it++) {
        int curr_empty_size = it->start - prev.second - 1;
        if(curr_empty_size >= a.required_memory) {
            max_block = max(max_block, {prev.second + 1, prev.second + a.required_memory});
        }
        prev = {it->start, it->end}; 
    }
    if(mem_size - prev.second >= a.required_memory) {
        max_block = max(max_block, {prev.second + 1, prev.second + a.required_memory});
    }

    if(max_block.first != -1) {
        return max_block;
    }
    return {-1, -1};
}

// Stores the memory location of the previous allocation, the nextFit algo. has to continue from thereon.
int prev_memory_allocation = -1;
bool should_remove = 0;
pair<int, int> nextFit(job a) {
    if(mem_size - prev_memory_allocation - 1 >= a.required_memory) {
        prev_memory_allocation = prev_memory_allocation + a.required_memory;
        return {prev_memory_allocation + 1, prev_memory_allocation + a.required_memory};
    }
    should_remove = 1;
    return {-1, -1};
}


void yield_cpu() {
    int id = ready_queue.front().first;
    ready_queue.pop();
    for(auto it = memory_allocation_table.begin();it != memory_allocation_table.end();it++) {
        if(it->process_id == id) {
            memory_allocation_table.erase(it);
            break;
        }
    }
    should_allocate = 1;
}

int main() {

    ifstream newfile("input.txt");
    
    int id = 0;
    while(1) {
        int memory; newfile>>memory;
        if(memory == -1) {
            break;
        }
        int time; newfile>>time;
        processes.push({id, time, memory});
        id++;
    }

    while(!processes.empty() or !ready_queue.empty()) {
        cout<<timer<<endl;
        if(should_allocate) {
            while(!processes.empty()) {
                pair<int, int> allocated_mem_range = firstFit(processes.front());
                if(allocated_mem_range.first != -1) {
                    cout<<"Process "<<processes.front().id<<' '<<"is allocated memory from "<<allocated_mem_range.first<<' '<<"to "<<allocated_mem_range.second<<endl;
                    
                    memory_allocation_table.insert({allocated_mem_range.first, allocated_mem_range.second, processes.front().id});
                    
                    // once allocated the memory, the process is ready to execute
                    ready_queue.push({processes.front().id, processes.front().execution_time});
                    processes.pop();
                }
                else {
                    cout<<"Process "<<processes.front().id<<' '<<"couldn't be allocated memory"<<endl;
                    should_allocate = 0;
                    if(should_remove) {
                        processes.pop();
                        should_remove = 0;
                    }
                    break;
                }
            }
        }
        if(--ready_queue.front().second == 0) {
            cout<<"Process "<<ready_queue.front().first<<" has completed it's execution"<<endl;
            yield_cpu();
        }
        timer++;
    }
}