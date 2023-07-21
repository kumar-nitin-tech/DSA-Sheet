/*
    Sort an array of 0s, 1s and 2s

    Problem Statement:  Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single 
                        pass-O(N) and constant space)

    Problem Link:   https://leetcode.com/problems/sort-colors/
                    https://www.codingninjas.com/studio/problems/631055?topList=striver-sde-sheet-problems

    Refer:  Notes
            https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
            https://www.youtube.com/watch?v=tp8JIuCXBaU&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F
*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O(N logN)
void sortArrayB(vector<int> &arr){
    sort(arr.begin(), arr.end());
}

//Optimal Approach
//TC: O(n)
//We use DNF Sort Algorithm
void sortArray(vector<int> &arr, int n){
    //unsorted array is between mid and high
    int low = 0, mid = 0, high = n-1;

    while(mid <= high){
        //There are 3 case 
        //arr[mid] == 0
        if(arr[mid] == 0){
            //We mid++ and low++
            swap(arr[mid++], arr[low++]);
        }
        else if(arr[mid] == 1)  mid++;

        else{
            swap(arr[mid], arr[high--]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;

    sortArray(arr,n);
    for(auto i:arr) cout<<i<<" ";
    return 0;
}