/*

Question:
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Input: nums = [3,2,3]
Output: [3]

Input: nums = [1,2]
Output: [1,2]

Link:
https://leetcode.com/problems/majority-element-ii/

Algo: Boyer-Moore Majority Vote Algorithm (for n/3)

Hint: There can be only two candidates with more than n/3 votes

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int>& arr){
    vector<int> res;
    int n = arr.size();
    int cada=-1, cadb=-1, vota=0, votb=0;
    for(int x: arr){
        if(x==cada){
            vota++;
            continue;
        }
        if(x==cadb){
            votb++;
            continue;
        }
        if(!vota){
            vota++;
            cada=x;
            continue;
        }
        if(!votb){
            votb++;
            cadb=x;
            continue;
        }
        vota--;
        votb--;
    }
    vota=0;
    votb=0;
    for(auto x: arr){
        if(x==cada)vota++;
        else if(x==cadb)votb++;
    }
    if(vota>n/3) res.push_back(cada);
    if(votb>n/3) res.push_back(cadb);
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> res = solution(arr);
    cout<<"[";
    for(int i=0; i<res.size()-1; i++) cout<<res[i]<<",";
    cout<<res[res.size()-1]<<"]"<<endl;
    return 0;
}