/*

Question:
Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under a constraint that any painter will only paint the continuous sections of boards.

Input: k=2, boards=[10,20,30,40]
Output: 60
Explanation: 1st painter paints first three boards (i.e. 10,20,30) and 2nd does the last one

Link:
https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557

Technique:
Instead of calculating what is the minimum time for the given number of painters what we actually are doing is we find minimum no of people required of some given time.
And we use that function to find the time between the minmum time for 1 person (height of longest board) and maximum time for 1 person (total sum).
That time is the answer where you use maximum number of painters alloted.

Tip:
Sometime calculating for the value already available might help in figuring out the best value for the missing variable.

*/

#include <bits/stdc++.h>

using namespace std;

int painterNo(vector<int> &boards, int cap){
    int counter=1, remCap=cap-boards[0], n=boards.size();
    for(int i=1; i<n; i++){
        remCap-=boards[i];
        if(remCap<0){
            remCap=cap-boards[i];
            counter++;
        }
    }
    return counter;
}

int solution(vector<int> &boards, int k){
    int n=boards.size(),sum=0,minCap=0;
    for(int x: boards){
        sum+=x;
        minCap=max(minCap,x);
    }
    int i=minCap, j=sum, ans=0;
    while(i<=j){
        int mid = i + ((j-i)/2);
        int pn=painterNo(boards,mid);
        if(pn<=k){
            ans=mid;
            j=mid-1;
        }
        else 
            i=mid+1;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>k;
    cout<<solution(arr,k);
    return 0;
}