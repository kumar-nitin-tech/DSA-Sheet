/*
    Problem Statement:  Given an array of integers. Find the Inversion Count in the array. 
                        Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
                        If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
                        Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
    Problem Link : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/
#include<bits/stdc++.h>
using namespace std;

//Brute Approach
//TC: O(n^2)
//SC: O(1)
int countInversionB(vector<int> &arr){
    int count = 0;
    for(int i=0;i<arr.size();i++){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}

int merge(vector<int> &arr, int start, int end, int mid){
    int left = start, right = mid+1;
    int count = 0;
    vector<int> temp;
    while(left <= mid && right <=end){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            count = mid - left + 1;
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=end){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=start; i<=end;i++){
        arr[i] = temp[i-start];
    }
    return count;
}

int mergeSort(vector<int> &arr, int start, int end){
    int count = 0;
    if(start>=end) return count;
    int mid = (start+end)/2;
    count += mergeSort(arr,start,mid);
    count += mergeSort(arr,mid+1,end);
    count += merge(arr,start,end,mid);
    return count;
}

//Optimized Approach 
int countInversionO(vector<int> &arr){
    return mergeSort(arr,0,arr.size()-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    cout<<countInversionO(arr);
    return 0;
}