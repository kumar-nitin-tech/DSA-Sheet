/*
    Area of largest rectangle in Histogram

    Problem Statement:  Given an array of integers heights representing the histogram's bar height where the width of each bar is 1  return the area of the largest rectangle in histogram.  

    Problem Link:   https://leetcode.com/problems/largest-rectangle-in-histogram/description/

    Refer:  https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/

*/

#include<bits/stdc++.h>
using namespace std;

//TC:
//SC:
int largestRectangleAreaBrute(vector<int>& heights) {
    int maxi = 0;
    for(int i=0; i<heights.size(); i++){
        int minHeight = INT_MAX;
        for(int j=i; j<heights.size(); j++){
            minHeight = min(minHeight,heights[j]);
            maxi = max(maxi, minHeight * (j-i+1));
        }
    }
    return maxi;
}

//TC:
//SC:

vector<int> nextSmallerHelper(vector<int> &heights){
    stack<pair<int, int>> s;
    int n = heights.size();
    vector<int> ans(n,n);
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && s.top().second >= heights[i]){
            s.pop();
        }
        if(!s.empty())
            ans[i] = s.top().first;
        s.push({i,heights[i]});
    }
    return ans;
}

vector<int> prevSmallerHelper(vector<int> &heights){
    stack<pair<int, int>> s;
    int n = heights.size();
    vector<int> ans(n,-1);
    for(int i=0; i<n; i++){
        while(!s.empty() && s.top().second >= heights[i]){
            s.pop();
        }
        if(!s.empty())
            ans[i] = s.top().first;
        s.push({i,heights[i]});
    }
    return ans;
}

int largestRectangleAreaBetter(vector<int>& heights) {
    //We find next smaller and prev smaller array
    vector<int> nextSmaller =  nextSmallerHelper(heights);
    vector<int> prevSmaller = prevSmallerHelper(heights);
    
    int maxArea = 0;
    for(int i=0; i<heights.size(); i++){
        int area = heights[i] * (nextSmaller[i]-prevSmaller[i]-1);
        maxArea = max(area,maxArea);
    }
    return maxArea;  
}

//TC:
//SC:
int largestRectangleAreaOptimal(vector<int>& heights) {
    //in one pass
    int maxArea = 0;
    stack<int> s;
    for(int i=0; i<=heights.size(); i++){
        while(!s.empty() && (i==heights.size() || heights[s.top()] >= heights[i])){
            int h = heights[s.top()];
            s.pop();
            int w;
            if(s.empty()){
                w = i;
            }
            else{
                w = i-s.top()-1;
            }
            maxArea = max(maxArea,h*w);
        }
        s.push(i);
    } 
    return maxArea;
}


int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(auto &i:heights)    cin>>i;
    cout<<largestRectangleAreaOptimal(heights);
    return 0;
}