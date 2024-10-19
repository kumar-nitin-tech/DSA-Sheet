/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> &arr){
    stack<int> st;
    vector<int> ans(arr.size(),-1);

    for(int i=0; i<arr.size(); i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<int> ans = nextSmaller(arr);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}