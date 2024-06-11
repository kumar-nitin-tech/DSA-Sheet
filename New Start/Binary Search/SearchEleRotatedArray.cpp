/*
    Search Element in a Rotated Sorted Array

    Problem Statement:  Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot 
                        point unknown to you. Find the index at which k is present and if k is not present return -1.

    Problem Link:   https://leetcode.com/problems/search-in-rotated-sorted-array/description/

    Refer:  https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(N)
//SC:   O(1)
int searchBrute(vector<int> &arr, int target){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

//Optimal Approach
//TC:   O(log N)
//SC:   O(1)
int searchOptimal(vector<int> &arr, int target){
    //we use binary search to eliminate the sorted half of the array
    int low = 0, high = arr.size()-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }
        //check which half is sorted
        else if(arr[low] <= arr[mid]){
            //left half is sorted
            //check if the target is present in the left half
            if(arr[low] <= target && arr[mid] >= target){
                //is in the half so eliminate right half
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            //check if the target is present in the right half
            if(arr[mid] <= target && arr[high] >= target){
                //is in the half so eliminate right half
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<searchOptimal(arr,target);
    return 0;
}