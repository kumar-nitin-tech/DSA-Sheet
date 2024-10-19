/*
    Count and Say

    Problem Statement:  The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

                        countAndSay(1) = "1"
                        countAndSay(n) is the run-length encoding of countAndSay(n - 1).
                        Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

                        Given a positive integer n, return the nth element of the count-and-say sequence.

    Problem Link:   https://leetcode.com/problems/count-and-say/description/

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:
//SC:
string countAndSay(int n){
    string ans = "1";
    int itr = 1;
    while(itr<n){
        itr++;
        string temp = "";
        int cnt = 0;
        for(int i=0; i<ans.size(); i++){
            cnt++;
            if(ans[i] != ans[i+1]){
                temp += to_string(cnt)+ans[i];
                cnt = 0;
            }
        }
        ans = temp;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<countAndSay(n);
    return 0;
}