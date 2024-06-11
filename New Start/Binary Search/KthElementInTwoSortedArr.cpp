/*
    K-th Element of two sorted arrays

    Problem Statement:  Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

    Problem Link:   https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

    Refer:  https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O(N+M)
//SC:   O(N+M)
int kthElementBrute(vector<int> &arr1, vector<int> &arr2, int n, int m, int k){
    vector<int> arr;
    int left = 0, right = 0;
    while(left<n && right<m){
        if(arr1[left] < arr2[right]){
            arr.push_back(arr1[left]);
            left++;
        }else{
            arr.push_back(arr2[right]);
            right++;
        }
    }

    while(left<n){
        arr.push_back(arr1[left]);
        left++;
    }
    while(right<m){
        arr.push_back(arr2[right]);
        right++;
    }
    return arr[k-1];
}

//Better Approach
//TC:   O(N+M)
//SC:   O(1)
int kthElementBetter(vector<int> &arr1, vector<int> &arr2, int n, int m, int k){
    k = k-1;
    int ans = -1;
    int cnt = 0;
    int left = 0, right = 0;
    while(left<n && right<m){
        if(arr1[left] < arr2[right]){
            if(cnt == k){
                ans = arr1[left];
            }
            cnt++;
            left++;
        }else{
            if(cnt == k){
                ans = arr2[right];
            }
            cnt++;
            right++;
        }
    }

    while(left<n){
        if(cnt == k){
            ans = arr1[left];
        }
        cnt++;
        left++;
    }
    while(right<m){
        if(cnt == k){
            ans = arr2[right];
        }
        cnt++;
        right++;
    }
    return ans;
}

//Optimal Approach
//TC:   O(min(logM, logN))
//SC:   O(1)
int kthElementOptimal(vector<int> &arr1, vector<int> &arr2, int n, int m, int k){
    if(n > m){
        return kthElementOptimal(arr2,arr1,m,n,k);
    }
    int low = max(0,k-m), high = min(k,n);
    int left = k;
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1<n) r1 = arr1[mid1];
        if(mid2<m) r2 = arr2[mid2];
        if(mid1-1 >= 0) l1 = arr1[mid1-1];
        if(mid2-1 >= 0) l2 = arr2[mid2-1];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        if(l2>r1){
            low = mid1+1;
        }else{
            high = mid1-1;
        }
    }
    return 0;
}


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr1(n), arr2(m);
    for(auto &i:arr1)   cin>>i;
    for(auto &i:arr2)   cin>>i;

    cout<<kthElementOptimal(arr1,arr2,n,m,k);
    return 0;
}