/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach 
//The Solution given tle for large input
int maxProfit(vector<int>& prices) {
    if(prices.size() == 1){
        return 0;
    }
    int maxi = INT_MIN;
    for(int i=0;i<prices.size();i++){
        for(int j=i+1;j<prices.size();j++){
            maxi = max(maxi, prices[j]-prices[i]);
        }
    }
    if(maxi == -1){
        return 0;
    }
    else
        return maxi;
}

//Optimized 
int maxProfitOp(vector<int> &prices){
    if(prices.size() == 1) return 0;
    int minPrice = prices[0];
    int profit = 0, maxProfit = INT_MIN;
    for(int i=1;i<prices.size();i++){
        minPrice = min(minPrice, prices[i]);
        profit = prices[i] - minPrice;
        maxProfit = max(maxProfit,profit);
    }
    return maxProfit;
}


int main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(auto &i:prices){
        cin>>i;
    }
    cout<<maxProfitOp(prices);
    return 0;
}