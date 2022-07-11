/*

Question:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Link:
https://leetcode.com/problems/longest-consecutive-sequence/

*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int>& arr){
    int res=1;
    // unordered_map<int,int> mp;
    // for(int x:arr){
    //     mp[x]=mp[x-1]+1+mp[x+1];
    //     if(mp[x-1])mp[x-1]=mp[x];
    //     if(mp[x+1])mp[x+1]=mp[x];
    // }
    // for(auto x: mp){
    //     res=max(res,x.second);
    // }
    unordered_set<int> st(arr.begin(), arr.end());
    for(int x: arr){
        if(st.find(x-1)==st.end()) continue;
        st.erase(x);
        int p=x-1,n=x+1;
        while(st.find(p)!=st.end()) st.erase(p--);
        while(st.find(n)!=st.end()) st.erase(n++);
        res = max(res,n-p-1);
    }
    return res;
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