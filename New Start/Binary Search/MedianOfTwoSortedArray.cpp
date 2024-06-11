/*
    Median of Two Sorted Arrays of different sizes

    Problem Statement:   Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle 
                        value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

    Problem Link:   https://leetcode.com/problems/median-of-two-sorted-arrays/description/

    Refer:  https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:   O((N+M)
//SC:   O(N+M)
double findMedianSortedArraysBrute(vector<int> &nums1, vector<int> &nums2){
    int n = nums1.size(), m = nums2.size();
    vector<int> arr;
    int left = 0, right = 0;
    while(left<n && right<m){
        if(nums1[left] < nums2[right]){
            arr.push_back(nums1[left]);
            left++;
        }
        arr.push_back(nums2[right]);
        right++;
    }

    while(left<n){
        arr.push_back(nums1[left]);
        left++;
    }
    while(right<m){
        arr.push_back(nums2[right]);
        right++;
    }

    int mid = arr.size()/2;
    if(arr.size()%2 == 0){
        return (arr[mid] + arr[mid-1])/2.00;
    }else{
        return arr[mid];
    }
}

//Better Approach
//TC:   O(N+M)
//SC:   O(1)
double findMedianSortedArraysBetter(vector<int> &nums1, vector<int> &nums2){
    int n = nums1.size(), m = nums2.size();
    int ele1 = -1, ele2 = -1, countEle1 = (n+m)/2, countEle2 = countEle1-1;
    int cnt = 0;
    int left = 0, right = 0;
    while(left<n && right<m){
        if(nums1[left] < nums2[right]){
            if(countEle1 == cnt){
                ele1 = nums1[left];
            }
            if(countEle2 == cnt){
                ele2 = nums1[left];
            }
            cnt++;
            left++;
        }else{
            if(countEle1 == cnt){
                ele1 = nums2[right];
            }
            if(countEle2 == cnt){
                ele2 = nums2[right];
            }
            cnt++;
            right++;
        }
    }

    while(left<n){
        if(countEle1 == cnt){
            ele1 = nums1[left];
        }
        if(countEle2 == cnt){
            ele2 = nums1[left];
        }
        cnt++;
        left++;
    }
    while(right<m){
        if(countEle1 == cnt){
            ele1 = nums2[right];
        }
        if(countEle2 == cnt){
            ele2 = nums2[right];
        }
        cnt++;
        right++;
    }
    //even
    if((n+m) %2 == 0){
        return (ele1+ele2)/2.0;  
    }else{
        return (double)ele1;
    }
}

//Optimal Approach
//TC:
//SC:
double findMedianSortedArraysOptimal(vector<int> &nums1, vector<int> &nums2){
    int n1 = nums1.size(), n2 = nums2.size();
    if(n1 > n2){
        return findMedianSortedArraysOptimal(nums2,nums1);
    }
    int low = 0, high = n1;
    int n = n1+n2;
    int left = (n1+n2+1)/2;
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1<n1) r1 = nums1[mid1];
        if(mid2<n2) r2 = nums2[mid2];
        if(mid1-1 >= 0) l1 = nums1[mid1-1];
        if(mid2-1 >= 0) l2 = nums2[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n%2 == 0){
                return (double)(max(l1,l2) + min(r1,r2))/2.0;
            }else{
                return max(l1,l2);
            }
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
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n), nums2(m);
    for(auto &i:nums1)  cin>>i;
    for(auto &i:nums2)  cin>>i;
    cout<<findMedianSortedArraysOptimal(nums1, nums2);
    return 0;
} 