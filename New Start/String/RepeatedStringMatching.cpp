/*
    Repeated String Match

    Problem Statement:  Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".  

    Problem Link:   https://leetcode.com/problems/repeated-string-match/description/

    Refer:  Rabin Karp Algo

*/

#include<bits/stdc++.h>
using namespace std;

bool stringMatch(string a, string b){
    for(int i=0; i<a.size(); i++){
        string temp = a.substr(i,b.size());
        if(temp == b){
            return true;
        }
    }
    return false;
}

//Brute Force
//TC: O(n*m)
int repeatedStringMatchBrute(string a, string b) {
    //Idea is to repeat the string if a.size()<b.size() till equal or greater than b.size();

    int cnt = 1;
    string temp = a;
    while(temp.size()<b.size()){
        temp += a;
        cnt++;
    }
    //Check the match pattern in string
    if(stringMatch(temp,b)){
        return cnt;
    }
    if(stringMatch(temp+a,b)){
        return cnt+1;
    }
    return -1;
}

int mod = 1e6;

//Using Rabin Karp Algo
long long hashString(string a){
    long long hash = 0;
    for(int i=0; i<a.size(); i++){
        hash = (hash*31 + a[i])%mod;
    }
    return hash;
}

bool checkMatch(string a, string b){
    int m = b.size();
    long long highPow = 1;
    for(int i=0; i<m; i++){
        highPow = (highPow*31)%mod;
    }
    long long bHash = hashString(b);
    long long aHash = 0;
    cout<<bHash<<endl;
    
    for(int i=0; i<a.size(); i++){
        aHash = (aHash*31 + a[i])%mod;
        if(i<m-1)   continue;
        if(i>=m){
            aHash = (aHash - a[i-m]*highPow)%mod;
        }
        if(aHash<0){
            aHash += mod;
        }
        if(aHash == bHash){
            if(a.substr(i-m+1, m) == b){
                return 1;
            }
        }
    }
    return false;
}
//Optimal APproach -> Rabin Karp Algorithm
//TC: O(N+m-1)
int repeatedStringMatchOptimal(string a, string b) {
    if(a==b){
        return 1;
    }
    int cnt = 1;
    string temp = a;
    while(temp.size()<b.size()){
        temp += a;
        cnt++;
    }
    
    //Check the match pattern in string
    if(checkMatch(temp,b)){
        return cnt;
    }
    if(checkMatch(temp+a,b)){
        return cnt+1;
    }
    return -1;
}




int main(){
    string a,b;
    cin>>a>>b;
    cout<<repeatedStringMatchOptimal(a,b);
    return 0;
}