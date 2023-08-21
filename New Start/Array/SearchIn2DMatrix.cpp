/*
    Search in a sorted 2D matrix

    Problem Statement:  Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

    Problem Link:   https://www.codingninjas.com/studio/problems/search-in-a-2d-matrix_980531
                    https://leetcode.com/problems/search-a-2d-matrix/

    Refer:  https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
            https://www.youtube.com/watch?v=JXU4Akft7yk

*/

#include<bits/stdc++.h>
using namespace std;

//Linear Search Brute Force
//TC: O(n2)
//SC: O(1)
bool searchKeyL(vector<vector<int>> &arr, int k){
    for(auto &i:arr){
        for(auto &j: i){
            if(j == k){
                return true;
            }
        }
    }
    return false;
}

//Optimised binary search
//TC:
//SC:

bool searchKeyTwo(vector<vector<int>> &arr, int k){
    int n = arr.size();
    int m = arr[0].size();
    int row = n-1;
    int col = 0;
    while(col<m && row>=0){
        if(arr[row][col] == k){
            return true;
        }
        else if(arr[row][col] > k){
            row--;
        }else{
            col++;
        }
    }
    return false;
}
//Optimised binary search
//TC:   O(log(n*m))
//SC:   O(1)

bool searchKey(vector<vector<int>> &arr, int k){
    //hypothecially assume a flatten 1d array contain element of matrix
    int n = arr.size();
    int m = arr[0].size();
    int low = 0, high = (n*m)-1;
    while(low<=high){
        int mid = (low+high)/2;
        int row = mid/m;
        int col = mid%m;
        if(arr[row][col] == k){
            return true;
        }
        arr[row][col] < k ? low = mid+1 : high = mid-1;
    }
    return false;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> arr(n, vector<int>(m));
    for(auto &i:arr){
        for(auto &j:i){
            cin>>j;
        }
    }
    cout<<searchKeyL(arr,k);
    return 0;
}