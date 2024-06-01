/*
    Median of Row Wise Sorted Matrix

    Problem Statement:  Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns, find the median in the given matrix.
                        Assume - r*c is odd  

    Problem Link:   https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

    Refer:  https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC: O((r*c) log(r*c))
//SC: O(1)
int medianMatrixBrute(vector<vector<int>> &matrix, int r, int c){
    vector<int> medianMatrix;
    for(auto i:matrix){
        for(auto j:i){
            medianMatrix.push_back(j);
        }
    }
    sort(medianMatrix.begin(), medianMatrix.end());
    int mid = medianMatrix.size()/2;
    return medianMatrix[mid];
}

//Optimal Approach
//TC:
//SC:

int upperBound(vector<int> row, int x){
    int low = 0, high = row.size()-1;
    int ans = row.size();

    while(low<=high){
        int mid = (low+high)/2;
        if(row[mid] > x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int lessThanEqual(vector<vector<int>> &matrix, int x){
    int sum = 0;
    for(int i=0; i<matrix.size(); i++){
        sum += upperBound(matrix[i],x);
    }
    return sum;
}

int medianMatrixOptimal(vector<vector<int>> &matrix, int r, int c){
    int low = INT_MAX, high = INT_MIN;
    for(int i=0; i<r; i++){
        low = min(low, matrix[i][0]);
        high = max(high,matrix[i][c-1]);
    }
    int x = (r*c)/2;
    while(low<=high){
        int mid = (low+high)/2;
        int smallerValue = lessThanEqual(matrix,mid);
        if(smallerValue <= x){
            low = mid+1;
        }
        else if(smallerValue > x){
            high = mid-1;
        }
    }
    return low;
}



int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> matrix(r, vector<int> (c));
    for(auto &i:matrix){
        for(auto &j:i){
            cin>>j;
        }
    }
    cout<<medianMatrixOptimal(matrix,r,c);
    return 0;
}