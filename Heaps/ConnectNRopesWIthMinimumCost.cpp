#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths.
*/

// Naive Method -> Sorting
int minCost(vector<int> &arr) {
    int totalCost=0;
    while (arr.size()>1) {
        sort(arr.begin(),arr.end());
        int first=arr[0];
        int second=arr[1];
        arr.erase(arr.begin());
        arr.erase(arr.begin());
        totalCost+=first+second;
        arr.push_back(first+second);
    }
    return totalCost;
}
//time:O(n^2logn),space:O(1)

// Expected Approach -> Priority Queue
int minCost(vector<int> &arr) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i=0;i<arr.size();i++) pq.push(arr[i]);
    int ans=0;
    while (pq.size()>1) {
        // extract 2 shortest ropes from pq
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        // connect the roeps: update result and insert the new row to pq
        ans+=first+second;
        pq.push(first+second);
    }
    return ans;
}
//time:O(nlogn),space:O(n)