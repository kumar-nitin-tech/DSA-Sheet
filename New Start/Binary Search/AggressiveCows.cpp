/*
    Aggressive Cows

    Problem Statement:  You are given an array 'arr' of size 'n' which denotes the position of stalls. You are also given an integer 'k' which denotes the number of aggressive 
                        cows. You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible. Find the maximum possible minimum distance.  

    Problem Link:   https://www.spoj.com/problems/AGGRCOW/
                    https://www.naukri.com/code360/problems/aggressive-cows_1082559

    Refer:  https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/

*/

#include<bits/stdc++.h>
using namespace std;

//Helper function
bool canWePlaceCow(vector<int> &arr, int minDist, int k){
    int n = arr.size();
    int cntCows = 1, last = arr[0];
    for(int i=1; i<n; i++){
        if((arr[i] - last) >= minDist){
            cntCows ++;
            last = arr[i];
        }
        if(cntCows >= k){
            return true;
        }
    }
    return false;
}

//Brute force: We define the search space which is from 1 to (max-min) and linearly search can we place k cows in with minimum distance or not
//TC: O(n* (max-min))
//SC: O(1)
int aggressiveCowBrute(vector<int> &arr, int k){
    int n = arr.size();
    //O(N log N)
    sort(arr.begin(), arr.end());
    int maxRange = arr[n-1] - arr[0];
    
    //loop for the anse
    //O(max - min)
    for(int i=1; i<=maxRange; i++){
        //O(N)
        if(canWePlaceCow(arr,i,k)){
            continue;
        }else{
            return i-1;
        }
    }
    return maxRange;
}

//Optimal: We define the search space which is from 1 to (max-min) and linearly search can we place k cows in with minimum distance or not
//TC: O(N* log(max-min))
//SC: O(1)
int aggressiveCowOptimal(vector<int> &arr, int k){
    int n = arr.size();
    //O(N log N)
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[n-1] - arr[0];
    
    //O(log(max-min))
    while(low<= high){
        int mid = (low+high)/2;
        //o(N)
        if(canWePlaceCow(arr,mid,k)){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    return high;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;

    cout<<aggressiveCowOptimal(arr,k);
    return 0;
}