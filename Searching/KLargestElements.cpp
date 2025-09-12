#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] and an integer k, the task is to find k largest elements in the given array. Elements in the output array should be in decreasing order.
*/

// Naive approach -> Sorting
vector<int> kLargest(vector<int> arr,int k) {
    sort(arr.begin(),arr.end(),greater<int> ());
    vector<int> res(arr.begin(),arr.begin()+k);
    return res;
}
// Time complexity: O(nlogn), Space complexity: O(1)

// Expected approach -> Min-Heap
vector<int> kLargest(vector<int> arr,int k) {
    priority_queue <int,vector<int>, greater<int>> minH(arr.begin(),arr.begin()+k);
    for (int i=k;i<arr.size();i++) {
        if (minH.top()<arr[i]) {
            minH.pop();
            minH.push(arr[i]);
        }
    }
    vector<int> res;
    while (!minH.empty()) {
        res.push_back(minH.top());
        minH.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}