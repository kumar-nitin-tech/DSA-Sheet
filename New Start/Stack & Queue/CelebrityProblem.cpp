/*
    
    Problem Statement:  A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat is 
                        used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

    Problem Link:   https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

    Refer:  https://www.youtube.com/watch?v=cEadsbTeze4

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O(N^2) + O(N)
//SC: O(2N)
int celebrityBrute(vector<vector<int>> &mat){
    int n = mat.size();
    vector<int> iKnow(n,0), knowMe(n,0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1){
                iKnow[i]++;
                knowMe[j]++;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(knowMe[i] == n-1 && iKnow[i] == 0){
            return i;
        }
    }
    return -1;
}

//Better
//TC: O(3N)
//SC: O(N)

int celebrityBetter(vector<vector<int>> &mat){
    
    int n = mat.size();
    if(n==1){
        return n-1;
    }
    stack<int> s;
    //O(N)
    for(int i=0; i<n; i++)
        s.push(i);

    //O(N)
    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(mat[a][b] == 1){
            s.push(b);
        }else{
            s.push(a);
        }
    }

    int ans = s.top();
    s.pop();
    //O(N)
    for(int i=0; i<n; i++){
        if(i==ans)  continue;
        if(mat[ans][i] != 0 || mat[i][ans] != 1){
            return -1;
        }
    }
    return ans;
}

//Optimal
//TC: O(N)
//SC: O(1)
int celebrityOptimal(vector<vector<int>> &mat){
    int n = mat.size();
    int top = 0, down = n-1;

    while(top<down){
        if(mat[top][down] == 1){
            top++;
        }
        else if(mat[down][top] == 1){
            down--;
        }else{
            top++;
            down--;
        }
        if(top>down){
            return -1;
        }
    }

    for(int i=0; i<n; i++){
        if(i==top)  continue;
        if(mat[top][i] != 0 || mat[i][top] != 1){
            return -1;
        }
    }
    return top;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(auto &i:mat){
        for(auto &j:i){
            cin>>j;
        }
    }
    cout<<celebrityOptimal(mat);
    return 0;
}