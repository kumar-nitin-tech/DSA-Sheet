/*
    Two Sum

    Problem Statement:  Given an array of integers arr[] and an integer target.
                        1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
                        2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
                        Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.  

    Problem Link:   https://leetcode.com/problems/two-sum/
                    https://www.codingninjas.com/studio/problems/reading_6845742

    Refer:  https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force 
//TC:   O(n^2)
//SC:   O(1)
//1st Variant
bool TwoSum1B(vector<int> &arr, int target){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                return true;
            }
        }
    }
    return false;
}
//2nd Variant
vector<int> TwoSum2B(vector<int> &arr, int target){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == target){
                return {i,j};
            }
        }
    }
    return {};
}

//Better Approach
//TC:   O(N)
//SC:   O(N)
bool TwoSum1Better(vector<int> &arr, int target){
 //In this map we store the element along with its index
   //In this map we store the element along with its index
    unordered_map<int,int> mp;
    //We store arr value as key and map it with ind;

    for(int i=0; i<arr.size(); i++){
        int aj = target - arr[i];
        if(mp.find(aj) != mp.end()){
            return true;
        }
        mp[arr[i]] = i;
    }
    return false;
}

vector<int> TwoSum2Better(vector<int> &arr, int target){
    //In this map we store the element along with its index
    unordered_map<int,int> mp;
    //We store arr value as key and map it with ind;

    for(int i=0; i<arr.size(); i++){
        int aj = target - arr[i];
        if(mp.find(aj) != mp.end()){
            return {mp[aj],i};
        }
        mp[arr[i]] = i;
    }
    return {-1,-1};
}

//Optimal Approach
//TC:   O(N)
//SC:   O(1)
bool TwoSum1O(vector<int> &arr, int target){
    int low = 0, high = arr.size()-1;
    sort(arr.begin(),arr.end());
    while(low<high){
        if(arr[low] + arr[high] == target)  return true;
        else if(arr[low]+arr[high] > target)    high--;
        else low++;
    }
    return false;
}


int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<int> ans = TwoSum2Better(arr,target);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}