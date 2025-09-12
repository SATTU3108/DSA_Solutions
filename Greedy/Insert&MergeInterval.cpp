#include <bits/stdc++.h>
using namespace std;

/*
Given a set of non-overlapping intervals and a new interval, the task is to insert the interval at the correct position such that after insertion, the intervals remain sorted. If the insertion results in overlapping intervals, then merge the overlapping intervals. Assume that the set of non-overlapping intervals is sorted based on start time.
*/

// Insertion and Merging
vector<vector<int>> mergeOverlap(vector<vector<int>> &intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i=1;i<intervals.size();i++) {
        vector<int> &last=res.back();
        vector<int> &curr=intervals[i];
        if (curr[0]<=last[1]) last[1]=max(last[1],curr[1]);
        else res.push_back(curr);
    }
    return res;
}
vector<vector<int>> insertInterval(vector<vector<int>> &intervals,vector<int> &newInterval) {
    intervals.push_back(newInterval);
    return mergeOverlap(intervals);
}
//time:O(nlogn),space:O(1)

// Continous Merging
vector<vector<int>> insertInterval(vector<vector<int>> &intervals,vector<int> &newInterval) {
    vector<vector<int>> res;
    int i=0,n=intervals.size();
    while (i<n && intervals[i][1]<newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }
    while (i<n && intervals[i][0]<=newInterval[1]) {
        newInterval[0]=min(newInterval[0],intervals[i][0]);
        newInterval[1]=max(newInterval[1],intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i<n) {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}
//time:O(n),space:O(1)