/*
    Missing and repeating numbers

    Problem Statement:  You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer 
                        appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

    Problem Link:   https://www.codingninjas.com/studio/problems/873366?topList=striver-sde-sheet-problems
                    https://www.interviewbit.com/problems/repeat-and-missing-number-array/

    Refer:  https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
            https://www.youtube.com/watch?v=2D0D8HE6uak

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//Brute Force based on sorting
//TC: O(n log n) + O(n) + O(n)
//SC: O(1)
vector<int> findRepAndMiss(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int rep = -1;
    int missing = -1;
    for(int i=1; i<arr.size(); i++){
        if(arr[i] == arr[i-1]){
            rep = arr[i];
            break;
        }
    }

    for(int i=1; i<=arr.size(); i++){
        if(arr[i-1] != i){
            missing = i;
            break;
        }
    }
    vector<int> ans;
    ans.push_back(rep);
    ans.push_back(missing);
    return ans;
}

//Brute Force with count array
//TC:
//SC:
vector<int> findRepAndMissC(vector<int> &arr){
    vector<int> count(arr.size()+1);
    vector<int> ans;
    int rep = -1, missing = -1;

    for(auto &i:arr){
        count[i]++;
    }

    for(int i=1; i<count.size(); i++){
        if(count[i] == 2)   rep = i;
        if(count[i] == 0)   missing = i;
    }
    ans.push_back(rep);
    ans.push_back(missing);
    return ans;
}

//Using map and not sorting the arr
//TC: O(n) + O(n)
//SC:   O(n)
vector<int> findRepAndMissM(vector<int> &arr){
    unordered_map<int,int> map;
    int rep = -1, missing = -1;
    for(int i=0; i<arr.size(); i++){
        map[arr[i]]++;
    }

    for(int i=1; i<arr.size()+1; i++){
        if(map[i] == 2){
            rep = i;
        }
        if(map[i] == 0){
            missing = i;
        }
    }
    vector<int> ans;
    ans.push_back(rep);
    ans.push_back(missing);
    return ans;
}

//Optimal Solution using maths
//TC: O(n)
//Sc: O(1)
vector<int> findRepAndMissOM(vector<int> &arr){
    //we use long long as we add square and arr element so they don't overflow int type
    ll n = arr.size();
    ll sn = (n*(n+1))/2;
    ll s2n = (n * (n+1) * (2*n+1))/6;
    ll s = 0, s2 = 0;
    for(int i=0; i<n; i++){
        s += arr[i];
        s2 += (ll) arr[i] * (ll)arr[i];
    }
    // value of s-sn
    ll val1 = s-sn; // x-y = val1
    //value of s2 - s2n
    ll val2 = s2-s2n; // x2-y2 = val2
    //x+y = (val2)/(x-y)
    val2 = val2/val1;

    //x = (val1+val2)/2;
    ll x = (val1+val2)/2;
    //y = val2 - x;
    ll y = val2 - x;
    return {(int)x, (int)y};
}

//Optimal Solution using XOR
//TC: O()
//SC: O(1)
vector<int> findRepAndMissOX(vector<int> &arr){
    int n = arr.size();
    //xor all the element in array and number from 1 to n
    int xr = 0;
    for(int i=0; i<n; i++){
        xr ^= arr[i];
        xr ^= (i+1);
    }
    //find bit no.
    //This is used to understand intituion for finding bit number and should tell in interview
    // int bitNo = 0;
    // while(1){
    //     if((1<<bitNo)&1){
    //         break;
    //     }
    //     bitNo++;
    // }
    //another method to find bit no. to avoid looping 
    //We & value with 2's complement of the value itself
    int num = xr & ~(xr-1);
    int oneth = 0, zeroth = 0;
    //Now we are find zeroth club and 1th club memeber in the array
    for(int i=0; i<n; i++){
        if(arr[i]&num){
            oneth ^= arr[i];
        }
        else{
            zeroth ^= arr[i];
        }
        if(i+1&num){
            oneth ^= i+1;
        }
        else{
            zeroth ^= i+1;
        }
    }

    //iterate over array and find the repeating or missing element
    int count = 0;
    for(auto &it: arr){
        if(oneth == it){
            count++;
        }
    }
    if(count != 0)  return {oneth,zeroth};
    else{
        return {zeroth,oneth};
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;
    vector<int> ans = findRepAndMissOX(arr);
    for(auto &i: ans){
        cout<<i<<" ";
    }
    return 0;
}