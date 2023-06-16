/*
    Problem Statement : Pair Sum
    Problem Link: https://www.codingninjas.com/codestudio/problems/pair-sum_8230699?challengeSlug=striver-sde-challenge&leftPanelTab=0
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin(), arr.end());
    int low = 0 , high = arr.size()-1;
    vector<vector<int>> ans;

    while(low<=high){
        if(arr[low] + arr[high] == s){
            ans.push_back({arr[low], arr[high]});
            high--;
        }
        else if(arr[low] + arr[high] > s){
            high--;
        }
        else{
            low++;
        }
    }
    return ans;
}

vector<vector<int>> pairSumO(vector<int> &arr, int s){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    unordered_map<int, int> umap;
    for(int i=0;i<arr.size();i++){
        if(umap.find(s-arr[i]) != umap.end()){
            int count = umap[s-arr[i]];
            while(count--){
                ans.push_back({s-arr[i], arr[i]});
            }
        }
        umap[arr[i]] ++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n,s;
    cin>>n>>s;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    vector<vector<int>> ans = pairSumO(arr,s);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}