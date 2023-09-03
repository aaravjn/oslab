// SHORTEST JOB FIRST SCHEDULING


#include <bits/stdc++.h>

using namespace std;

// Implementing the scheduling algorithm
void scheduler(vector<vector<int>> &jobs, int &i, int &timer, int n) {
    timer += jobs[i][1];
    cout<<"timer: "<<timer<<"-----";
    cout<<"Job with ID: "<<jobs[i][2]<<" has completed"<<endl;
    
    i++;
}


int main() {

    /*
        CONVENTION: The array 'jobs' contains all the jobs to be executed. The 1st integer in each job 
        is the arrival time of the job. The 2nd integer is the time required to complete the job. The
        3rd integer represents the process ID of the job.
    */

    vector<vector<int>> jobs{{1, 10, 1}, {1, 2, 2}, {1, 4, 3}, {1, 9, 4}, {1, 1, 5}};
    int n = jobs.size();
    for(int i = 0;i < n;i++) {
        cout<<"timer: 1"<<"-----";
        cout<<"Job with ID: "<<jobs[i][2]<<" has arrived in the ready stage"<<endl;
    }
    
    
    sort(jobs.begin(), jobs.end());

    int timer = 0;
    int i = 0;
    while(i < n) {
        scheduler(jobs, i, timer, n);
    }

    return 0;
}