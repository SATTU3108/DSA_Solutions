#include <bits/stdc++.h>
using namespace std;

/*
Given an array stalls[] representing the positions of stalls and an integer k denoting the number of aggressive cows, place the cows in the stalls such that the minimum distance between any two cows is as large as possible. Return this maximum possible minimum distance.
*/

// Naive Approach -> iterate over all possible distances
bool check(vector<int> &stalls,int k,int dist) {
    // pace first cow at 0th index
    int count=1,prev=stalls[0];
    for (int i=1;i<stalls.size();i++) {
        // if the current stall is at least dist away from the previous one, place the cow here
        if (stalls[i]-prev>=dist) {
            prev=stalls[i];
            count++;
        }
    }
    // return true if we are able to place all k cows
    return (count>=k);
}
int aggressiveCows(vector<int> &stalls,int k) {
    // sorting the array to ensure stalls ins sequence
    sort(stalls.begin(),stalls.end());
    int res=0;
    // minimum and miaximum possible distance between 2 stalls
    int min_dist=1,max_dist=stalls[stalls.size()-1]-stalls[0];
    // iterating through all possible distances
    for (int i=min_dist;i<=max_dist;i++) {
        // if we can place k cows with this distance, update res
        if (check(stalls,k,i)) res=i;
    }
    return res;
}
//time:O(n*(max-min)),space:O(1)

// Optimal Approach -> Binary Search
int aggressiveCows(vector<int> &stalls,int k) {
    sort(stalls.begin(),stalls.end());
    int res=0;
    int low=1,high=stalls[stalls.size()-1]-stalls[0];
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (check(stalls,k,mid)) {
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}
//time:O(nlogd),space:O(1)