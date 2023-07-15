/*
    Problem Statement : Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
    Problem Link : https://leetcode.com/problems/trapping-rain-water/
*/

#include<bits/stdc++.h>
using namespace std;

//My Solution with some help
int trap(vector<int> &height){
    vector<int> leftMax;
    vector<int> rightMax;
    int leftMaxi=INT_MIN, rightMaxi =INT_MIN, ans = 0;
    for(int i=0;i<height.size();i++){
        leftMaxi = max(height[i],leftMaxi);
        leftMax.push_back(leftMaxi);
    }
    for(int i=height.size()-1;i>=0;i--){
        rightMaxi = max(height[i],rightMaxi);
        rightMax.push_back(rightMaxi);
    }
    reverse(rightMax.begin(), rightMax.end());

    for(int i=0;i<height.size();i++){
        ans += min(leftMax[i],rightMax[i]) - height[i];

    }
    return ans;
}

//Optimized Solution
int waterTrap(vector<int> &height, int n){
    int low = 0, high = n-1, leftMax = 0, rightMax = 0;
    int waterTrap = 0;
    while(low<=high){
        if(height[low]<=height[high]){
            if(height[low] >= leftMax){
                leftMax = height[low];
            }
            else{
                waterTrap += leftMax - height[low];
            }
            low++;
        }
        else{
            if(height[high]>=rightMax){
                rightMax = height[high];
            }
            else{
                waterTrap += rightMax - height[high];     
            }
            high--;
        }
    }
    return waterTrap;

}

int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(auto &i:height){
        cin>>i;
    }
    cout<<waterTrap(height,n);
    return 0;
}