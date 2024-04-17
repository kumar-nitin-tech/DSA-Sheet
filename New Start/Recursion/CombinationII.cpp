/*
    Combination Sum II - Find all unique combinations
    Problem Statement:  Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate 
                        numbers sum to target. Each number in candidates may only be used once in the combination.

    Problem Link:   https://leetcode.com/problems/combination-sum-ii/description/
                    https://www.naukri.com/code360/problems/1112622?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/

*/

#include<bits/stdc++.h>
using namespace std;

//Recursive approach ( My approach)
//TC: O(2^N) + O(2^N log(2^N)) 
//SC: O(N)
void combinationSumHelper(set<vector<int>> &ans, vector<int> &arr, vector<int> &temp, int ind, int target){
    if(ind == arr.size()){
        if(target == 0){
            sort(temp.begin(), temp.end());
            ans.insert(temp);
        }
        return;
    }

    temp.push_back(arr[ind]);
    combinationSumHelper(ans,arr,temp,ind+1,target-arr[ind]);
    temp.pop_back();
    combinationSumHelper(ans,arr,temp,ind+1,target);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target){
    set<vector<int>> ans;
    vector<int> temp;
    combinationSumHelper(ans,arr,temp,0,target);
    vector<vector<int>> res;
    for(auto i:ans){
        res.push_back(i);
    }
    return res;
}


//Optimal Approach : We combine the no duplicate subset and combination sum method to get unique subset sum
//TC:   O(2^N) + O(N log N)
//SC:   O(N)
void combinationSumOptimalHelper(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int ind, int target){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    for(int i=ind; i<arr.size(); i++){
        if(i>ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        temp.push_back(arr[i]);
        combinationSumOptimalHelper(arr,ans,temp,i+1,target-arr[i]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSumOptimal(vector<int> &arr, int target){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    combinationSumOptimalHelper(arr,ans,temp,0,target);
    return ans;
}


int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<vector<int>> ans = combinationSumOptimal(arr,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}