#include <bits/stdc++.h>
using namespace std;

/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.
*/


// Brute-force approach
int numberOfArithmeticSlices(vector <int> &nums) {
    int n=nums.size();
    if (n<3) return 0;
    int count=0,diff;
    for (int i=0;i<n-2;i++) {
        diff=nums[i+1]-nums[i];
        for (int j=i+2;j<n;j++) {
            if (nums[j]-nums[j-1]==diff) count++;
            else break;
        }
    }
    return count;
}
//time:O(n^2),space:O(1)

// Optimal Approach
int numberOfArithmeticSlices(vector<int> &nums) {
    int n=nums.size();
    if (n<3) return 0;
    int streak=0,total=0;
    int prev_diff=nums[1]-nums[0];
    for (int i=2;i<n;i++) {
        int curr_diff=nums[i]-nums[i-1];
        if (prev_diff==curr_diff) {
            streak++;
            total+=streak;
        }
        else {
            streak=0;
            prev_diff=curr_diff;
        }
    }
    return total;
}
//time:O(n),space:O(1)