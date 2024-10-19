/*
    Valid Anagram
    Problem Statement:     Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    Problem Link:   https://leetcode.com/problems/valid-anagram/description/

    Refer:  

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force -> Using Hash
//TC:
//SC:
bool isAnagramBrute(string s, string t){
    if(s == t){
        return 1;
    }
    unordered_map<char,int> map;
    for(int i=0; i<s.size(); i++){
        map[s[i]]++;
    }

    for(int i=0; i<t.size(); i++){
        if(map.find(t[i]) != map.end()){
            map[t[i]]--;
        }else{
            return false;
        }
    }
    for(auto i:map){
        if(i.second != 0){
            return false;
        }
    }
    
    return true;
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<isAnagramBrute(s,t);
    return 0;
}