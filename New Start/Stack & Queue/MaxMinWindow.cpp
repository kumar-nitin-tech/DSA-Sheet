/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(N^3)
//SC:   O(1)
vector<int> maxMinWindowSizeBrute(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        for(int j=i; j<n-i; j++){
            int mini = INT_MAX;
            for(int k=j; k<j+i-1; k++){
                mini = min(arr[k],mini);
            }
            ans[i] = max(ans[i],mini);
        }
    }
    return ans;
}


//Better Approach
//TC:
//SC:
vector<int> maxMinWindowSizeBetter(vector<int> &arr){
    
}

//Optimal Approach
//TC:
//SC:
vector<int> maxMinWindowSizeOptimal(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n,INT_MIN);
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            //we are now computing stack element as we got the stack element next smaller element and we know prev smaller element
            int index = st.top();
            st.pop();
            if(st.empty()){
                int range = i;
                ans[range-1] = max(ans[range-1], arr[index]);
            }else{
                int range = i-st.top()-1;
                ans[range-1] = max(ans[range-1], arr[index]);
            }
        }
        st.push(i);
    }
     while(!st.empty()){
        //we are now computing stack element as we got the stack element next smaller element and we know prev smaller element
        int index = st.top();
        st.pop();
        if(st.empty()){
            int range = n;
            ans[range-1] = max(ans[range-1], arr[index]);
        }else{
            int range = n-st.top()-1;
            ans[range-1] = max(ans[range-1], arr[index]);
        }
    }

    //now compute remaining back element
    for(int i=n-2; i>=0; i--){
        ans[i] = max(ans[i],ans[i+1]);
    }

    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<int> ans = maxMinWindowSizeOptimal(arr);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}