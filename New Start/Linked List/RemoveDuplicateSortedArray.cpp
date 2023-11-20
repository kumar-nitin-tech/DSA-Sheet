/*
    Remove Duplicates in-place from Sorted Array

    Problem Statement:  Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative     
                        order of the elements should be kept the same.
                        If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.  

    Problem Link:   https://leetcode.com/problems/remove-duplicates-from-sorted-array/
                    https://www.codingninjas.com/studio/problems/1102307?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O(N + n* logn)
//SC: O(N)
int removeDuplicateFromSortArrayBrute(vector<int> &arr){
    set<int> st;
    for(auto i:arr){
        st.insert(i);
    }
    int i = 0;
    for(auto it:st){
        arr[i++] = it;
    }
    return st.size();
}

//Optimal Approach
//TC:
//SC:
int removeDuplicateFromSortArrayOptimal(vector<int> &arr){
    int i = 0;
    for(int j =1; j<arr.size(); j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}   

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<removeDuplicateFromSortArrayOptimal(arr)<<endl;
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}