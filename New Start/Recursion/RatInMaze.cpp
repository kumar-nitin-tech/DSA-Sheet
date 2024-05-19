/*
    Rat in a Maze
   
    Problem Statement:  Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the 
                        rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.  

    Problem Link:   https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

    Refer:  https://takeuforward.org/data-structure/rat-in-a-maze/

*/

#include<bits/stdc++.h>
using namespace std;

//TC: O(4^(n^2))
//SC: O(n^2)

void solvePath(vector<vector<int>> &visited, vector<vector<int>> &maze, vector<string> &ans, string temp, int n, int i, int j){
    //Lexiographically DLRU
    if(i == n-1 && j == n-1){
        ans.push_back(temp);
        return;
    }

    //down
    if(i+1<n && !visited[i+1][j] && maze[i+1][j] == 1){
        visited[i][j] = 1;
        solvePath(visited,maze,ans,temp+"D",n,i+1,j);
        visited[i][j] = 0;
    }

    //left
    if(j-1>=0 && !visited[i][j-1] && maze[i][j-1] == 1){
        visited[i][j] = 1;
        solvePath(visited,maze,ans,temp+"L",n,i,j-1);
        visited[i][j] = 0;
    }

    //right
    if(j+1<n && !visited[i][j+1] && maze[i][j+1] == 1){
        visited[i][j] = 1;
        solvePath(visited,maze,ans,temp+"R",n,i,j+1);
        visited[i][j] = 0;
    }

    //up
    if(i-1>=0 && !visited[i-1][j] && maze[i-1][j] == 1){
        visited[i][j] = 1;
        solvePath(visited,maze,ans,temp+"U",n,i-1,j);
        visited[i][j] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &maze, int n){
    vector<vector<int>> visited(n,vector<int> (n,0));
    vector<string> ans;
    if(maze[0][0] == 1){
        solvePath(visited,maze,ans,"",n,0,0);
    }
    return ans;
}


//We can optimise the check part by not checking every path and using a single loop

void solvePathOptimal(vector<vector<int>> &visited, vector<vector<int>> &maze, vector<string> &ans, string temp, int n, vector<int>&di, vector<int> &dj, int i, int j){
    //Lexiographically DLRU
    if(i == n-1 && j == n-1){
        ans.push_back(temp);
        return;
    }
    string dir = "DLRU";
    for(int ind = 0; ind<n; ind++){
        int nexti= i + di[ind];
        int nextj = j+dj[ind];
        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && maze[nexti][nextj] == 1 && !visited[nexti][nextj]){
            visited[i][j] = 1;
            solvePathOptimal(visited,maze,ans,temp+dir[ind],n,di,dj,nexti,nextj);
            visited[i][j] = 0;
        }
    }
}

vector<string> findPathOptimal(vector<vector<int>> &maze, int n){
    vector<vector<int>> visited(n,vector<int> (n,0));
    vector<string> ans;
    vector<int> di = {1,0,0,-1};
    vector<int> dj = {0,-1,1,0};
    //Following DLRU pattern
    if(maze[0][0] == 1){
        solvePathOptimal(visited,maze,ans,"",n,di,dj,0,0);
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze(n,vector<int> (n));
    for(auto &i:maze){
        for(auto &j:i)  cin>>j;
    }
    
    vector<string> ans = findPath(maze,n);

    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}