/*

Question:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Input: nums = [3,2,3]
Output: 3

Link:
https://leetcode.com/problems/majority-element/

Algo: Boyer-Moore Majority Vote Algorithm

*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int>& arr){
    int res=-1;
    int n = arr.size();
    // unordered_map<int, int> mp;
    // for(int x: arr){
    //     mp[x]++;
    //     if(mp[x]>n/2)
    //         return x;

    // }
    // for(auto x: mp) if(x.second>n/2) res=x.first;
    int cad = arr[0], vot = 1;
    for(int i=1; i<n; i++){
        if(cad==arr[i]){
            vot++;
            continue;
        }
        vot--;
        if(vot==0){
            vot=1;
            cad=arr[i];
        }
    }
    return cad;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int res = solution(arr);
    cout<<res<<endl;
    return 0;
}