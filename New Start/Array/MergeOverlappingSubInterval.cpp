/*
    Merge Overlapping Sub-intervals

    Problem Statement:  Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping 
                        intervals.

    Problem Link:   https://www.codingninjas.com/studio/problems/merge-all-overlapping-intervals_6783452

    Refer:  https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
            https://www.youtube.com/watch?v=IexN60k62jo&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F&feature=emb_imp_woyt
*/

#include<bits/stdc++.h>
using namespace std;


//Brute Force Approach
//Tc: O(NlogN) + O(2N)
//SC: O(N)
vector<vector<int>> mergeOverlappingB(vector<vector<int>> &arr){
    int n = arr.size();
    //sorting the arra so that we get the close element near
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    //merge
    for(int i=0;i<n;i++){
        int start = arr[i][0], end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(end >= arr[j][0]){
                end = max(end, arr[j][1]);
            }
            else    break;
        }
        ans.push_back({start,end});
    }
    return ans;
}

//Optimal Approach
vector<vector<int>> mergeOverlapping(vector<vector<int>> &arr){
    int n = arr.size();
    //sorting the arra so that we get the close element near
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        //if ans array is empty we push the intially value to check further
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back({arr[i][0], arr[i][1]});
        }

        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));

    for(auto &i:arr){
        for(auto &j:i){
            cin>>j;
        }
    }

    vector<vector<int>> ans = mergeOverlappingB(arr);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}