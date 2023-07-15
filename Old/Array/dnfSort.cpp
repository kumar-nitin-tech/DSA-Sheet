/*
    problem statement : Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

    problem link : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*/
#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr){
    int left = 0, end = arr.size()-1, mid = 0;
    while(mid<=end){
        if(arr[mid] == 0){
            swap(arr[left],arr[mid]);
            left++; mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid] , arr[end]);
            end--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    sort012(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}