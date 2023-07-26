/*
    Merge Sorted Arrays Without Extra Space

    Problem Statement:  Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. 
                        Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

    Problem Link:   https://leetcode.com/problems/merge-sorted-array/
                    https://www.codingninjas.com/studio/problems/merge-two-sorted-arrays-without-extra-space_6898839

    Refer:  https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
            https://www.youtube.com/watch?v=n7uwj04E0I4
*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//Time Complexity: O(N)
//Space Complexity: O(N) // which is against the constraint but it is a solution 
void mergeSortArrayB(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size(), m = arr2.size();
    vector<int> ans(n+m);

    int left = 0, right = 0, j=0;
    while(left<n && right<m){
        if(arr1[left] <= arr2[right]){
            ans[j] = arr1[left];
            j++;left++;
        }
        else {
            ans[j] = arr2[right];
            j++; right++;
        }  
    }
    while(left<n){
         ans[j++] = arr1[left++];
    }
    while(right<m){
        ans[j++] = arr2[right++];
    }
    
    for(int i=0;i<n+m;i++){
        if(i<n) arr1[i] = ans[i];
        else    arr2[i-n] = ans[i];
    }
}

//Optimal Approach 1
//Time Complexity: O(N) + O(n log n) + O(m logm)
void mergeSortedArray1(vector<int> &arr1, vector<int> &arr2){
    //We have to arrange the both array such that it has smaller element in arr1 and greater element in arr2
    //for that we take two pointer one at end of arr1 as it contain greatest element in arr1 as it is sorted
    //and secong iterator on first index of arr2

    int left = arr1.size()-1, right = 0;

    while(left>= 0 && right<arr2.size()){
        if(arr2[right] < arr1[left]){
            swap(arr1[left], arr2[right]);
            left--; right++;
        }
        //If any condition is not true which means that all other element are in place
        else    break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

//Gap Method

void swapGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2){
    if(arr1[ind1] > arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}

void mergeSortedArrayGap(vector<int> &arr1, vector<int> &arr2){
    //In gap mehtod is  based on shell sort 
    // In this we find the gap between the two len of the of the array and try to sort the array we each reduction of gap
    //Gap value if the seal value of the total len of both array divided by 2
    int n = arr1.size(), m = arr2.size();
    //Modulo with 2 to get the seal value
    int gap = ((n+m)/2) + ((n+m)%2);

    while(gap > 0){
        //we have to place right iterator to gap 
        int left = 0, right = left+gap;
        while(right < (n+m)){
            //if left is in arr1 and right in arr2
            if(left<n && right >= n){
                swapGreater(arr1,arr2,left, right-n);
            }
            //if left and right are both in arr2
            else if(left>=n){
                swapGreater(arr2,arr2,left-n, right-n);
            }
            //if left and right both are in arr1
            else{
                swapGreater(arr1,arr1,left, right);
            }
            left++; right++;
        }
        if(gap == 1)    break;
        gap = (gap/2) + (gap%2);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n), arr2(m);

    for(auto &i:arr1)    cin>>i;
    for(auto &i:arr2)    cin>>i;

    mergeSortedArrayGap(arr1,arr2);

    for(auto i:arr1)    cout<<i<<" ";
    for(auto i:arr2)    cout<<i<<" ";

    return 0;
}

