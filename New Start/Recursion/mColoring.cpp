/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//TC: O(N^M)
//SC: O(N)

bool isSafe(vector<vector<bool>> &graph, vector<int> &color, int col, int n, int node){
    for(int i=0; i<n; i++){
        if(i != node && graph[i][node] == 1 && color[i] == col){
            return false;
        }
    }
    return true;
}

bool solveGraph(vector<vector<bool>> &graph, vector<int> &color, int node, int N, int m){
    if(node == N){
        return true;
    }

    for(int i=1; i<=m; i++){
        if(isSafe(graph,color,i,N,node)){
            color[node] = i;
            if(solveGraph(graph,color,node+1,N,m)){
                return true;
            }else{
                color[node] = 0;
            }
        }
    }
    return false;
}

bool graphColoring(vector<vector<bool>> &graph, int N, int m){
    vector<int> color(N,0);
    return solveGraph(graph,color,0,N,m);
}

int main(){
    int n,e,m;
    cin>>n>>m>>e;
    vector<vector<int>> edges(e,vector<int> (2));
    for(auto &i:edges){
        for(auto &j:i){
            cin>>j;
        }
    }
    vector<vector<bool>>graph(101, vector<bool> (101,0));

    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0]][edges[i][1]] = 1;
    }

    cout<<graphColoring(graph,n,m);
    return 0;
}