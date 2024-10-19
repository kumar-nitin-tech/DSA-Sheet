/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force -> Using 
//TC: O(N3)
//SC: O(1)
bool checkPalindrome(string s){
   string temp = s;
   reverse(temp.begin(),temp.end());
   return temp==s;
}
string lpsBrute(string s){
    int n = s.size();
    int len = 0;
    int maxAns = INT_MIN;
    string ans = "";
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            string temp = s.substr(i,j-i+1);
            if(checkPalindrome(temp)){
                 len = j-i+1;
                if(len>maxAns){
                    maxAns = len;
                    ans = s.substr(i,maxAns);
                } 
             }
        }
    }
    return ans;
}

//Optimal Approach -> Expand from center
string lenOfPalindrome(string s, int left, int right){
    while(left>=0 && right<s.size() && s[left] == s[right]){
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}
string lpsOptimal(string s){
    int start = 0, end = 0;
    if(s.size()<=1){
        return s;
    }
    string ans = "";
    
    for(int i=0; i<s.size(); i++){
        string len1 = lenOfPalindrome(s,i,i);
        string len2 = lenOfPalindrome(s,i,i+1);
        if(len1.size() > ans.size()){
            ans = len1;
        }
         if(len2.size() > ans.size()){
            ans = len2;
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<lpsOptimal(s);
    return 0;
}