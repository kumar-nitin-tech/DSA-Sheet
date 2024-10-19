/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> st;
    public:
    void Push(int n){
        int s = st.size();
        st.push(n);
        for(int i=0; i<s; i++){
            st.push(st.front());
            st.pop();
        }
    }

    void pop(){
        st.pop();
    }

    int Top(){
        return st.front();
    }

};

int main(){
    Stack s;
    s.Push(1);
    s.Push(2);
    cout<<s.Top();
    s.pop();
    cout<<s.Top();
    return 0;
}