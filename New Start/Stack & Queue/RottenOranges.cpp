/*
    Rotting Oranges

    Problem Statement:  You are given an m x n grid where each cell can have one of three values:

                        0 representing an empty cell,
                        1 representing a fresh orange, or
                        2 representing a rotten orange.
                        Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

                        Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    Problem Link:   https://leetcode.com/problems/rotting-oranges/description/

    Refer:  https://takeuforward.org/data-structure/rotten-oranges-min-time-to-rot-all-oranges-bfs/

*/

#include<bits/stdc++.h>
using namespace std;


int orangeRotting(vector<vector<int>> & grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    int cnt = 0, total = 0, ans =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] != 0) total++;
            if(grid[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    int row[] = {0,0,1,-1};
    int col[] = {1,-1,0,0};
    while(!q.empty()){
        int k = q.size();
        cnt+=k;
        while(k--){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x+row[i], ny = y+col[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
        if(!q.empty()){
            ans++;
        }
    }
    return total == cnt?ans:-1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(auto &i:grid){
        for(auto &j:i){
            cin>>j;
        }
    }
    cout<<orangeRotting(grid);
    return 0;
}