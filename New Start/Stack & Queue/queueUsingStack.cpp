/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1,s2;

    public:
    //Push function TC: O(N)
    void push(int n){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(n);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }

    void pop(){
        s1.pop();
    }

    int top(){
        return s1.top();
    }
};

int main(){
    return 0;
}