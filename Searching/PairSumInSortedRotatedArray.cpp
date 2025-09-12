#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of size n, which is sorted and then rotated around an unknown pivot, the task is to check whether there exists a pair of elements in the array whose sum is equal to a given target value.
*/

// Naive Approach -> Hashing
bool pairInSortedRotated(vector<int> &arr,int target) {
    unordered_set <int> s;
    for (int i=0;i<arr.size();i++) {
        int complement=target-arr[i];
        if (s.find(complement)!=s.end()) return true;
        s.insert(arr[i]);
    }
    return false;
}
// Time complexity:O(n),Space complexity:O(n)


// Optimised Approach -> Two Pointer Technique
bool pairInSortedRotated(vector<int>& arr, int target) {
    int n=arr.size();
    int i;
    for (i=0;i<n-1;i++) {
        if (arr[i]>arr[i+1]) break;
    }
    int left=(i+1)%n,right=i;
    while (left!=right) {
        int sum=arr[left]+arr[right];
        if (sum==target) return true;
        if (sum>target) right=(right-1+n)%n;
        else left=(left+1+n)%n;
    }
    return false;
}
// Time complexity: O(n),Space complexity:O(1)