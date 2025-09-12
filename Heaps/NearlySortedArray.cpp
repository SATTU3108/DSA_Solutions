#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] and a number k . The array is sorted in a way that every element is at max k distance away from it sorted position. It means if we completely sort the array, then the index of the element can go from i - k to i + k where i is index in the given array. Our task is to completely sort the array.
*/

// Naive Approach -> Sorting
void nearlySorted(vector<int>& arr, int k) {
    sort(arr.begin(),arr.end());
}
//time:O(nlogn),space:O(1)

// Expected Approach -> Heaps
void nearlySorted(vector<int> &arr,int k) {
    int n=arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    // Push first (k+1) elements
    for (int i=0;i<=k && i<n;i++) pq.push(arr[i]);
    int index=0;
    for (int i=k+1;i<n;i++) {
        arr[index]=pq.top();
        index++;
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty()) {
        arr[index]=pq.top();
        index++;
        pq.pop();
    }
}
//time:O(nlogk),space:O(k)