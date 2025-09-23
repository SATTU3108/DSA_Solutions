/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums,int target) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int min_diff=INT_MAX;
    int ans;
    for (int i=0;i<n-2;i++) {
        int left=i+1,right=n-1; // similar to 3sum logic
        while (left<right) {
            int sum=nums[i]+nums[left]+nums[right];
            int curr_diff=abs(sum-target);
            if (curr_diff<min_diff) {
                min_diff=curr_diff;
                ans=sum;
            }
            if (sum>target) right--;
            else left++;
        }
    }
    return ans;
}
//time:O(n^2),space:O(1)
