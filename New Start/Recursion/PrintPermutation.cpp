/*
    Print All Permutations of a String/Array

    Problem Statement:  Given an array arr of distinct integers, print all permutations of String/Array.

    Problem Link:   https://leetcode.com/problems/permutations/description/
                    https://www.naukri.com/code360/problems/print-permutations-string_758958?topList=striver-sde-sheet-problems&problemListRedirection=true&search=permutat

    Refer:  https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/

*/

#include<bits/stdc++.h>
using namespace std;

//Recursive Approach
//TC: O(N!*N)
//SC: O(N) -> freq array

void recursiveHelper(vector<int> &arr, vector<vector<int>> &ans, vector<int> &freq, vector<int> &temp){
    if(temp.size() == arr.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<arr.size(); i++){
        if(!freq[i]){
            freq[i] = 1;
            temp.push_back(arr[i]);
            recursiveHelper(arr,ans,freq,temp);
            freq[i] = 0;
            temp.pop_back();
        }
    }
}

vector<vector<int>> PrintPermutationRecursive(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> freq(arr.size(),0), temp;
    recursiveHelper(arr,ans,freq,temp);
    return ans;
}

//Backtracking Approach
//TC:   O(N!*N)
//SC: O(1)

void recursiveHelper(vector<int> &arr, vector<vector<int>> &ans, int ind){
    if(ind == arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=ind; i<arr.size(); i++){
        swap(arr[i],arr[ind]);
        recursiveHelper(arr,ans,ind+1);
        swap(arr[i],arr[ind]);
    }
}

vector<vector<int>> PrintPermutationBackTrack(vector<int> &arr){
    vector<vector<int>> ans;
    recursiveHelper(arr,ans,0);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<vector<int>> ans = PrintPermutationBackTrack(arr);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}