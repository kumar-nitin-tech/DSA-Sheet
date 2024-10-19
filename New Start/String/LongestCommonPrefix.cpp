/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    int n = strs.size();
    for(int i=1; i<n; i++){
        string st = strs[i];
        int j = 0;
        int minSize = min(st.size(), prefix.size());
        while (st[j] == prefix[j] && j<minSize) {
                j++;
        }
        prefix = st.substr(0,j);
    }     
    if(prefix.size() == 0){
        return "";
    }   
    return prefix;
}

int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(auto &i:strs)   cin>>i;
    cout<<longestCommonPrefix(strs);
    return 0;
}