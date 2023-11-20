/*
    Trapping Rainwater

    Problem Statement:  Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.

    Problem Link:   https://leetcode.com/problems/trapping-rain-water/description/
                    https://www.codingninjas.com/studio/problems/trapping-rain-water_630519?leftPanelTabValue=PROBLEM

    Refer:  https://takeuforward.org/data-structure/trapping-rainwater/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O(N^2)
//SC: O(1)
int trappedWaterBrute(vector<int> &arr){
    int n = arr.size();
    int waterTrapped = 0;
    for(int i=0; i<n; i++){
        int leftMax= arr[i], rightMax = arr[i];
        for(int j=i; j>=0; j--) leftMax = max(leftMax,arr[j]);
        for(int j=i; j<n; j++)  rightMax = max(rightMax,arr[j]);
        waterTrapped += min(leftMax,rightMax) - arr[i];
    }
    return waterTrapped;
}

//Better Approach
//TC: O(3*N)
//SC: O(N)
//Using array as space
int trappedWaterBetter(vector<int> &arr){
    int n = arr.size();
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = arr[0];
    rightMax[n-1] = arr[n-1];
    for(int i=1; i<n; i++)  leftMax[i] = max(leftMax[i-1],arr[i]);
    for(int i=n-2; i>=0; i--)  rightMax[i] = max(rightMax[i+1],arr[i]);

    int waterTrapped = 0;
    for(int i=0; i<n; i++){
        waterTrapped += min(leftMax[i],rightMax[i]) - arr[i];
    }
    return waterTrapped;
}

//Optimal Approach
//TC: O(N)
//SC: O(1)
int trappedWaterOptimal(vector<int> &arr){
    int n = arr.size();
    int l=0, r=n-1;
    int lm = arr[0], rm = arr[n-1];
    int waterTrapped = 0;
    while(l<=r){
        if(arr[l] <= arr[r]){
            if(arr[l]>lm){
                lm = arr[l];
            }else{
                waterTrapped += lm - arr[l];
            }
            l++;
        }else{
            if(arr[r] > rm){
                rm = arr[r];
            }else{
                waterTrapped += rm - arr[r];
            }
            r--;
        }
    }
    return waterTrapped;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<trappedWaterOptimal(arr);
    return 0;
}