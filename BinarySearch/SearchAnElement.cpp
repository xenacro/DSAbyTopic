/*

Question:
You have given a sorted array 'A' of 'N' integers.
Now, you are given 'Q' queries, and each query consists of a single integer 'X'. Your task is to check whether 'X' is present in array 'A' or not for each query. If 'X' exists in array 'A', you need to print 1 else print 0.

Input: N=5, A=[1,3,5,7,8], X=2, Q=[5,2]
Output: [1,0]

Link: 
https://www.codingninjas.com/codestudio/problems/binary-search_975480

Tip:
Avoid (i+j)/2 and instead use i+((j-i)/2) since (i+j) ming overflow.

*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> dp;

int helper(vector<int> &arr, int i, int j, int target){
    if(i>j||i>=arr.size()||j>arr.size()) return -1;
    if(i==j) {
        if(target==arr[i]) return 1;
        return -1;
    }
    if(target==arr[(i+j)/2]) return 1;
    if(target>arr[(i+j)/2]) return helper(arr, ((i+j)/2)+1, j,target);
    return helper(arr,i, (i+j)/2,target);
}

vector<int> solution(vector<int> &arr, int n, vector<int> &queries, int q){
    vector<int> res;
    for(int x:queries){
        if(dp[x]!=0){
            if(dp[x]==-1) res.push_back(0);
            else res.push_back(1);
        }
        else {
            dp[x]=helper(arr, 0, n, x);
            if(dp[x]==-1) res.push_back(0);
            else res.push_back(1);
        }
    }
    dp.clear();
    return res;
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n), queries;
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>k;
    for(int i=0; i<k; i++){
        int t;
        cin>>t;
        queries.push_back(t);
    }
    vector<int> res = solution(arr, n, queries, k);
    cout<<"[";
    for(int i=0; i<res.size()-1; i++) cout<<res[i]<<",";
    cout<<res[res.size()-1]<<"]"<<endl;
    return 0;
}