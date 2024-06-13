/*
    Allocate Minimum Number of Pages
  
    Problem Statement:  Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is 
                        to allocate all the books to the students.
                        Allocate books in such a way that:

                        -> Each student gets at least one book.
                        -> Each book should be allocated to only one student.
                        -> Book allocation should be in a contiguous manner.
                        You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1  

    Problem Link:   https://www.interviewbit.com/problems/allocate-books/   

    Refer:  https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/

*/

#include<bits/stdc++.h>
using namespace std;

int countStudent(vector<int> &arr, int pages){
    int student = 1;
    long long pagesStd = 0;
    for(int i=0; i<arr.size(); i++){
        if(pagesStd + arr[i] <= pages){
            pagesStd += arr[i];
        }else{
            student++;
            pagesStd = arr[i];
        }
    }
    return student;
}

//Brute Force -> We do linear search for the range that minimum pages allocated to student to maxium pages allocated to student
//TC: O((N * (sum(arr[])-max(arr[])+1))
//SC: O(1)
int books(vector<int> &arr, int m){
    int n = arr.size();
    if(m>n) return -1;

    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);

    for(int i=low; i<=high; i++){
        if(countStudent(arr,i) == m){
            return i;
        }
    }
    return low;
}


//Optimal Approach
//TC: O(N log(sum(arr[])-max(arr[])+1)) 
//SC: O(1)
//Using Binary Search
int booksOptimal(vector<int> &arr, int m){
    int n = arr.size();
    if(m>n) return -1;

    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);

    while(low<=high){
        int mid = (low + high)/2;
        int student = countStudent(arr,mid);
        if(student > m){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    cout<<booksOptimal(arr,m);
    return 0;
}