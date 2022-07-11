/*

Question:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Link:
https://leetcode.com/problems/two-sum/

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int k){
    vector<int> res(2);
    map<int, int> mp;
    for(int i=0; i<arr.size(); i++){
        if(mp[arr[i]]!=0){
            res[0]=mp[arr[i]]-1;
            res[1]=i;
            return res;
        }
        mp[k-arr[i]]=i+1;
    }
    return res;
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>k;
    vector<int> res = solution(arr, k);
    cout<<"["<<res[0]<<","<<res[1]<<"]"<<endl;
    return 0;
}