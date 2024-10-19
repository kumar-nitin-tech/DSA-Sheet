/*
    Find the Index of the First Occurrence in a String
    Problem Statement:  

    Problem Link:   Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Refer:  KMP, Rabin Karp

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(N*M)
//SC:   O(1)
int stringMatchBrute(string source, string pattern){
    if(source == pattern){
        return 0;
    }
    //Idea is to check every substr in source
    int n = source.size();
    int m = pattern.size();
    for(int i=0; i<=n-m; i++){
        string temp = source.substr(i,m);
        if(temp == pattern){
            return i;
        }
    }
    return -1;
}


//KMP Algo
//TC:
//SC:

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

int stringMatchBetter(string source, string pattern){
    if(source == pattern){
        return 0;
    }

    int n = source.size();
    int m = pattern.size();

    vector<int> lps = lpsArray(pattern);
    for(auto i:lps){
        cout<<i<<" ";
    }
    int i = 0, j = 0;
    while(i<n){
        if(source[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
        if(j==m){
            return i-m;
        }
    }
    return -1;
}


int main(){
    string source,pattern;
    cin>>source>>pattern;
    cout<<stringMatchBetter(source,pattern);
    return 0;
}