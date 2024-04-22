/*
    Find K-th Permutation Sequence   
    Problem Statement:  Given N and K, where N is the sequence of numbers from 1 to N([1,2,3..... N]) find the Kth permutation sequence.

    Problem Link:   https://leetcode.com/problems/permutation-sequence/description/
                    https://www.naukri.com/code360/problems/1112626?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/find-k-th-permutation-sequence/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force -> Generate all permutation and sort the permutation and return the kth permutation
//TC: O(N!)
//SC: O(N)
//generate all permutation
void generatePermutation(vector<string> &permutation, string temp, string &s){
    if(s.size() == 0){
        permutation.push_back(temp);
        return;
    }

    for(int i=0; i<s.size(); i++){
        char ch = s[i];
        string rest = s.substr(0,i) + s.substr(i+1);
        generatePermutation(permutation,temp+ch, rest);
    }
}

string KthPermutationBrute(int n, int k){
    string s = to_string(n);
    vector<string> permutation;
    generatePermutation(permutation,"",s);
    sort(permutation.begin(), permutation.end());
    return permutation[k-1];
}

//Optimal Approach -> We use the mathematical approach
//TC:   O(N^2)
//SC:   O(N)
string KthPermutationOptimal(int &n, int &k){
    int fact = 1;
    vector<int> num;
    for(int i=1; i<n; i++){
        num.push_back(i);
        fact = fact*i;
    }
    num.push_back(n);
    string ans = "";
    k = k-1;
    while(true){
        ans += to_string(num[k/fact]);
        num.erase(num.begin()+k/fact);
        if(num.size() == 0) break;
         k = k%fact;
        fact = fact/num.size();
    }
    return ans;
}


int main(){
    int n,k;
    cin>>n>>k;
    cout<<KthPermutationOptimal(n,k);
    return 0;
}