/*
    Find the Duplicate Number

    Problem Statement:  Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. 
                        There is only one repeated number in nums, return this repeated number. You must solve the problem without modifying the array nums and uses only constant extra space.

    Problem Link:   https://leetcode.com/problems/find-the-duplicate-number/
                    https://www.codingninjas.com/studio/problems/1112602?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
            https://www.youtube.com/watch?v=32Ll35mhWg0

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(N logN) + O(N)
//SC:   O(1)
int findDuplicateB(vector<int> &arr){
    //sort the array
    sort(arr.begin(), arr.end());

    //check prev;
    for(int i=1; i<arr.size(); i++){
        if(arr[i] == arr[i-1]){
            return arr[i];
        }
    }
    return -1;
}

//Frequency Array
//Tc: O(n)
//Sc: O(n) -> Need to be optimised 
int findDuplicateBe(vector<int> &arr){
    int n = arr.size();
    vector<int> freq(n+1,-1);

    for(int i=0; i<arr.size(); i++){
        if(freq[arr[i]] != -1){
            return arr[i];
        }else{
            freq[arr[i]] = 0;
        }
    }
    return -1;
}

//Optimal Approach (Flyod Algorithm)-> Slow and fast pointer
//TC: O(N)
//SC: (1)
int findDuplicate(vector<int> &arr){
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    fast = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<findDuplicate(arr);
    return 0;
}