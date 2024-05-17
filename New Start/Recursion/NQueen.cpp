/*
    N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle

    Problem Statement:  The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all 
                        distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen's placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

    Problem Link:   https://leetcode.com/problems/n-queens/description/
                    https://www.naukri.com/code360/problems/n-queens_759332?topList=striver-sde-sheet-problems&problemListRedirection=true&search=N%20queen

    Refer:  https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force -> Using Backtracking principle of recursion
//Tc: O(N! * N * N)
//SC: O(N^2)

//Hepler

bool isSafe(int col, int row, vector<string> &board, int n){
    int dupRow = row, dupCol = col;
    //Upper Diagonal
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q')  return false;
        row--;
        col--;
    }
    col = dupCol;
    row = dupRow;
    //Row
    while(col>=0){
        if(board[row][col] == 'Q')  return false;
        col--;
    }

    col = dupCol;
    while(row<n && col>=0){
        if(board[row][col] == 'Q')  return false;
        row++;
        col--;
    }

}

void bruteHelper(vector<vector<string>> &ans, vector<string> &board, int n, int col){
    if(col == n){
        ans.push_back(board);
        return;
    }    

    //Iterate for every row
    for(int row = 0; row<n; row++){
        if(isSafe(col, row, board, n)){
            board[row][col] = 'Q';
            bruteHelper(ans,board,n,col+1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueenBrute(int n){
    vector<vector<string>> ans;
    vector<string> board(n, string(n,'.'));
    bruteHelper(ans,board,n,0);
    return ans;
} 


//Optimal Approach
//TC:   O(N!*N)
//SC:   O(N)
void optimalHelper(vector<vector<string>> &ans, vector<string> &board, int n, int col, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &loweDiagonal){
    if(col == n){
        ans.push_back(board);
        return;
    }    

    //Iterate for every row
    for(int row = 0; row<n; row++){
        if(leftRow[row] == 0 && upperDiagonal[(n-1) + (col-row)] == 0 && loweDiagonal[row+col] == 0){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[n-1 + col-row] = 1;
            loweDiagonal[row+col] = 1;
            optimalHelper(ans,board,n,col+1,leftRow,upperDiagonal,loweDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[n-1 + col-row] = 0;
            loweDiagonal[row+col] = 0;
        }
    }
}

vector<vector<string>> solveNQueenOptimal(int n){
    vector<vector<string>> ans;
    vector<string> board(n, string(n,'.'));
    vector<int> leftRow(n,0), upperDiagonal(2*n-1,0),loweDiagonal(2*n-1,0);
    optimalHelper(ans,board,n,0,leftRow,upperDiagonal,loweDiagonal);
    return ans;
} 

int main(){
    int n;
    cin>>n;
    vector<vector<string>> ans = solveNQueenOptimal(n);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" "<<endl;
        }
        cout<<endl;
    }
    return 0;
}