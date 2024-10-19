/*
    Implement Min Stack

    Problem Statement:  Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.  

    Problem Link:   https://leetcode.com/problems/min-stack/description/

    Refer:  https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/

*/

#include<bits/stdc++.h>
using namespace std;


//SC: O(2N)
//TC: O(1)
class minStackBrute{
    public:
    stack<pair<int,int>> s;

    void push(int val){
        int mini;
        if(s.empty()){
            mini = val;
        }else{
            mini = min(s.top().second, val);
        }
        s.push({val,mini});
    }

    void pop(){
        s.pop();
    }

    int top(){
        return s.top().first;
    }

    int getMin(){
        return s.top().second;
    }

};

//SC: O(N)
//TC: O(1)
class minStackOptimal{
    stack<int> s;
    long long mini = INT_MAX;
    public:
    void push(int value){
        long long val = (long long)value;
        if(s.empty()){
            mini = val;
            s.push(val);
        }else{
            if(val>mini){
                s.push(val);
            }else{
                //modified value
                s.push(2*val*1LL - mini);
                mini = val;
            }
        }
    }

    void pop(){
        if(s.empty())   return;
        long long curr = s.top();
        s.pop();
        if(curr<mini){
            mini = 2*mini - curr;
        }
    }

    int top(){
        if(s.empty())   return -1;
        long long el = s.top();
        if(el<mini)    return mini;
        return el;
    }

    int getMin(){
        return mini;
    }
};

int main(){
    minStackOptimal minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout<<minStack.getMin()<<endl;
    minStack.pop();
    cout<<minStack.getMin()<<endl<<minStack.top()<<endl;
    
    return 0;
}