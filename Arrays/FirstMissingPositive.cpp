/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
*/

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    // place each positive integer at its correct position; nums[i] should be at index nums[i]-1
    // for example, 1 should be at index 0,2 should be at index 1 etc.
    for (int i=0;i<n;i++) {
        // keep swapping while
        // 1. current number is positive & in valid range [1,n]
        // 2. current number is not already in its correct position
        while (nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);
    }
    // find the first position where the number doesn't match its expected value
    for (int i=0;i<n;i++) {
        if (nums[i]!=i+1) return i+1;
    }
    // all positions are at correct positions, so the first missing porive is n+1
    return n+1;
}
//time:O(n),space:O(1)
