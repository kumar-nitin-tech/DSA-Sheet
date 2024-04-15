/*
    Subset Sum : Sum of all Subsets   
    Problem Statement:  Given an array print all the sum of the subset generated from it, in the increasing order.

    Problem Link:   https://www.geeksforgeeks.org/problems/subset-sums2234/1
                    https://www.naukri.com/code360/problems/subset-sum_3843086?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/

*/

#include<bits/stdc++.h>
using namespace std;

//Generate Subset (Power Set technique)
//Tc: O(N* 2^N)
//SC: O(N);
vector<int> subSetSum(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    for(int i=0; i<(1<<n); i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            //check the set bit pos in the j index
            if(i & (1<<j)){
                sum += arr[j];
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

//Recursive method
//Tc: O(2^N) + O(2^N log 2^N)
//SC: O(N);
void subsetSumHelper(int idx, vector<int> &ans, vector<int> &arr, int sum, int n){
    if(idx == n){
        ans.push_back(sum);
        return;
    }

    //take
    subsetSumHelper(idx+1, ans, arr, sum + arr[idx], n);
    //not taken
    subsetSumHelper(idx+1, ans, arr, sum, n);
}

vector<int> subsetSumRecursion(vector<int> &arr){
    vector<int> ans;
    int n = arr.size();
    subsetSumHelper(0,ans,arr,0,n);
    sort(ans.begin(), ans.end());
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<int> ans = subsetSumRecursion(arr);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}