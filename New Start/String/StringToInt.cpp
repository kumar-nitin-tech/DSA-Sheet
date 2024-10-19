/*
    
    Problem Statement:  Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

    Problem Link:   https://leetcode.com/problems/string-to-integer-atoi/description/

    Refer:  

*/

#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int n = s.size();
    long long ans = 0;
    if(n == 0){
        return 0;
    }        
    int i = 0;
    //Whitespace at start 
    while(i<n && s[i] == ' '){
        i++;
    }
    if(i>=n){
        return 0;
    }
    int sign = 1;
    //any sign in front
    if(s[i] == '+' || s[i] == '-'){
        sign = (s[i] == '-')?-1:1;
        i++;
    }
    if(i>=n){
        return 0;
    }

    //For integer in string
    for(; i<n; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            ans = ans*10 + s[i]-'0';
            if(sign == -1 && -1*ans<INT32_MIN)   return INT32_MIN;
            if(sign == 1 && ans>INT32_MAX)    return INT32_MAX;
        }else{
            break;
        }
    }
    return (sign)* ans;
}

int main(){
    string s;
    cin>>s;
    cout<<myAtoi(s);
    return 0;
}