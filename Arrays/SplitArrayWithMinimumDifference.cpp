/*
You are given an integer array nums.

Split the array into exactly two subarrays, left and right, such that left is strictly increasing and right is strictly decreasing.

Return the minimum possible absolute difference between the sums of left and right. If no valid split exists, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

long long splitArray(vector<int>& nums) {
    int n=nums.size();
    if (n<2) return -1;
    vector<long long> prefix_sum(n);
    prefix_sum[0]=nums[0];
    for (int i=1;i<n;i++) {
        prefix_sum[i]=prefix_sum[i-1]+nums[i];
    }
    long long total_sum=prefix_sum[n-1];
    // inc[i]=true if nums[0...i] is strictly increasing
    vector<bool> inc(n,true);
    for (int i=1;i<n;i++) {
        inc[i]=inc[i-1] && (nums[i]>nums[i-1]);
    }
    // dec[i]=true if nums[i...n-1] is strictly increasing
    vector<bool> dec(n,true);
    for (int i=n-2;i>=0;i--) {
        dec[i]=dec[i+1] && (nums[i]>nums[i+1]);
    }
    // left: nums[0...i],right[i+1...n-1]
    long long min_diff=LLONG_MAX;
    for (int i=0;i<n-1;i++) {
        if (inc[i] && dec[i+1]) {
            long long left_sum=prefix_sum[i];
            long long right_sum=total_sum-left_sum;
            long long diff=abs(left_sum-right_sum);
            min_diff=min(min_diff,diff);
        }
    }
    if (min_diff==LLONG_MAX) return -1;
    else return min_diff;
}
