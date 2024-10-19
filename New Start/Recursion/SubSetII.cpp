/*
    Subset - II | Print all the Unique Subsets
    Problem Statement:  Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any 
                        order.

    Problem Link:   https://leetcode.com/problems/subsets-ii/description/
                    https://www.naukri.com/code360/problems/unique-subsets_3625236?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:
//SC:
void subsetHelper(vector<int> &arr, int n, int ind, set<vector<int>> &ans, vector<int> temp){
    if(ind == n){
        sort(temp.begin(), temp.end());
        ans.insert(temp);
        return;
    }
    temp.push_back(arr[ind]);
    //take
    subsetHelper(arr,n,ind+1,ans,temp);

    temp.pop_back();
    //not take
    subsetHelper(arr,n,ind+1,ans,temp);
}
vector<vector<int>> subSetBrute(vector<int> &arr){
    //In this we generate all subset and push them in set to get unique subset
    set<vector<int>> ans;
    vector<int> temp;
    int n = arr.size(); 
    subsetHelper(arr,n,0,ans,temp);
    vector<vector<int>> res;
    for(auto i:ans){
        res.push_back(i);
    }
    return res;
}


//Optimal approach
//TC: O(n log n) + O(2^N * N)
//SC: O(N)
void subsetRecursionHelper(vector<int> temp, vector<vector<int>> &ans, int ind, int n, vector<int> &arr){
    ans.push_back(temp);
    for(int i=ind; i<n; i++){
        if(ind != i && arr[i] == arr[i-1])  continue;
        temp.push_back(arr[i]);
        subsetRecursionHelper(temp,ans,ind+1,n,arr);
        temp.pop_back();
    }
}
vector<vector<int>> subsetOptimal(vector<int> &arr){
    vector<int> temp;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    subsetRecursionHelper(temp,ans,0,n,arr);
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<vector<int>> ans = subsetOptimal(arr);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}