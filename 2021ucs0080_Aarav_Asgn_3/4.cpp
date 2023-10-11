// ROUND ROBIN SCHEDULING


#include <bits/stdc++.h>

using namespace std;
const int TIME_QUANTUM = 3;
int rr_timer = 0;

// Implementing the Round-Robin scheduling algorithm
void scheduler(queue<vector<int>> &q, vector<vector<int>> &jobs, int &i, int timer, int n) {
    
    while(i < n and timer == jobs[i][0]) {
        q.push(jobs[i]);
        cout<<"timer: "<<timer<<"-----";
        cout<<"Job with ID: "<<jobs[i][2]<<" has entered the ready stage"<<endl;
        i++;
    }
    
    if(!q.empty()) {
        vector<int> job = q.front();

        if(--job[1] == 0) {
            q.pop();
            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<job[2]<<" has completed"<<endl;
        }
        else if(++rr_timer == TIME_QUANTUM) {
            q.pop();
            rr_timer = 0;
            q.push(job);

            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<job[2]<<" is pushed to the back of the queue"<<endl;
        }
        else {
            q.front()[1]--;
        }
    }
}


int main() {

    /*
        CONVENTION: The array 'jobs' contains all the jobs to be executed. The 1st integer in each job 
        is the arrival time of the job. The 2nd integer is the time required to complete the job. The
        3rd integer represents the process ID of the job.
    */
    // {{1, 10, 1}, {2, 2, 2}, {2, 4, 3}, {4, 9, 4}, {5, 1, 5}}
    
    cout<<"Input the number of Jobs: ";
    int n; cin>>n;
    cout<<endl;

    cout<<"Input the jobs\n";
    vector<vector<int>> jobs;
    for(int i = 0;i < n;i++) {
        int arrival_time, process_time, process_id;
        cin>>arrival_time>>process_time>>process_id;
        jobs.push_back({arrival_time, process_time, process_id});
    }

    queue<vector<int>> q;

    int timer = 0;
    int i = 0;
    while(i < n or !q.empty()) {
        timer++;
        scheduler(q, jobs, i, timer, n);
    }

    return 0;
}