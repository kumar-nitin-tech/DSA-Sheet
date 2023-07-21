/*
    Rotate Matrix

    Problem Statement:  You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
                        You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

    Problem Link:   https://leetcode.com/problems/rotate-image/
                    https://www.codingninjas.com/studio/problems/rotate-the-matrix_6825090

    Refer:  https://takeuforward.org/data-structure/rotate-image-by-90-degree/
            https://www.youtube.com/watch?t=1&v=Y72QeX0Efxw&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F&feature=emb_imp_woyt
*/

#include<bits/stdc++.h>
using namespace std;

//Brute Approach
//TC: O(n2)
//SC: O(n*m)
//Create a ans matrix and set value at correct index
void rotateMatrixR(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][(n-1)-i] = mat[i][j];
        }
    }
    mat = ans;
}

//Optimal Approach
void rotateMatrix(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();

    //Transpose the Matrix
    for(int i=0;i<n-1;i++){
        for(int j = i+1; j<m;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    //Reverse every row
    for(int i=0;i<n;i++){
        //row is mat[i]
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(auto &i:mat){
        for(auto &j:i){
            cin>>j;
        }
    }
    rotateMatrix(mat);

    for(auto i:mat){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}