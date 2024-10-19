/*
    
    Problem Statement:  Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M

    Problem Link:   https://leetcode.com/problems/roman-to-integer/description/

    Refer:  https://leetcode.com/problems/roman-to-integer/solutions/

*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC:
//SC:

int numTo(char c){
    if(c == 'I')    return 1;
    else if(c == 'V')    return 5;
    else if(c == 'X')    return 10;
    else if(c == 'L')    return 50;
    else if(c == 'C')    return 100;
    else if(c == 'D')    return 500;
    else if(c == 'M')    return 1000;
}

int romanToIntBrute(string s){
    int sum = 0; 
    
    for(int i=0; i<s.size()-1; i++){
        if(numTo(s[i]) < numTo(s[i+1])){
            sum -= numTo(s[i]);
        }else{
            sum += numTo(s[i]);
        }
    }

    sum += numTo(s[s.size()-1]);
    return sum;
}


//Optimnal Approach
//TC:
//SC:
int romanToIntOptimal(string s){

}

int main(){
    string s;
    cin>>s;
    cout<<romanToIntBrute(s);
    return 0;
}