// FIRST COME FIRST SERVE SCHEDULING


#include <bits/stdc++.h>

using namespace std;

void scheduler(queue<vector<int>> &q, vector<vector<int>> &jobs, int &i, int timer, int n) {
    while(i < n and jobs[i][0] == timer) {
        vector<int> job = jobs[i];

        job.push_back(timer);
        q.push(job); i++;
        cout<<"timer: "<<timer<<"-----"; 
        cout<<"Job with ID: "<<job[2]<<" has arrived in the ready stage"<<endl;
    }

    if(!q.empty()) {
        int currJobFirstStarted = q.front()[3];
        int currJobProcessTime = q.front()[1];
        int currJobID = q.front()[2];

        if(timer - currJobFirstStarted == currJobProcessTime) {
            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<currJobID<<" is completed"<<endl;
            q.pop();
        }
    }
}


int main() {

    /*
        CONVENTION: The array 'jobs' contains all the jobs to be executed. The 1st integer in each job 
        is the arrival time of the job. The 2nd integer is the time required to complete the job. The
        3rd integer represents the process ID of the job.
    */


    vector<vector<int>> jobs{{1, 3, 1}, {2, 3, 2}, {2, 4, 3}, {3, 5, 4}, {6, 7, 5}};
    int n = jobs.size();

    queue<vector<int>> q;
    // Implementing the scheduling algorithm
    
    int timer = 0;
    int i = 0;
    while(i < n or !q.empty()) {
        timer++;
        scheduler(q, jobs, i, timer, n);
    }

    return 0;
}