/*
    Count Reverse Pairs
   
    Problem Statement:  Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

    Problem Link:   https://leetcode.com/problems/reverse-pairs/
                    https://www.codingninjas.com/studio/problems/1112652?topList=striver-sde-sheet-problems

    Refer:  https://takeuforward.org/data-structure/count-reverse-pairs/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O(n2)
//SC: O(1)
int countReversePairBrute(vector<int> &arr){
    int count = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > 2*arr[j]){
                count++;
            }
        }
    }
    return count;
}

//Optimal Approach
//TC: O(N logN)
//SC: O(N)

void mergeArray(int i, int j, int mid, vector<int> &arr){
    int l = i, r= mid+1;
    vector<int> temp;
    while(l<=mid && r<=j){
        if(arr[l] <= arr[r]){
            temp.push_back(arr[l]);
            l++;
        }else{
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=j){
        temp.push_back(arr[r]);
        r++;
    }

    for(int k=i; k<=j; k++){
        arr[k] = temp[k-i];
    }
}

int countPairs(int i, int j, int mid, vector<int> &arr){
    //Here we count the how many pairs we can form using two sorted array
    int r = mid+1, count = 0;
    for(int l=i; l<=mid; l++){
        while(r<=j && arr[l] > 2*arr[r]){
            r++;
        }
        count += r-(mid+1);
    }
    return count;
}

int mergeSort(int i, int j, vector<int> &arr){
    if(i>=j)    return 0;
    int count = 0;
    int mid = (i+j)/2;
    count += mergeSort(i,mid,arr);//left part
    count += mergeSort(mid+1, j, arr);//right part
    count += countPairs(i,j,mid,arr);
    mergeArray(i,j,mid,arr);
    return count;
}

int countReversePairOptimal(vector<int> &arr){
    return mergeSort(0,arr.size()-1,arr);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<countReversePairOptimal(arr);
    return 0;
}