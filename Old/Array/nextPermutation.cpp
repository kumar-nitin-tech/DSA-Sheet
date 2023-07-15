/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

    For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

    For example, the next permutation of arr = [1,2,3] is [1,3,2].
    Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
    While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.
*/

#include<bits/stdc++.h>
using namespace std;

void Permutation(vector<int> &nums, vector<vector<int>> &ans, int idx){
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=idx; i<nums.size();i++){
        swap(nums[i], nums[idx]);
        Permutation(nums, ans, idx+1);
        swap(nums[i], nums[idx]);
    }
}

void nextPermutation(vector<int>&nums){
   vector<vector<int>> ans;
   int idx = 0;
   Permutation(nums, ans, idx);
   sort(ans.begin(), ans.end());


   int index = -1;
   for(int i=ans.size()-2; i>=0;i--){
        if(ans[i] == nums){
            index = i;
            break;
        }
   }
   if(index == ans.size()-1){
        for(auto i: ans[0]){
            cout<<i<<" ";
        }
   }
   else{
    for(auto i: ans[index+1]){
        cout<<i<<" ";
    }
   }
}

void nextpermutation(vector<int> &nums){
    int pivot = -1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        for(auto i:nums){
            cout<<i<<" ";
        }
        return;
    }
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    reverse(nums.begin()+pivot+1, nums.end());
    for(auto i:nums){
        cout<<i<<" ";
    }
}




int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(auto &i:nums){
        cin>>i;
    }
    nextPermutation(nums);
    return 0;
}