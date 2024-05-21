/*
    Nth Root of a Number using Binary Search
   
    Problem Statement:  Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth 
                        root is not an integer, return -1.

    Problem Link:   https://www.naukri.com/code360/problems/1062679?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force
//TC: O(M)
//SC: O(1)
int NthRootBrute(int n, int m){
    for(int i=0; i<m; i++){
        long long val = pow(i,n);
        if(val == m*1ll){
            return i;
        }else if(val > m*1ll){
            break;
        }
    }

    return -1;
}

//Optimal approach
//TC: O(log M)
//SC: O(1)

long long mutliply(int mid, int n){
    long long ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans*mid;
    }
    return ans;
}

int NthRootOptimal(int n,int m){
    long long low = 1, high = m;
    while(low<=high){
        int mid = (low+high)/2;
        long long val = mutliply(mid,n);
        if(val == m){
            return mid;
        }
        else if(val > m){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<NthRootOptimal(n,m);
    return 0;
}