/*
    Length of Longest Substring without any Repeating Character

    Problem Statement:  Given a String, find the length of longest substring without any repeating character.  

    Problem Link:   https://leetcode.com/problems/longest-substring-without-repeating-characters/
                    https://www.codingninjas.com/studio/problems/630418?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O(N^2)
//SC: O(N)
int longestSubstringWithOutRepeatngCharBrute(string &s){
    int count = 0;
    for(int i=0; i<s.size(); i++){
        unordered_set<int> hashSet;
        for(int j=i; j<s.size(); j++){
            if(hashSet.find(s[j]) != hashSet.end()){
                break;
            }
            hashSet.insert(s[j]);
        }
        int hashSize = hashSet.size();
        count = max(count,hashSize);
    }
    return count;
}

//Better Approach
//TC: O(2N)
//SC: O(N)
int longestSubStringWithOutRepeatingCharBetter(string &s){
    //Idea is to keep two pointer to check the prev char exists in set then move until its not equal
    int l = 0;
    int n = s.size();
    unordered_set<int> mp;
    int maxi = 0;
    for(int r=0; r<n; r++){
        if(mp.find(s[r]) != mp.end()){
            while(l<r && mp.find(s[r]) != mp.end()){
                mp.erase(s[l]);
                l++;
            }
        }
        mp.insert(s[r]);
        maxi = max(maxi,r-l+1);
    }
    return maxi;
}


//Optimise Approach
//TC: O(N)
//SC: O(N)
int longestSubStringWithOutRepeatingCharOptimal(string &s){
    //Idea is to keep two pointer to check the prev char exists in set then move until its not equal
    int l = 0;
    int n = s.size();
    unordered_map<char,int> mp;
    int maxi = 0;
    for(int r=0; r<n; r++){
        if(mp.find(s[r]) != mp.end()){
            l = max(mp[s[r]]+1, l);
        }
        mp[s[r]] = r;
        maxi = max(maxi,r-l+1);
    }
    return maxi;
}


int main(){
    string s;
    cin>>s;
    cout<<longestSubstringWithOutRepeatngCharBrute(s);
    return 0;
}