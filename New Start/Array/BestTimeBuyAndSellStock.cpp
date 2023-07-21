/*
    Stock Buy and Sell

    Problem Statement:  We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following 
                        guidelines need to be followed:
                            We can buy and sell a stock only once.
                            We can buy and sell the stock on any day but to sell the stock, we need to first buy it on the same or any previous day.
                        We need to tell the maximum profit one can get by buying and selling this stock.

    Problem Link:   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
                    https://www.codingninjas.com/studio/problems/893405?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/stock-buy-and-sell-dp-35/
            https://www.youtube.com/watch?v=excAOvwF_Wk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=36
*/

#include<bits/stdc++.h>
using namespace std;

//Brute Approach we use nested 2 loops to buy at every day and sell it at every day 
//TC: O(n2)

//Optimal Approach
//TC: O(N)
int maxiProfit(vector<int> &arr){
    int mini = arr[0], maxi = 0;
    for(int i=1;i<arr.size();i++){
        int profit = arr[i] - mini;
        mini = min(mini, arr[i]);
        maxi = max(maxi,profit);
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;

    cout<<maxiProfit(arr);
    return 0;
}