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

struct item{
    int value;
    int weight;
};

static bool cmp(pair<double,item> a, pair<double,item> b){
    return a.first > b.first;
}

double fractionalKnapsack(int N, int W, vector<item>arr){
    vector<pair<double, item>> indiviualArray;
    for(int i=0;i<N;i++){
        double indivualValue = 1.0*(arr[i].value) / arr[i].weight;
        indiviualArray.push_back({indivualValue,arr[i]});
    }

    sort(indiviualArray.begin(), indiviualArray.end(), cmp);

    double ans = 0;

    for(int i=0;i<N;i++){
        if(indiviualArray[i].second.weight > W){
            ans += W*indiviualArray[i].first;
            W = 0;
        }
        else{
            ans += indiviualArray[i].second.value;
            W -= indiviualArray[i].second.weight;
        }
    }
    return ans;
}

int main(){
    int N,W;
    cin>>N>>W;
    vector<item> arr(N);
    for(auto &i:arr){
        cin>>i.value>>i.weight;
    }
    cout<<fractionalKnapsack(N,W,arr);
    return 0;
}