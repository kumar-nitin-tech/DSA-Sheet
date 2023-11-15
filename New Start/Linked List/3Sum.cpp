/*
    3 Sum : Find triplets that add up to a zero

    Problem Statement:  Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the 
                        unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.  

    Problem Link:   https://leetcode.com/problems/3sum/
                    https://www.codingninjas.com/studio/problems/893028?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(N^3)
//SC:   O(N)
vector<vector<int>> threeSumBrute(vector<int> &arr){
    int n = arr.size();
    set<vector<int>> st;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//Better Approach
//TC: O(N^2)
//SC: O(N)
vector<vector<int>> threeSumBetter(vector<int> &arr){
    int n = arr.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        set<int> hashSet;
        for(int j=i+1; j<n; j++){
            int third = 0-(arr[i]+arr[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {arr[i],arr[j],third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//Optimal Approach
//TC: O(N^2 * log (no. of triplets))
//SC: O(2*no.of triplets) + O(N)
vector<vector<int>> threeSumBetter(vector<int> &arr){
    int n = arr.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        set<int> hashSet;
        for(int j=i+1; j<n; j++){
            int third = 0-(arr[i]+arr[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {arr[i],arr[j],third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//Optimal Approach
//TC:
//SC:
vector<vector<int>> threeSumOptimal(vector<int> &arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<arr.size(); i++){
        if(i!=0 && arr[i] == arr[i-1])  continue;
        int start = i+1, end = arr.size()-1;
        
        while(start<end){
            int sum = arr[i]+arr[start]+arr[end];
            if(sum>0){
                end--;
            }
            else if(sum <0){
                start++;
            }else{
                ans.push_back({arr[i],arr[start], arr[end]});
                end--;
                start++;
                while(start<end && arr[start] == arr[start-1])  start++;
                while(start<end && arr[end] == arr[end+1])  end--;
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}