/*
    Set Matrix Zero

    Problem Statement:  Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

    Problem Link:   https://leetcode.com/problems/set-matrix-zeroes/
                    https://www.codingninjas.com/studio/problems/zero-matrix_1171153

    Refer:  Notes
            https://takeuforward.org/data-structure/set-matrix-zero/
            https://www.youtube.com/watch?v=N0MgLvceX7M
*/

#include<bits/stdc++.h>
using namespace std;

void markRow(int i, vector<vector<int>> &mat){
    for(int j=0;j<mat.size();j++){
        if(mat[i][j] != 0)  mat[i][j] = -1;
    }
}

void markCol(int j, vector<vector<int>> &mat){
    for(int i=0;i<mat.size();i++){
        if(mat[i][j] != 0)  mat[i][j] = -1;
    }
}

//Brute Force 
//Time Complexity:  O(n*m)*O(n+m) + O(n*m) -> nearly equal to O(n3)
//Space Complexity: O(1)
vector<vector<int>> setMatrixZeroB(int n, int m, vector<vector<int>> &mat){
    //Iterate and mark row and col with -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                markRow(i,mat);
                markCol(j,mat);
            }
        }
    }
    //Marking every -1 to 0
    for(auto &i:mat){
        for(auto &j:i){
            if(j==-1)   j=0;
        }  
    }
    return mat;
}

//Better Approach
//Time Complexity:  O(n*m) + O(n*m) -> O(n2)
//Space Complexity: O(n) + O(m)
vector<vector<int>> setMatrixZeroBetter(int n, int m, vector<vector<int>> &mat){
    vector<int> row(n,0), col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] == 1 || col[j] == 1){
                mat[i][j] = 0;
            }
        }
    }
    return mat;
}

//Optimal Approach
//Time Complexity:  O(n*m) + O(n*m) -> O(n2)
//Space Complexity: O(1)
vector<vector<int>> setMatrixZeroO(int n, int m, vector<vector<int>> &mat){
    //col[m] -> mat[0][..]
    //row[n] -> mat[..][0]

    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                //marking row of the matrix
                mat[i][0] = 0;
                if(j!=0)
                    mat[0][j] = 0;
                else 
                    col0 = 0;
            }
        }
    }
    
    //Setting the matix to zero
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][0] == 0 || mat[0][j] == 0){
                mat[i][j] = 0;
            }
        }
    }

    //Setting row and col 
    if(mat[0][0] == 0){
        for(int j=0;j<m;j++){
            mat[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<n;i++){
            mat[i][0] = 0;
        }
    }
    return mat;
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
    mat = setMatrixZeroO(n,m,mat);

    for(auto i:mat){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}