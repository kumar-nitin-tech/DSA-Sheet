/*
    Minimum Characters required to make a String Palindromic
   
    Problem Statement:  Given a string A. The only operation allowed is to insert characters at the beginning of the string.
Find how many minimum characters are needed to be inserted to make the string a palindrome string.  

    Problem Link: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

    Refer: Brute -> Find Longest Plandromic substr and ans would be size() - subst.size()
        Optimal -> Two Pointer left and right and and increase resultant if the left and rigth doesn't match 

*/

#include<bits/stdc++.h>
using namespace std;

//Brute -> Find Longest palindromic substr by left and right moving algo

//Optimal
//TC:   O(N)
//SC:   O(1)
int minInsertion(string s){
    int n = s.size();
    int ans = 0;
    int l = 0, r = n-1, tr = r;
    while(l<r){
        if(s[l] == s[r]){
            l++;
            r--;
        }else{
            ans++;
            r = --tr;
            l = 0;
        }
    }
    return ans;
}

vector<int> lpsArray(string pattern){
    int n = pattern.size();
    vector<int> lps(n);
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i<n){
        if(pattern[i] == pattern[len]){
            lps[i] = len+1;
            len++;
            i++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int minInsertionOptimal(string s){
    string temp = s;
    reverse(temp.begin(), temp.end());
    string rev = s + "$" + temp;
    vector<int> lps = lpsArray(rev);
    return (s.size()-lps[lps.size()-1]);
}


int main(){
    string s;
    cin>>s;
    cout<<minInsertionOptimal(s);
    return 0;
}