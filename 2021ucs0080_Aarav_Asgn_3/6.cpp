// MULTI LEVEL FEEDBACK QUEUE SCHEDULING


#include <bits/stdc++.h>

using namespace std;
const int SHIFT_TIME = 20;
int curr_shift_timer = 0;


// Implementing the scheduling algorithm
void scheduler(vector<vector<int>> &jobs, vector<queue<vector<int>>> &jobQueue, vector<int> &timeQuanta, vector<int> &currTime, int &i, int &timer, int &prevQueue, int n) {
    while(i < n and timer == jobs[i][0]) {
        cout<<"timer: "<<timer<<"-----";
        cout<<"Job with ID: "<<jobs[i][2]<<" entered the ready stage"<<endl;
        jobQueue[0].push(jobs[i]);
        i++;
    }

    if(curr_shift_timer == SHIFT_TIME) {
        for(int i = 1;i < 3;i++) {
            while(!jobQueue[i].empty()) {
                jobQueue[0].push(jobQueue[i].front());
                jobQueue[i].pop();
            }
        }
        cout<<"timer: "<<timer<<"-----";
        cout<<"Shifted all the jobs in the queue with highest priority"<<endl;

        curr_shift_timer = 0;
        currTime[0] = 0;
        currTime[1] = 0;
        currTime[2] = 0;
        prevQueue = -1;
    }

    if(!jobQueue[0].empty() and (prevQueue == -1 or prevQueue == 0)) {
        prevQueue = 0;
        if(--jobQueue[0].front()[1] == 0) {
            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<jobQueue[0].front()[2]<<" was completed in Q1"<<endl;

            jobQueue[0].pop();
            prevQueue = -1;
        }
        else if(++currTime[0] == timeQuanta[0]) {
            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<jobQueue[0].front()[2]<<" was pushed to Q2"<<endl;

            vector<int> job = jobQueue[0].front();
            jobQueue[0].pop();
            jobQueue[1].push(job);
            currTime[0] = 0;
            prevQueue = -1;
        }
    }
    else if(!jobQueue[1].empty() and (prevQueue == -1 or prevQueue == 1)) {
        prevQueue = 1;
        if(--jobQueue[1].front()[1] == 0) {
            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<jobQueue[1].front()[2]<<" was completed in Q2"<<endl;

            jobQueue[1].pop();
            prevQueue = -1;
        }
        else if(++currTime[1] == timeQuanta[1]) {
            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<jobQueue[1].front()[2]<<" was pushed to Q3"<<endl;

            vector<int> job = jobQueue[1].front();
            jobQueue[1].pop();
            jobQueue[2].push(job);
            currTime[1] = 0;
            prevQueue = -1;
        }
    }
    else if(!jobQueue[2].empty() and (prevQueue == -1 or prevQueue == 2)) {
        prevQueue = 2;
        if(--jobQueue[2].front()[1] == 0) {
            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<jobQueue[2].front()[2]<<" was completed in Q3"<<endl;

            jobQueue[2].pop();
            prevQueue = -1;
        }
        else if(++currTime[2] == timeQuanta[2]) {
            cout<<"timer: "<<timer<<"-----";
            cout<<"Job with ID: "<<jobQueue[2].front()[2]<<" was push to the back of Q3"<<endl;

            vector<int> job = jobQueue[2].front();
            jobQueue[2].pop();
            jobQueue[2].push(job);
            currTime[2] = 0;
            prevQueue = -1;
        }
    }
}

int main() {

    /*
        CONVENTION: The array 'jobs' contains all the jobs to be executed. The 1st integer in each job 
        is the arrival time of the job. The 2nd integer is the time required to complete the job. The
        3rd integer represents the process ID of the job.
    */

    vector<vector<int>> jobs{{1, 10, 1}, {2, 20, 2}, {2, 4, 3}, {4, 90, 4}, {24, 1, 5}};
    
    vector<queue<vector<int>>> jobQueue(3);
    vector<int> timeQuanta{2, 5, 10};
    vector<int> currTime(3);
    int prevQueue = -1;

    int n = jobs.size();
    
    int timer = 0;
    int i = 0;
    while((i < n or !jobQueue[0].empty() or !jobQueue[1].empty() or !jobQueue[2].empty())) {
        timer++;
        curr_shift_timer++;
        scheduler(jobs, jobQueue, timeQuanta, currTime, i, timer, prevQueue, n);
    }

    return 0;
}