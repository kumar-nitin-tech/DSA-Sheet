/*
    
    Problem Statement:  

    Problem Link:   https://leetcode.com/problems/online-stock-span/description/

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//TC: O(N)
//SC: O(N)

class StockSpanner{
    stack<pair<int,int>> st;
    public:

    int next(int price){
        if(st.empty()){
            st.push({price,1});
            return 1;
        }
        int cnt = 1;
        while(!st.empty() && price >=st.top().first){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt});
        return st.top().second;
    }

};

int main(){
    return 0;
}