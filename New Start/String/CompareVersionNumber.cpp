/*
    Compare Version Numbers
    Problem Statement:  Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

    Problem Link:   https://leetcode.com/problems/compare-version-numbers/description/

    Refer:

*/

#include<bits/stdc++.h>
using namespace std;

//Two Pointer Approach
int compareVersion(string version1, string version2) {
    int i=0, j=0;
    int n = version1.size(), m = version2.size();
    while(i<n || j<m){
        int v1 = 0, v2 = 0;
        while(i<n && version1[i] != '.'){
            v1 = v1*10 + (version1[i] - '0');
            i++;
        }
        i++;
        while(j<m && version2[j] != '.'){
            v2 = v2*10 + (version2[j] - '0');
            j++;
        }
        j++;
        if(v1<v2){
            return -1;
        }
        else if(v1>v2){
            return 1;
        }
    }
    return 0;
}

int main(){
    string v1,v2;
    cin>>v1>>v2;
    cout<<compareVersion(v1,v2);
    return 0;
}