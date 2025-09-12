#include <bits/stdc++.h>
using namespace std;

/*
Given n horizontal line segments are arranged on the X-axis of a 2D plane. The start and end point of each line segment is given in an nx2 matrix lines[ ][ ], the task is to find the maximum number of intersections possible of any vertical line with the given n line segments.
*/

// Naive Approach
int maxIntersections(vector<vector<int>> &lines) {
    int n=lines.size();
    int min_x=INT_MAX,max_x=INT_MIN;
    for (auto line:lines) {
        min_x=min(min_x,line[0]);
        max_x=max(max_x,line[1]);
    }
    int res=0;
    for (int x=min_x;x<=max_x;x++) {
        int count=0;
        for (auto line:lines) {
            if (x>=line[0] && x<=line[1]) count++;
        }
        res=max(res,count);
    }
    return res;
}
//time:O(n*(max-min)),space:O(1)

// Better Approach -> Sorting + 2 Pointer 
int maxIntersections(vector<vector<int>> &lines) {
    int n=lines.size();
    vector<int> start(n),end(n);
    for (int i=0;i<n;i++) {
        start[i]=lines[i][0];
        end[i]=lines[i][1];
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int res=0,count=0,i=0,j=0;
    while (i<n && j<n) {
        if (start[i]<=end[j]) {
            count++;
            i++;
            res=max(res,count);
        }
        else {
            count--;
            j++;
        }
    } 
    return res;
}
//time:O(nlogn),space:O(n)

// Best Approach -> Hashmap
int maxIntersections(vector<vector<int>> &lines) {
    int n=lines.size();
    unordered_map <int,int> events;
    for (auto line:lines) {
        events[line[0]]++;
        events[line[1]+1]--;
    }
    int count=0,max_count=0;
    for (auto event:events) {
        count+=event.second;
        max_count=max(max_count,count);
    }
    return max_count;
}