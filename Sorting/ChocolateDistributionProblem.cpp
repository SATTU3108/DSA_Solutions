#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of n integers where arr[i] represents the number of chocolates in ith packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

Each student gets exactly one packet.
The difference between the maximum and minimum number of chocolates in the packets given to the students is minimized.
*/

// Naive Approach -> Generate All Subsets

// Optimal Approach -> Sorting + Sliding Window
int findMinDiff(vector<int> &arr,int m) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int min_diff=INT_MAX;
    for (int i=0;(i+m-1)<n;i++) {
        int diff=arr[i+m-1]-arr[i];
        if (diff<min_diff) min_diff=diff;
    }
    return min_diff;
}
//time:O(NlogN),space:O(1)