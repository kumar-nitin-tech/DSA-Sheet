/*
Given an array containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.
*/

#include<bits/stdc++.h>
using namespace std;

//Brute Appraoch
//Gives TLE
//TC: O(n^2)
int longSubarrWthSumDivByK(vector<int> &arr, int n, int k){
    int maxAns = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            int start = i;
            sum += arr[j];
            if(sum%k == 0){
                int end = j;
                int length = end - start;
                maxAns = max(maxAns, length);
            }
        }
    }
    return maxAns+1;
}

//Optimized Approach
//Using HashMap 
int longSubarrWthSumDivByKOp(vector<int> &arr, int n, int k){
    // Hash map which store remainder and index
    unordered_map<int,int> map;   
    map.insert({0,-1});
    int maxLen = INT_MIN, sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        int rem = ((sum % k)+k)%k;
        if(map.find(rem) != map.end()){
            int len = i - map[rem];
            map.insert({rem, i});
            maxLen = max(maxLen, len);
        }
        else{
            map.insert({rem,i});
        }
    }
    return maxLen;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    cout<<longSubarrWthSumDivByKOp(arr,n,k);
    return 0;
}