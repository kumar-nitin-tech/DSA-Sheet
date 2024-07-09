/*
    Find Median from Data Stream
    
    Problem Statement:  The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the 
                        two middle values.

    Problem Link:   https://leetcode.com/problems/find-median-from-data-stream/description/

    Refer:  Notes and code 

*/

#include<bits/stdc++.h>
using namespace std;

// TC: O(N Log N) -> for median 
class MedianFinderBrute{
    vector<int> arr;

    void addNum(int num){
        arr.push_back(num);
    }

    double findMedian(){
        sort(arr.begin(), arr.end());
        if(arr.size() %2 == 0){
            //even
            return (arr[arr.size()/2] + arr[(arr.size()/2)-1])/2.0;
        }else{
            return (double)arr[arr.size()/2];
        }
    }
};

//TC: O(log N)-> for pushing
//SC: O(N)

class MedianFinderOptimal{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    void addNum(int num){
        //we add smaller element in maxHeap and larger element in minHeap
        if(maxHeap.empty() || num<maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        //we balance the both heap to contain equal element or max heap should have 1 greater element 
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian(){
       if(maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top())/2.0;
       }else{
        return (double)maxHeap.top();
       }
    }
};

int main(){

    return 0;
}