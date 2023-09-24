/*
    Length of the longest subarray with zero Sum

    Problem Statement:  Given an array having both positive and negative integers. The task is to compute the length of the largest 
                        subarray with sum 0.

    Problem Link:   https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
                    https://www.codingninjas.com/studio/problems/920321?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O(N^2)
//SC: O(1)
int longestSubArrayWithSumZeroBrute(vector<int> &arr){
    int longestSubaaray = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == 0){
                longestSubaaray = max(longestSubaaray,j-i+1);
            }
        }
    }
    return longestSubaaray;
}

//Optimal Approach
//TC: O(N log N)
//SC: O(N)
int longestSubArrayWithSumZeroOptimal(vector<int> &arr){
    //Mantaining a prefix sum
    int prefixSum = 0;
    //To find the max len of the subarray
    int maxi = 0;
    //Hashmap to store the prefix sum and index 
    unordered_map<int,int> mp;
    //Iterating over the arr
    for(int i=0; i<arr.size(); i++){
        //adding array element in the prefix sum ;
        prefixSum += arr[i];
        if(prefixSum == 0){
            //If the prefix sum is 0 that means that till now the subarray sum is 0;
            maxi = i+1;
        }
        else{
            //We find the prefix sum is already present in the hashmap or not
            if(mp.find(prefixSum) != mp.end()){
                maxi = max(maxi,i-mp[prefixSum]);
            }
            else{
                mp[prefixSum] = i;
            }
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<longestSubArrayWithSumZeroOptimal(arr);
    return 0;
}