/*
    Find the Majority Element that occurs more than N/2 times

    Problem Statement:  Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given 
                        array. You may consider that such an element always exists in the array.

    Problem Link:   https://leetcode.com/problems/majority-element/
                    https://www.codingninjas.com/studio/problems/majority-element_6783241

    Refer:  https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
            https://www.youtube.com/watch?v=nP_ns3uSh80
*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force 
//TC:   O(n^2)
//SC:   O(1)
int majorityElementB(int n, vector<int> &arr){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
            if(count>n/2){
                return arr[j];
            }
        }
        count = 0;
    }
    return -1;
}

//Better Approach (Using Hashmap)
//TC:   O(n)
//SC:   O(n)
int majorityElementBetter(int n, vector<int> &arr){
    unordered_map<int,int> map;
    for(auto &i:arr){
        map[i]++;
    }

    for(auto i:map){
        if(i.second > n/2){
            return i.first;
        }
    }
    return -1;
}

//Optimal Approach
//TC:   O(2n)
//SC:   O(1)
int majorityElementO(int n, vector<int> &arr){
    //Moore's voting Algorithm
    int count = 0;
    int ele;
    for(int i=0; i<n; i++){
        if(count == 0){
            ele = arr[i];
            count = 1;
        }
        else if(arr[i] == ele){
            count++;
        }else{
            count--;
        }
    }
    int count1=  0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele)   count1++;
    }
    if(count1 > n/2){
        return ele;
    }else{
        return -1;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<majorityElementB(n,arr);
    return 0;
}