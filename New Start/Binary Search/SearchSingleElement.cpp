/*
    Search Single Element in a sorted array

    Problem Statement:  Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

    Problem Link:   https://leetcode.com/problems/single-element-in-a-sorted-array/description/

    Refer:  https://takeuforward.org/data-structure/search-single-element-in-a-sorted-array/

*/


#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(N)
//SC:   O(1)
int singleNonDuplicateBrute(vector<int> &arr){
    //Iterate over arr and check prev and next element is not equal then return it
    for(int i=1; i<arr.size(); i++){
        if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}

//Better Approach
//TC: O(N)
//SC: O(1)
int singleNonDuplicateBetter(vector<int> &arr){
    //We can use XOR operator to find the single element
    int ans = 0;
    for(int i=0; i<arr.size(); i++){
        ans ^=arr[i];
    }
    return ans;
}

//Optimal Approach
//TC:   O(log N)
//SC:   O(1)
int singleNonDuplicateOptimal(vector<int> &arr){
    int n = arr.size();
    //Edges cases
    if(arr.size() == 1){
        return arr[0];
    }
    if(arr[0] != arr[1])    return arr[0];
    if(arr[n-1]  != arr[n-2])   return arr[n-1];

    int low = 1, high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
            return arr[mid];
        }
        else if((mid%2 == 1 && arr[mid] == arr[mid-1]) || (mid%2 == 0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}


int main(){
    int n;
    cin>>n;  
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;  
    cout<<singleNonDuplicateOptimal(arr);
    return 0;
}