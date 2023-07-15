/*
    Kadane’s Algorithm : Maximum Subarray Sum in an Array

    Problem Statement:  Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest 
                        sum and returns its sum and prints the subarray.

    Problem Link:   https://leetcode.com/problems/maximum-subarray/
                    https://www.codingninjas.com/studio/problems/630526?topList=striver-sde-sheet-problems

    Refer:  Note
            https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
            https://www.youtube.com/watch?t=1209&v=AHZpyENo7k4&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F&feature=emb_imp_woyt
*/

#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n)
int maxSubarraySum(vector<int> &arr){
    int n = arr.size(), sum = 0, maxSum = INT_MIN;
    vector<int> temp;
    for(int i=0;i<n;i++){
        sum += arr[i];
        temp.push_back(arr[i]);
        maxSum = max(maxSum,sum);
        if(sum< 0){
            sum = 0;
            temp.clear();
        }
    }
    for(auto i:temp){
        cout<<i<<" ";
    }
    cout<<endl;
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(auto &i:arr)    cin>>i;

    cout<<maxSubarraySum(arr);
    return 0;
}