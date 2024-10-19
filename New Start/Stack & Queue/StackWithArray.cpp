/*
    Implement Stack using Array

    Problem Statement:  

    Problem Link:   https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

    Refer:  https://takeuforward.org/data-structure/implement-stack-using-array/

*/

#include<bits/stdc++.h>
using namespace std;

class st{
    int top;
    int size;
    int *arr;
    public:
    st(){
        top = -1;
        size = 10000;
        arr = new int[size];
    }

    void push(int n){
        top++;
        arr[top] = n;
    }

    void pop(){
        top--;
    }
    int Top(){
        return arr[top];
    }
};

int main(){
    st s;
    s.push(1);
    s.push(2);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;

    return 0;
}