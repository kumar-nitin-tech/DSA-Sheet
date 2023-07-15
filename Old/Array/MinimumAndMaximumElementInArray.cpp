/*
    2. Minimum and Maximum Element in the given Array
*/

#include<bits/stdc++.h>
using namespace std;

//Basic Approach using loops
int maxElement(vector<int>&a){
    int max = a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}
int minElement(vector<int>&a){
    int min = a[0];
    for(int i=0;i<a.size();i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    return min;
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &i:a){
        cin>>i;
    }
    cout<<maxElement(a)<<" "<<minElement(a);
    return 0;
}