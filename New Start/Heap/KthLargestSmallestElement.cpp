/*
    Kth largest/smallest element in an array

    Problem Statement:   Given an unsorted array, print Kth Largest and Smallest Element from an unsorted array.

    Problem Link:   https://leetcode.com/problems/kth-largest-element-in-an-array/description/

    Refer:  https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/

*/

#include<bits/stdc++.h>
using namespace std;

//Using sorting
int findKthLargestSort(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[arr.size()-k];
}

//using heap
int findKthLargestheap(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
    for(auto i:arr){
        maxHeap.push(i);
    }
    int f = k-1;
    while(f>0){
        maxHeap.pop();
        f--;
    }
    return maxHeap.top();
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<findKthLargestheap(arr,k);
    return 0;
}