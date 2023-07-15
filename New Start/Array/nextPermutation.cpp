/*
    Next Permutation

    Problem Statement:  Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next 
                        greater permutation of numbers.

    Problem Link:   https://leetcode.com/problems/next-permutation/
                    https://www.codingninjas.com/studio/problems/next-greater-permutation_6929564

    Refer:  Notes
            https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr){
    int pivot = -1, n=arr.size();
    for(int i = n-2;i>=0;i--){
        if(arr[i] < arr[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        reverse(arr.begin(),arr.end());
        return arr;
    }

    for(int i = n-1;i>=0;i--){
        if(arr[i] > arr[pivot]){
            swap(arr[i],arr[pivot]);
            break;
        }
    }
    reverse(arr.begin()+pivot+1,arr.end());
    return arr;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    arr = nextPermutation(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}