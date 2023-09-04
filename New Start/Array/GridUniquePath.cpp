/*
    Grid Unique Paths

    Problem Statement:  Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from 
                        each cell you can either only move to the rightward direction or the downward direction.

    Problem Link:   https://leetcode.com/problems/unique-paths/
                    https://www.codingninjas.com/studio/problems/1081470?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach ( Recursion )
//TC:   O(2^N)
//SC:   O(N) -> Auxiallry Stack Space
int uniquePathB(int i, int j){
    if(i==0 && j == 0 ){
        return 1;
    }
    if(i<0 || j<0)  return 0;

    //We can go up or left
    int up = uniquePathB(i-1,j);
    int left = uniquePathB(i,j-1);

    return up+left;
}

//Better Approach Using DP
//TC: O(N*M)
//SC: O(M)
int uniquePathDp(int n, int m){
    //Tabulation
    //vector<vector<int>> dp(n,vector<int> (m,0));
    //we can use prev and curr space optimization
    vector<int> prev(m,0), curr(m,0);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0){
                curr[j] = 1;
            }
            else{
                int up = 0, left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];
                curr[j] = up+left;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

//Optimal Approach
//TC: O(N) or O(M)
//SC: O(1)
int uniquePathO(int n, int m){
    int N = n+m-2;
    int r = n-1;
    double ans = 1;
    for(int i=1; i<=r; i++){
        ans = ans* (N-r+i)/i;
    }
    return (int)ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    cout<<uniquePathO(n,m);
    return 0;
}