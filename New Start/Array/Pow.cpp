/*
    Implement Pow(x,n) | X raised to the power N

    Problem Statement:  Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).

    Problem Link:   https://leetcode.com/problems/powx-n/
                    https://www.codingninjas.com/studio/problems/find-x-raised-to-power-n-_626560

    Refer:  https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/
            https://www.youtube.com/watch?v=l0YC3876qxg

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//TC:   O(N)
//SC:   O(1)
double power(double x, int n){
    long long nn = n;
    if(nn<0)    nn = 0-nn;
    double ans = 1;
    for(long long i=0; i<nn; i++){
        ans *= x;
    }
    if(n<0) ans = 1/ans;
    return ans;
}

//Binary Exponentation
//TC:   O(log n)
//SC:   O(1)
double powerBinary(double x, int n){
    long long nn = n;
    if(nn<0)    nn = 0-n;
    double ans = 1.0;
    while(nn){
        if(nn%2 == 0){
            x *= x;
            nn = nn/2;
        }
        else{
            ans *= x;
            nn = nn-1;
        }
    }
    if(n<0) return 1/ans;
    else return ans;
}

int main(){
    double x;
    int n;
    cin>>x>>n;
    cout<<powerBinary-(x,n);
    return 0;
}