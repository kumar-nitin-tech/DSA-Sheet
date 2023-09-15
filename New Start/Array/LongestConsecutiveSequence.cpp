/*
    Longest Consecutive Sequence

    Problem Statement:  Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.  

    Problem Link:   https://leetcode.com/problems/longest-consecutive-sequence/
                    https://www.codingninjas.com/studio/problems/759408?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/

*/

#include<bits/stdc++.h>
using namespace std;

bool searchElement(int x, vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == x) return true;
    }
    return false;
}
//Brute Force
//TC:   O(n^2)
//SC:   O(1)
int longestConsecutiveSequenceBrute(vector<int> &arr){
    int longestSeq = 1;
    for(int i=0; i<arr.size(); i++){
        int x = arr[i];
        int count = 1;
        while(searchElement(x+1,arr)){
            x = x+1;
            count++;
        }
        longestSeq = max(longestSeq,count);
    }
    return longestSeq;
}

//Better Approach
//TC:   O(N log N) + O(N)
//SC:   O(1)
int longestConsecutiveSequenceBetter(vector<int> &arr){
    //sort the array
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int longestSeq = 1;
    int count = 1;
    for(int i=1; i<n; i++){
        if(arr[i-1] == arr[i]-1)    count++;
        else if (arr[i] == arr[i-1])    continue;
        else    count = 1;
        longestSeq = max(longestSeq,count);
    }
    return longestSeq;
}

//Optimal Approach
// Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
// Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the      consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).
// Space Complexity: O(N), as we are using the set data structure to solve this problem.
// Note: The time complexity is computed under the assumption that we are using unordered_set and it is taking O(1) for the set operations. 
// If we consider the worst case the set operations will take O(N) in that case and the total time complexity will be approximately O(N2). 
// And if we use the set instead of unordered_set, the time complexity for the set operations will be O(logN) and the total time complexity will be O(NlogN).
int longestConsecutiveSequenceOptimal(vector<int> &arr){
    unordered_set<int> st;
    for(auto i:arr) st.insert(i);
    int longestSeq = 1;
    for(auto &i:st){
        //For finding the starting point
        if(st.find(i-1) == st.end()){
            int count = 1;
            int x = i;
            while(st.find(x+1) != st.end()){
                count ++;
                x++;
            }
            longestSeq = max(longestSeq,count);
        }
    }
    return longestSeq;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<longestConsecutiveSequenceOptimal(arr);
    return 0;
}