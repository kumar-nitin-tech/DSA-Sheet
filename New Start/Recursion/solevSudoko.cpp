/*
    Sudoku Solver
    
    Problem Statement:  Given a 9x9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.

         1. All the rows should be filled with numbers(1 - 9) exactly once.

         2. All the columns should be filled with numbers(1 - 9) exactly once.

         3. Each 3x3 submatrix should be filled with numbers(1 - 9) exactly once.      

    Problem Link:   https://leetcode.com/problems/sudoku-solver/description/   

    Refer:  https://takeuforward.org/data-structure/sudoku-solver/

*/

#include<bits/stdc++.h>
using namespace std;

//TC: O(9^(n^2))
//SC: O(1)

bool isValid(vector<vector<char>> &board, int row, int col, char c){
    for(int i=0; i<9; i++){
        if(board[row][i] == c)  return false;
        if(board[i][col] == c)  return false;
        if(board[(3*(row/3) + i/3)][(3*(col/3) + i%3)] == c)    return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board){
    
    for(int i=0; i<board.size(); i++){
        for(int j =0; j<board[0].size(); j++){
            if(board[i][j] == '.'){
                for(char c = '1'; c<='9'; c++){
                    if(isValid(board,i,j,c)){
                        board[i][j] = c;
                        if(solve(board) == true){
                            return true;
                        }else{
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoko(vector<vector<char>> &board){
    solve(board);
}

int main(){
    vector<vector<char>> board (9,vector<char>(9));
    for(auto &i:board){
        for(auto &j:i){
            cin>>j;
        }
    }
    solveSudoko(board);

    for(auto i:board){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}