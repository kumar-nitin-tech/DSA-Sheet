/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(n1*n2*n2)
//SC:   O(1)

int nextGreaterBrute(vector<int> &nums2, int ind){
    for(int i=ind; i<nums2.size(); i++){
        if(nums2[i] > nums2[ind]){
            return nums2[i];
        }
    }
    return -1;
}

vector<int> nextGreaterElementBrute(vector<int> &nums1, vector<int> &nums2){

    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> ans;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(nums1[i] == nums2[j]){
                ans.push_back(nextGreaterBrute(nums2,j));
            }
        }
    }
    return ans;
}


//Optimal Approach
//TC:   O(n1*n2 + n2)
//SC:   O(n2+n2)
vector<int> nextGreaterElementOptimal(vector<int> &nums1, vector<int> &nums2){
    vector<int> nextGreater(nums2.size(),-1);
    stack<int> s;
    for(int i=nums2.size()-1; i>=0; i--){
        while(!s.empty() && nums2[i] >s.top()){
            s.pop();
        }
        if(!s.empty())
            nextGreater[i] = s.top();
        s.push(nums2[i]);
    }

    vector<int> ans;

    for(int i=0; i<nums1.size(); i++){
        for(int j=0; j<nums2.size(); j++){
            if(nums1[i] == nums2[j]){
                ans.push_back(nextGreater[j]);
            }
        }
    }
    return ans;

}

//With Circular Array
vector<int> nextGreaterElementOptimalCircular(vector<int> nums){
    vector<int> ans(nums.size(),-1);
    int n = nums.size();
    stack<int> s;
    for(int i=2*n-1; i>=0; i--){
        while(!s.empty() && nums[i%n] >= s.top()){
            s.pop();
        }
        if(i<n){
            if(!s.empty())  ans[i] = s.top(); 
        }
        s.push(nums[i%n]);
    }
    return ans;
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> nums1(n1), nums2(n2);
    for(auto &i:nums1)  cin>>i;
    for(auto &i:nums2)  cin>>i;

    vector<int> ans =nextGreaterElementOptimal(nums1,nums2);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}