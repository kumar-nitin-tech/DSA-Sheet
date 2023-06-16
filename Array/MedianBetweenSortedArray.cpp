/*
    Median of Two Sorted Arrays

    Problem Statement:  Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
                        The overall run time complexity should be O(log (m+n)).

    Problem Link :  https://leetcode.com/problems/median-of-two-sorted-arrays/
                    https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_8230788?challengeSlug=striver-sde-challenge
*/

#include<bits/stdc++.h>
using namespace std;

//This would wotk if we given a unsorted array and we have find median of final soretd array
//Tc: O(log(m+n))
double median(vector<int> &a, vector<int> &b){
    int startA = 0, startB = 0;
    vector<int> temp;
    double ans = 0.00;
    while(startA<a.size() && startB<b.size()){
        if(a[startA] > b[startB]){
            temp.push_back(b[startB]);
            startB++;
        }
        else{
            temp.push_back(a[startA]);
            startA++;
        }
    }
    while(startA<a.size()){
        temp.push_back(a[startA]);
        startA++;
    }
    while(startB<b.size()){
        temp.push_back(b[startB]);
        startB++;
    }

    int mid = (temp.size()-1)/2;
    if((a.size() + b.size()) % 2 == 0){
        ans = (temp[mid] + temp[mid+1])/2.00;
    }
    else{
        ans = temp[mid];
    }
    return ans;
}

//Here we have given that array is sorted so we apply binary search algorithm 
//TC: O(log(min(n,m)))
double findMedian(vector<int> &a, vector<int> &b){
    int n1 = a.size(), n2 = b.size();
    if(n1>n2){
        return findMedian(b,a);
    } 
    int low = 0 , high = n1;
    while(low<=high){
        int cut1 = (low+high) >> 1;
        int cut2 =  (n1+n2+1)/2 - cut1;

        int left1 = cut1 == 0 ?INT_MIN : a[cut1-1];// because high is at n
        int left2 = cut2 == 0 ?INT_MIN : b[cut2-1];

        int right1 = cut1 == n1 ?INT_MAX : a[cut1];
        int right2 = cut2 == n2 ?INT_MAX : b[cut2];

        if(left1 <= right2 && left2 <= right1){
            if((n1+n2) %2 == 0){
                return (max(left1,left2) + min(right1,right2))/2.0;
            }
            else    
                return max(left1,left2);
        }
        else if(left1 > right2){
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
    }
    return 0.00;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(auto &i:a){
        cin>>i;
    }
    for(auto &i:b){
        cin>>i;
    }
    cout<<findMedian(a,b);
    return 0;
}