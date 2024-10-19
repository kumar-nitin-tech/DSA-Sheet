/*
    Reverse Words in a String

    Problem Statement:  Given a string s, reverse the words of the string.

    Problem Link:   https://leetcode.com/problems/reverse-words-in-a-string/description/

    Refer:  https://takeuforward.org/data-structure/reverse-words-in-a-string/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(N)
//SC:   O(N)
string reverseWordInStringBrute(string &s){
    string ans = "";
    s+=" ";
    stack<string> st;
    string temp = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            st.push(temp);
            temp = "";
        }
        else
            temp+=s[i];
    }
    while(st.size() != 1){
        ans += st.top()+" ";
        st.pop();
    }
    ans+=st.top();
    return ans;
}

//Optimal 
//TC:   O(N)
//SC:   O(1)
string reverseWordInStringOptimal(string &s){
    int n = s.size();
    string ans = "";
    int i = n-1;
    while(i>=0){
        while(i>=0 && s[i] == ' ')  i--;
        if(i<0) break;
        int j = i;
        while(i>=0 && s[i] != ' ') i--;
        string temp = s.substr(i+1,j-i);
        if(ans == ""){
            ans = temp;
        }else{
            ans = ans + " " + temp;
        }
    }
   
    return ans;
}

int main(){
    string s;
    getline(cin,s);
    cout<<reverseWordInStringOptimal(s);
    return 0;
}