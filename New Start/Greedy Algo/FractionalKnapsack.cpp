/*
    Fractional Knapsack Problem

    Problem Statement:  The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained 
                        is maximized.  

    Problem Link:   https://www.codingninjas.com/studio/problems/fractional-knapsack_975286
                    https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

    Refer:  https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/

*/

#include<bits/stdc++.h>
using namespace std;

//Optimal Approach
//TC:
//SC:
double fractionalKnapsack(vector<pair<int,int>> &items, int n, int w){

}

int main(){
    int n,w;
    cin>>n>>w;
    vector<pair<int,int>> items(n);
    for(auto &i:items)  cin>>i.first>>i.second;
    return 0;
}