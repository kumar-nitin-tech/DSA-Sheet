/*
    Check for Balanced Parentheses

    Problem Statement:  Check Balanced Parentheses. Given string str containing just the characters '(', ')', '{', '}', '[' and ']', check if the input string is valid and return true if the string is balanced otherwise return false.

    Problem Link:https://leetcode.com/problems/valid-parentheses/description/

    Refer:  https://takeuforward.org/data-structure/check-for-balanced-parentheses/

*/

#include<bits/stdc++.h>
using namespace std;

//TC: O(N)
bool isValid(string s){
    stack<int> st;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();

            if((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[')  || (s[i] == '}' && ch == '{') ) continue;
            else return false;
        }
        
    }

    return st.empty();
}

int main(){
    string s;
    cin>>s;
    cout<<isValid(s);
    return 0;
}