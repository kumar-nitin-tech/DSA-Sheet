/*
    Maximum Sum Combinations

    Problem Statement:  Given two equally sized 1-D arrays A, B containing N integers each. A sum combination is made by adding one element from array A and another element of 
                        array B. Return the maximum C valid sum combinations from all the possible sum combinations.

    Problem Link:   https://www.interviewbit.com/problems/maximum-sum-combinations/

    Refer:  Notes / Youtube

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:
//SC:
vector<int> maxSumCombinationBrute(vector<int> &a, vector<int> &b, int c){
    //find all combination
    vector<int> combination;
    vector<int> ans;
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            combination.push_back(a[i]+b[j]);
        }
    }
    sort(combination.begin(), combination.end());
    for(int i=combination.size()-1; i>=0; i--){
        if(c>0){
            ans.push_back(combination[i]);
            c--;
        }
    }
    return ans;
}

vector<int> maxSumCombinationOptimal(vector<int> &a, vector<int> &b, int c){
    //idea is to push combination sum in max heap 
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int> ());

    priority_queue<pair<int, pair<int,int>>> maxHeap;
    //to avoid duplicate pair index
    set<pair<int, int>> index;
    //we push largest sum in maxHeap which is a[n-1] and b[n-1]

    maxHeap.push({a[0]+b[0], {0,0}});

    vector<int> ans;
    for(int i=0; i<c; i++){
        pair<int, pair<int,int>> curr = maxHeap.top();
        maxHeap.pop();
        ans.push_back(curr.first);
        if(curr.second.first+1 < a.size() && index.find({curr.second.first+1, curr.second.second}) == index.end()){
            maxHeap.push({a[curr.second.first+1]+b[curr.second.second], {curr.second.first+1, curr.second.second}});
            index.insert({curr.second.first+1, curr.second.second});
        }
        if(curr.second.second+1 < b.size() && index.find({curr.second.first, curr.second.second+1}) == index.end()){
            maxHeap.push({a[curr.second.first]+b[curr.second.second+1], {curr.second.first,curr.second.second+1}});
            index.insert({curr.second.first, curr.second.second+1});
        }
    }
    return ans;
}

int main(){
    int n,c;
    cin>>n>>c;
    vector<int> a(n),b(n);
    for(auto &i:a)  cin>>i;
    for(auto &i:b)  cin>>i;
    vector<int> ans = maxSumCombinationOptimal(a,b,c);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}