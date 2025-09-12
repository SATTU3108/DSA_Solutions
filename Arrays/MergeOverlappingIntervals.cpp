#include <bits/stdc++.h>
using namespace std;

/*
Given an array of time intervals where arr[i] = [starti, endi], our task is to merge all the overlapping intervals into one and output the result which should have only mutually exclusive intervals.
*/

vector<vector<int>> mergeOverlap(vector<vector<int>> &arr) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> res;
    res.push_back(arr[0]);
    for (int i=1;i<arr.size();i++) {
        vector<int> &last=res.back();
        vector<int> &curr=arr[i];
        if (curr[0]<=last[1]) last[1]=max(last[1],curr[1]);
        else res.push_back(curr);
    }
    return res;
}