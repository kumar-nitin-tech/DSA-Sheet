/*
    Count Inversion

    Problem Statement:  Given an array of integers. Find the Inversion Count in the array.Inversion Count: For an array, inversion count 
                        indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

    Problem Link:   https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
                    https://www.codingninjas.com/studio/problems/count-inversions_615?leftPanelTab=0

    Refer:  Notes
            https://takeuforward.org/data-structure/count-inversions-in-an-array/
            https://www.youtube.com/watch?v=AseUmwVNaoY

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(n2)
//SC:   O(1)
int countInversionB(vector<int> &arr){
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}

//Using Merge Sort
//TC: O(N logN)
//SC: O(N)

int merge(int left, int mid, int right, vector<int> &arr){
    int start = left, end = mid+1;
    int count = 0;
    vector<int> temp;

    while(start<=mid && end <= right){
        if(arr[start] > arr[end]){
            temp.push_back(arr[end]);
            count += mid - start + 1;
            end++;
        }else{
            temp.push_back(arr[start]);
            start++;
        }
    }
    while(start<=mid){
        temp.push_back(arr[start]);
        start++;
    }
    while(end <= right){
        temp.push_back(arr[end]);
        end++;
    }
    for(int i=left; i<=right; i++){
        arr[i] = temp[i-left];
    }
    return count;
}

int mergeSort(int left, int right, vector<int> &arr){
    int count = 0;
    if(left>=right) return count;

    int mid = (left+right)/2;
    count += mergeSort(left,mid,arr);
    count += mergeSort(mid+1,right,arr);
    count += merge(left,mid,right,arr);
    return count;
}

int countInversion(vector<int> &arr){
    return mergeSort(0,arr.size()-1,arr);
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<countInversionB(arr);
    return 0;
}