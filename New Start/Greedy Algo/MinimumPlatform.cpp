/*
    Minimum number of platforms required for a railway

    Problem Statement:  We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of 
                        platforms needed at the railway station so that no train has to wait.  

    Problem Link:   https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_799400
                    https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

    Refer: https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/

*/

#include<bits/stdc++.h>
using namespace std;

//Naive Approach -> In this we just find the maximum no. of overlapping of train are there
//TC: O(N^2)
//SC: O(1)
int minimumPlatformBrute(vector<int> &arr, vector<int> &dep){
    int ans = 1, n = arr.size();
    for(int i=1; i<n-1; i++){
        int count = 1;
        for(int j=i+1; j<n-1; j++){
            if(arr[i]>=arr[j] && arr[i]<=dep[j] || arr[j]>=arr[i] && arr[j]<=dep[i]){
                count++;
            }
        }
        ans = max(ans,count);
    }
    return ans;
}

//Optimal Approach -> we sort the arr and dep array and find the platform consirdering the whole day
//TC: O(N)
//SC: O(1)
int minimumPlatformOptimal(vector<int> &arr, vector<int> &dep){
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int n = arr.size();
    int currPlatform = 1;
    int maxPlatform = 1;
    int i=1, j=0;
    while(i<n){
        if(arr[i] > dep[j]){
            currPlatform--;
            j++;
        }
        else{
            currPlatform++;
            i++;
        }
        maxPlatform = max(maxPlatform,currPlatform);
    }
    return maxPlatform;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n), dep(n);
    for(auto &i:arr)    cin>>i;
    for(auto &i:dep)    cin>>i;
    cout<<minimumPlatformOptimal(arr,dep);
    return 0;
}