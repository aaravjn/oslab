// LOTTERY SCHEDULING


#include <bits/stdc++.h>

using namespace std;
const int TIME_QUANTUM = 4;
int curr_time = 0;
int j = 0;

// Implementing the scheduling algorithm
void scheduler(vector<vector<int>> &jobs, vector<vector<int>> &processes, int &i, int &timer, int n) {
    while(i < n and timer == jobs[i][0]) {
        cout<<"timer: "<<timer<<"-----";
        cout<<"Job with ID: "<<jobs[i][2]<<" has arrived the ready stage"<<endl;

        processes.push_back(jobs[i]);
        i++;
    }

    if(curr_time == 0) {
        vector<int> pre (processes.size());
        int sum = 0;
        for(int i = 0;i < processes.size();i++) {
            pre[i] = processes[i][1] + sum;
            sum += processes[i][1];
        }

        int x = rand() % sum;
        j = upper_bound(pre.begin(), pre.end(), x) - pre.begin();
    }

    if(--processes[j][1] == 0) {
        cout<<"timer: "<<timer<<"-----";
        cout<<"Job with ID: "<<processes[j][2]<<" was completed"<<endl;
        processes.erase(processes.begin() + j);
        curr_time = 0;
    }
    else if(++curr_time == TIME_QUANTUM) {
        curr_time = 0;
    }
}

int main() {

    /*
        CONVENTION: The array 'jobs' contains all the jobs to be executed. The 1st integer in each job 
        is the arrival time of the job. The 2nd integer is the time required to complete the job. The
        3rd integer represents the process ID of the job.
    */

    vector<vector<int>> jobs{{1, 10, 1}, {2, 2, 2}, {2, 4, 3}, {4, 9, 4}, {5, 1, 5}};
    int n = jobs.size();

    vector<vector<int>> processes;

    int timer = 0;
    int i = 0;
    while(i < n or processes.size() != 0) {
        timer++;
        scheduler(jobs, processes, i, timer, n);
    }

    return 0;
}