/*

Question:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[1] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Link: https://leetcode.com/problems/3sum/

Explanation:
For every element take two points. One next to the element and other at the end and keep sliding them for required

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<int> arr){
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if(n<3)
        return res;
    for(int i=0; i<n-2; i++){
        int s=i+1, e=n-1;
        while(s<e){
            int sum=arr[i]+arr[s]+arr[e];
            if(sum==0){
                res.push_back({arr[i], arr[s], arr[e]});
                s++;
                e--;
                while(s<n && arr[s] == arr[s-1])s++;
                while(s<e && arr[e] == arr[e+1])e--;
            }else if(sum>0){
                e--;
            }else{
                s++;
            }
            while(i<n-1 && arr[i] == arr[i+1])i++;
        }
    }
    vector<vector<int>> res2;
    map<vector<int>, int> mp;
    for(auto x: res){
        mp[x]++;
    }
    for(auto x:mp){
        res2.push_back(x.first);
    }
    return res2;
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>k;
    vector<vector<int>> res = solution(arr);
    cout<<"[";
    for(int i=0; i<res.size()-1; i++) cout<<"["<<res[i][0]<<","<<res[i][1]<<","<<res[i][2]<<"]"<<",";
    cout<<"["<<res[res.size()-1][0]<<","<<res[res.size()-1][1]<<","<<res[res.size()-1][2]<<"]"<<"]"<<endl;
    return 0;
}