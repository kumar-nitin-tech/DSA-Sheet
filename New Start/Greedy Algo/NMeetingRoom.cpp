/*
    N meeting room

    Problem Statement:  There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the 
                        ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.  

    Problem Link:   https://www.codingninjas.com/studio/problems/maximum-meetings_1062658
                    https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

    Refer:  https://takeuforward.org/data-structure/n-meetings-in-one-room/

*/

#include<bits/stdc++.h>
using namespace std;

//Optimal Solution: Sorting the end array to maximise the no. of meeting in a room
//TC: O(N log N)
//SC: O(N)

//we will create struct or object to store the three things index, start, end
struct meeting{
    int idx;
    int start;
    int end;
};

bool static cmp(meeting m1, meeting m2){
    if(m1.end<m2.end)   return true;
    else if(m1.end>m2.end)  return false;
    else if(m1.idx<m2.idx)  return true;
    return false;
}

//To print the order we are keeping the index
void printNmeetingOrder(vector<int> &st, vector<int> &ed){
    int n = st.size();
    vector<meeting> meet(n);
    for(int i=0; i<n; i++){
        meet[i].idx = i+1;
        meet[i].start = st[i];
        meet[i].end = ed[i];
    }
    sort(meet.begin(), meet.end(), cmp);

    vector<int> ans;
    int limit = meet[0].end;
    ans.push_back(meet[0].idx);
    for(int i=1; i<n; i++){
        if(meet[i].start > limit){
            limit = meet[i].end;
            ans.push_back(meet[i].idx);
        }
    }

    cout<<ans.size()<<endl;

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> st(n),ed(n);
    for(auto &i:st) cin>>i;
    for(auto &i:ed) cin>>i;
    printNmeetingOrder(st,ed);
    return 0;
}