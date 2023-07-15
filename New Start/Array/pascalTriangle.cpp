/*
    Pascal's Triangle

    Problem Statement:  Given an integer numRows, return the first numRows of Pascal's triangle.

    Problem Link:   https://leetcode.com/problems/pascals-triangle/
                    https://www.codingninjas.com/studio/problems/print-pascal-s-triangle_6917910

    Refer:  Notes
            https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
            https://www.youtube.com/watch?v=bR7mQgwQ_o8
*/
#include<bits/stdc++.h>
using namespace std;

//nCr Helper
//Time Complexity: O(r)
int nCr(int n, int r){
    long long ans = 1;
    for(int i=0;i<r;i++){
        ans = ans*(n-i);
        ans = ans/(i+1);
    }
    return ans;
}

//1st Type of Problem 
//Where we have given a r and c number and we have to give the element number at that place
int giveElementAtPascalTriangle(int r, int c){
    //There is the formula which determine the element number
    //nCr = n! / r! * (n-r)!
    return nCr(r,c);
}

//2nd Type of Problem 
//We have to print entire row for given row number
//Time Complexity: O(n)
vector<int> PascalRow(int n){
    vector<int> temp;
    temp.push_back(1);
    int ans = 1;
    for(int i=1;i<n;i++){
        ans = ans*(n-i);
        ans = ans/i;
        temp.push_back(ans);
    }
    return temp;
}

//Print Full Pascal Triangle 
vector<vector<int>> generatePascalTriangle(int n){
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        vector<int> temp = PascalRow(i);
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans = generatePascalTriangle(n);

    for(auto &i:ans){
        for(auto &j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}