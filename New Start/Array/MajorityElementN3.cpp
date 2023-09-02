/*
    Find the elements that appears more than N/3 times in the array

    Problem Statement:  Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element 
                        exists, return an empty vector.

    Problem Link:   https://www.codingninjas.com/studio/problems/majority-element_6915220
                    https://leetcode.com/problems/majority-element-ii/

    Refer:  https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
            https://www.youtube.com/watch?v=vwZj1K0e9U8


*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(n^2)
//SC:   O(1)
vector<int> majorityElementB(vector<int> &arr){
    vector<int> ans;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int count = 0;
        if(ans.empty() || ans[0] != arr[i]){
            for(int j=0; j<n; j++){
                if(arr[i] == arr[j])    count++;
            }
            if(count > n/3) ans.push_back(arr[i]);
        }
        if(ans.size() == 2) break;
    }
    return ans;
}

//Better Approach
//TC:   O(n)
//SC:   O(n)
vector<int> majorityElementBetter(vector<int> &arr){
    unordered_map<int,int> mp;
    for(auto &it:arr){
        mp[it]++;
    }

    vector<int> ans;
    for(auto &it:mp){
        if(it.second > arr.size()/3){
            ans.push_back(it.first);
        }
    }
    return ans;
}

//Optimal Approach
//TC:
//SC:
vector<int> majorityElementO(vector<int> &arr){
    int n = arr.size();
    int count1= 0, count2 = 0;
    int ele1, ele2;
    for(int i=0; i<n; i++){
        if(count1 == 0 && arr[i] != ele2){
            ele1 = arr[i];
            count1 = 1;
        }
        else if(count2 == 0 && arr[i] != ele1){
            ele2 = arr[i];
            count2 = 1;
        }
        else if(arr[i] == ele1) count1++;
        else if(arr[i] == ele2) count2++;
        else{
            count1--;
            count2--;
        }
    }

    count1 = 0, count2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele1)  count1++;
        else if(arr[i] == ele2) count2++;
    }
    if(count1>n/3 && count2>n/3){
        return {ele1,ele2};
    }
    else if(count1>n/3) return {ele1};
    else if(count2>n/3) return {ele2};
    else return {};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    return 0;
}