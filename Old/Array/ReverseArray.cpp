/*
    1. Reverse a Array
*/

#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>&arr){
    int start = 0, end = arr.size()-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void recursiveReverse(vector<int>&arr, int start, int end){
    if(start>=end){
        return;
    }
    swap(arr[start],arr[end]);
    recursiveReverse(arr,start+1,end-1);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    recursiveReverse(arr,0,n-1);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}