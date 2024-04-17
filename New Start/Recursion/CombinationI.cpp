/*
    Combination Sum - 1
    Problem Statement:  Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You 
                        may return the combinations in any order. The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different. It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input. 

    Problem Link:   https://leetcode.com/problems/combination-sum/description/
                    https://www.naukri.com/code360/problems/759331?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/combination-sum-1/

*/

#include<bits/stdc++.h>
using namespace std;

//Recursion
//TC: O(2^T * N)
//SC: O(N)
//helper function
void combinationSumHelper(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int ind, int n, int target){
    if(ind == n){
        if(target == 0){
            ans.push_back(temp);
        }
        return;
    }
    if(arr[ind] <= target){
        //pick the element 
        temp.push_back(arr[ind]);
        combinationSumHelper(arr,ans,temp,ind,n,target-arr[ind]);
        temp.pop_back();
    }
    combinationSumHelper(arr,ans,temp,ind+1,n,target);
}
vector<vector<int>> combinationSum(vector<int> &arr, int &target){
    vector<vector<int>> ans;
    vector<int> temp;
    int n = arr.size();
    combinationSumHelper(arr,ans,temp,0,n,target);
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<vector<int>> ans = combinationSum(arr,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}