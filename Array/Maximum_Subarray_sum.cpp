/*
    Problem Statement : Given an integer array nums, find the subarray with the largest sum, and return its sum.
    Problem Link :  https://leetcode.com/problems/maximum-subarray/
                    https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_8230694?challengeSlug=striver-sde-challenge
*/

#include<bits/stdc++.h>
using namespace std;

//My Solution
//TC: O(n2)
int maximumSumSubArray(vector<int> &nums){
    int maxSum = INT_MIN;
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            maxSum = max(maxSum,sum);
        }
    }

}

//Optimized Solution 
//Kadane Algorithm
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN,sum=0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        maxSum = max(sum,maxSum);
        if(sum<0){
            sum = 0;
        }
    }        
    if(maxSum<0)
        return 0;
    return maxSum; 
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &i:nums){
        cin>>i;
    }
    cout<<maxSubArray(nums);
    return 0;
}