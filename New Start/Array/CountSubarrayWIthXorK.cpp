/*
    Count the number of subarrays with given xor K

    Problem Statement:  Given an array of integers arr and an integer k. Find the total number of subarrays having bitwise XOR of all elements equal to k.

    Problem Link:   https://www.interviewbit.com/problems/subarray-with-given-xor/
                    https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258

    Refer:  https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O(N^2)
//SC: O(1)
int countSubArrayWithXorKBrute(vector<int> &arr, int k){
    int count = 0;
    for(int i=0; i<arr.size(); i++){
        int subarrayXor = 0;
        for(int j=i; j<arr.size(); j++){
            subarrayXor ^= arr[j];
            if(subarrayXor == k)    count++;
        }
    }
    return count;
}

//Optimal Approach
//TC: O(N log N) -> if we take map but we take unordered map at best it operation give O(1) but at worst it give O(N)
//SC: O(N)
int countSubArrayWithXorKOptimal(vector<int> &arr, int k){
    map<int,int> mp;
    int count = 0;
    int xr = 0;
    mp[xr]++;
    for(int i=0; i<arr.size(); i++){
        xr ^= arr[i];
        //we are find the x = xr^k
        int x = xr^k;
        count += mp[x];
        mp[xr]++;
    }
    return count;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<countSubArrayWithXorKOptimal(arr,k);
    return 0;
}