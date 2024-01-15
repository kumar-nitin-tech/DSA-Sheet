/*
    Job Sequencing Problem

    Problem Statement:  You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its 
                        deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.  

    Problem Link:   https://www.codingninjas.com/studio/problems/job-sequencing-problem_1169460
                    https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

    Refer:  https://takeuforward.org/data-structure/job-sequencing-problem/

*/

#include<bits/stdc++.h>
using namespace std;

struct Job{
    int jobId;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b){
    return a.profit>b.profit;
}
//Optimal Approach
//TC: 
//SC:
vector<int> jobSequencing(vector<Job> &jobs){
    //Idea is to sort the array of jobs in descending order of the profit to have maximumm profit 
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), cmp);
    int maxiDeadline = jobs[0].deadline;
    for(auto i:jobs){
        maxiDeadline = max(maxiDeadline,i.deadline);
    }
    vector<int> slot(maxiDeadline+1,-1);
    int countJobs = 0, jobsProfit = 0; 
    for(int i=0; i<n; i++){
        for(int j=jobs[i].deadline; j>0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                countJobs++;
                jobsProfit += jobs[i].profit;
                break;
            }
        }
    }
    return {countJobs,jobsProfit};
}

bool static cmp2(vector<int> a, vector<int> b){
    return a[2]>b[2];
}
vector<int> jobScheduling2(vector<vector<int>> &jobs){
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), cmp2);
    int maxiDeadline = jobs[0][1];
    for(auto i:jobs){
        maxiDeadline = max(maxiDeadline,i[1]);
    }
    vector<int> slot(maxiDeadline+1,-1);
    int countJobs = 0, jobsProfit = 0; 
    for(int i=0; i<n; i++){
        for(int j=jobs[i][1]; j>0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                countJobs++;
                jobsProfit += jobs[i][2];
                break;
            }
        }
    }
    return {countJobs,jobsProfit};
}

int main(){
    int n;
    cin>>n;
    vector<Job> jobs(n);
    for(auto &i:jobs){
        cin>>i.jobId>>i.deadline>>i.profit;
    }
    vector<int> ans = jobSequencing(jobs);
    for(auto i:ans)    cout<<i<<" ";
    return 0;
}