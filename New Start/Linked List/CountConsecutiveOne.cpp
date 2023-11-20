/*
    Max Consecutive Ones

    Problem Statement:  Given a binary array nums, return the maximum number of consecutive 1's in the array.  

    Problem Link:   https://leetcode.com/problems/max-consecutive-ones/

    Refer:  https://takeuforward.org/data-structure/count-maximum-consecutive-ones-in-the-array/

*/

#include<bits/stdc++.h>
using namespace std;

//TC: O(N)
//SC:   O(1)
int countConsecutiveOneBrute(vector<int> &arr){
    int n = arr.size();
    int cnt = 0, maxCnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            cnt++;
        }
        else{ 
            cnt = 0;
        }
        maxCnt = max(cnt,maxCnt);
    }
    return maxCnt;
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<countConsecutiveOneBrute(arr);
    return 0;
}