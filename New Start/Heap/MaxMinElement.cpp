/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> MinHeap(int n, vector<vector<int>> &q){
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0; i<n; i++){
        if(q[i][0] == 0){
            minHeap.push(q[i][1]);
        }
        if(q[i][0] == 1){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> q(n, vector<int> (2));
    for(auto &i:q){
        for(auto &j:i){
            cin>>j;
        }
    }
    vector<int> ans = MinHeap(n,q);
    for(auto i:ans) cout<<i<<" ";
    return 0;
} 