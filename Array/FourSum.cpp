/*

Question:
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Link: https://leetcode.com/problems/4sum/

Explanation:
For every two element take two points. One next to the element and other at the end and keep sliding them for required

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<int> arr, int target)
{
    vector<vector<int>> res;
    int n = arr.size();
    if (n < 4)
        return res;
    sort(arr.begin(), arr.end());
    int i = 0;
    while (arr[i] > abs(target) && i < n - 1)
        i++;
    for (; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            int s = j + 1, e = n - 1;
            while (s < e)
            {
                long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[s] + (long long)arr[e];
                if (sum == target)
                {
                    res.push_back({arr[i], arr[j], arr[s], arr[e]});
                    s++;
                    e--;
                    while (s < n && arr[s] == arr[s - 1])
                        s++;
                    while (s < e && arr[e] == arr[e + 1])
                        e--;
                }
                else if (sum > target)
                {
                    e--;
                }
                else
                {
                    s++;
                }
                while (j < n - 1 && arr[j] == arr[j + 1])
                    j++;
            }
        }
    }
    vector<vector<int>> res2;
    map<vector<int>, int> mp;
    for (auto x : res)
    {
        mp[x]++;
    }
    for (auto x : mp)
    {
        res2.push_back(x.first);
    }
    return res2;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    vector<vector<int>> res = solution(arr, k);
    cout << "[";
    for (int i = 0; i < res.size() - 1; i++)
        cout << "[" << res[i][0] << "," << res[i][1] << "," << res[i][2] << "," << res[i][3] << "]"
             << ",";
    cout << "[" << res[res.size() - 1][0] << "," << res[res.size() - 1][1] << "," << res[res.size() - 1][2] << "," << res[res.size() - 1][3] << "]"
         << "]" << endl;
    return 0;
}