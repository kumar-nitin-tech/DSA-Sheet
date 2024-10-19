/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//TC:
//SC:

void insertStack(stack<int> &s, int n){
    if(s.empty() || (!s.empty() && s.top()<n)){
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    insertStack(s,n);
    s.push(num);
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int n = s.top();
    s.pop();
    sortStack(s);

    insertStack(s,n);
}

int main(){
    stack<int> s;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    for(auto i:arr) s.push(i);

    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
    }
    return 0;
}