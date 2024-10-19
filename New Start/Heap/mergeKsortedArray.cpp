/*
    Merge k Sorted Arrays

    Problem Statement:   Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array 
                        ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).


    Problem Link:   https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

    Refer:  

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force
vector<int> megreKsortedArrayBrute(vector<vector<int>> &arr, int n){
    vector<int> ans;
    for(auto i:arr){
        for(auto j:i){
            ans.push_back(j);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

//Optimal Approach
vector<int> mergeKsortedOptimal(vector<vector<int>> &arr, int n){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(auto i:arr){
        for(auto j:i){
            minHeap.push(j);
        }
    }

    while(!minHeap.empty()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int> (n));

    for(auto &i:arr){
        for(auto &j:i){
            cin>>j;
        }
    }

    vector<int> ans = mergeKsortedOptimal(arr,n);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}