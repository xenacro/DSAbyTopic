/*

Question:
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

Link:
https://leetcode.com/problems/sqrtx/

Hint:
Keep j=1e8 instead of N for bigger (hence faster) jumps

*/

#include <bits/stdc++.h>

using namespace std;

int sqrtN(long long int N){
    long long int i=0,j=1e8, res=0;
    while(i<=j){
        long long int m = i + ((j-i)/2);
        if(m*m<=N){
            res=m;
            i=m+1;
        }
        else j=m-1;
    }
    return res;
}

int main(){
    long long int x;
    cin>>x;
    cout<<sqrtN(x);
    return 0;
}