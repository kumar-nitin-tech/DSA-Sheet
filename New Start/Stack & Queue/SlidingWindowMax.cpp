/*
    Sliding Window Maximum

    Problem Statement:  You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can 
                        only see the k numbers in the window. Each time the sliding window moves right by one position.
                        Return the max sliding window.  

    Problem Link:   https://leetcode.com/problems/sliding-window-maximum/description/

    Refer:  https://takeuforward.org/data-structure/sliding-window-maximum/

*/

#include<bits/stdc++.h>
using namespace std;

//TC: O(N^2)
//SC: O(1)
int getMax(int left, int right, vector<int> &nums){
    int maxi = INT_MIN;
    for(int i=left; i<=right; i++){
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}

vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {
    vector<int> ans;
    int left = 0, right = k-1;

    while(right < nums.size()){
        int maxi = getMax(left, right, nums);
        ans.push_back(maxi);
        left++;
        right++;
    }

    return ans;
}


//TC:
//SC:
vector<int> maxSlidingWindowOptimal(vector<int>& nums, int k) {
    //We create a deque
    deque<int> q;
    vector<int> ans;

    //idea to iterate over array and keep maximum element in front by poping element from back if curr array element is greater than deque back
    for(int i=0; i<nums.size(); i++){
        //check whether the deque is out bound or not
        if(!q.empty() && q.front() == i-k){
            q.pop_front();
        }
        //pop from back is element from back in deque
        while(!q.empty() && nums[q.back()] < nums[i]){
            q.pop_back();
        }  
        q.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &i:nums)    cin>>i;

    vector<int> ans = maxSlidingWindowOptimal(nums,k);
    for(auto i:ans) cout<<i<<" ";

    return 0;
}