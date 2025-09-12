#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

// Naive Approach
int findAllSubarraysWithGivenSum(vector<int> &arr,int k) {
    int n=arr.size();
    int count=0;
    for (int i=0;i<n;i++) {
        int sum=0;
        for (int j=i;j<n;j++) {
            sum+=arr[j];
            if (sum==k) count++;
        }
    }
    return count;
}
//time:O(n^2),space:O(1)

// Optimal Approach -> Prefix Sums
int findAllSubarraysWithGivenSum(vector<int> &arr,int k) {
    int n=arr.size();
    map<int,int> mp;
    int prefix_sum=0,count=0;
    mp[0]=1;
    for (int i=0;i<n;i++) {
        prefix_sum+=arr[i];
        int remove=prefix_sum-k;
        count+=mp[remove];
        mp[prefix_sum]++;
    }
    return count;
}
//time:O(nlogn),space:O(n)