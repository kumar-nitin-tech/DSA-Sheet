/*
     Word Break II
   
    Problem Statement:  You are given a non-empty string S containing no spaces’ and a dictionary of non-empty strings (say the list of words). You are supposed to construct 
                        and return all possible sentences after adding spaces in the originally given string ‘S’, such that each word in a sentence exists in the given dictionary.
                        Note :
                        The same word in the dictionary can be used multiple times to make sentences.
                        Assume that the dictionary does not contain duplicate words.  

    Problem Link:   https://www.naukri.com/code360/problems/983635?topList=striver-sde-sheet-problems

    Refer:  

*/

#include<bits/stdc++.h>
using namespace std;

//TC : O(N^N)
//SC: O(N)
//Recursive approach

void wordBreakHelper(vector<string> &ans, unordered_multiset<string> &wordDict, string &s, string temp){
    if(s.size() == 0){
        ans.push_back(temp);
    }

    for(int i=0; i<s.size(); i++){
        string left = s.substr(0,i+1);
        if(wordDict.find(left) != wordDict.end()){
            string right = s.substr(i+1);
            wordBreakHelper(ans,wordDict,right,temp + left + " ");
        }
    }
}

vector<string> wordBreak(vector<string> &dict, string &s){
    unordered_multiset<string> wordDict;
    for(auto i:dict){
        wordDict.insert(i);
    }
    vector<string> ans;
    wordBreakHelper(ans,wordDict,s,"");
    return ans;
}

int main(){
    int n;
    cin>>n;
    string s;
    vector<string> dict(n);
    for(auto &i:dict){
        cin>>i;
    }
    cin>>s;

    vector<string> ans = wordBreak(dict,s);
    for(auto i:ans) cout<<i<<" "<<endl;

    return 0;
}