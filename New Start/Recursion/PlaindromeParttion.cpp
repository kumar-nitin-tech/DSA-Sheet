/*
    Palindrome Partitioning
    Problem Statement:  You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.

    Problem Link:   https://leetcode.com/problems/palindrome-partitioning/description/
                    https://www.naukri.com/code360/problems/palindrome-partitioning_626181

    Refer:  https://takeuforward.org/data-structure/palindrome-partitioning/

*/

#include<bits/stdc++.h>
using namespace std;

//Optimal Approach
//TC: O(2^N * k * N/2 )  O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another 
//                      data structure, where k  is the average length of the palindrome list.
//SC: O(N)

bool isPalindrome(int start, int end, string s){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void partitionHelper(vector<vector<string>> &ans, vector<string> &temp, string &s, int ind){
    if(ind == s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        if(isPalindrome(ind,i,s)){
            string subStr = s.substr(ind,i-ind+1);
            temp.push_back(subStr);
            partitionHelper(ans,temp,s,i+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> palindromePartition(string s){
    vector<vector<string>> ans;
    vector<string> temp;
    partitionHelper(ans,temp,s,0);
    return ans;
}


int main(){
    string s;
    cin>>s;
    vector<vector<string>> ans = palindromePartition(s);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
}