/*
    
    Problem Statement:  

    Problem Link:

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//Brute Force Approach
//TC:   O(n^4)
//SC:   O(2*n)
vector<vector<int>> FourSumB(vector<int> &arr, int target){
    //Approach is simple we use four nested loop to check all possible quadralets in array
    int n = arr.size();
    set<vector<int>> distinctEle;
    for(int a=0; a<n; a++){
        for(int b=a+1; b<n; b++){
            for(int c=b+1; c<n; c++){
                for(int d=c+1; d<n; d++){
                    ll sum = arr[a] + arr[b] + arr[c] + arr[d];
                    if(sum == target){
                        vector<int> temp = {arr[a],arr[b],arr[c],arr[d]};
                        sort(temp.begin(),temp.end());
                        distinctEle.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(distinctEle.begin(), distinctEle.end());
    return ans;
}

//Better Approach 
//TC:   O(N^3)
//SC:   O(N)
vector<vector<int>> FourSumBetter(vector<int> &arr, int target){
    //We find the 3 value from loops and last value from hashmap
    set<vector<int>> st;
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<int> mp;
            for(int k=j+1; k<n; k++){
                ll neededValue = target - (arr[i] + arr[j] + arr[k]);
                if(mp.find(neededValue) != mp.end()){
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)neededValue};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                mp.insert(arr[k]); 
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Optimal Approach (Two Pointers)
//TC:   O(N^3)
//SC:   O(1)
vector<vector<int>> FourSumO(vector<int> &arr, int target){
    //We fix 2 value and find 3rd and 4th value using two pointer approach
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1]){
            continue;
        }
        for(int j=i+1; j<n; j++){
            if(j>i+1 && arr[j] == arr[j-1])  continue;

            int low = j+1, high = n-1;
            while(low<high){
                ll sum = arr[i];
                sum += arr[j];
                sum += arr[low];
                sum += arr[high];
                if(sum == target){
                    vector<int> temp = {arr[i],arr[j],arr[low],arr[high]};
                    ans.push_back(temp);
                    low++;
                    high--;
                    //we will skip the duplicates 
                    while(low<high && arr[low] == arr[low-1])    low++;
                    while(low<high && arr[high] == arr[high+1])    high--;
                }
                else if(sum > target)   high--;
                else    low++;
            }
        }
    }
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(auto &i:arr)    cin>>i;

    vector<vector<int>> ans = FourSumO(arr,target);
    for(auto i:ans){
        for(auto j:i)   cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}