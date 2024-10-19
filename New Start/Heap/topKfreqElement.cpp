/*
    Top K Frequent Elements
    Problem Statement:  Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Problem Link:   https://leetcode.com/problems/top-k-frequent-elements/description/

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Approach
//TC:
//SC:
vector<int> topKFrequentBrute(vector<int> &arr, int k){
    unordered_map<int, int> map;
    for(auto i:arr){
        map[i]++;
    } 
    vector<pair<int,int>> temp;
    vector<int> ans;
    for(auto i:map){
        temp.push_back({i.second,i.first});
    }
    sort(temp.begin(),temp.end());
    for(int i=0; i<k; i++){
        ans.push_back(temp[temp.size()-i-1].second);
    }
    return ans;
}

//Optimal Approach
//TC:
//SC:
vector<int> topKFrequentOptimal(vector<int> &arr, int k){
    unordered_map<int, int> map;
    for(auto i:arr){
        map[i]++;
    } 
    priority_queue<pair<int,int>> maxHeap;
    for(auto i:map){
        maxHeap.push({i.second,i.first});
    }
    vector<int> ans;
    while(k--){
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;
    vector<int> ans = topKFrequentBrute(arr,k);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}