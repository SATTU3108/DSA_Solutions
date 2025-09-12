#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of integers. In one operation you can choose an index i, and increment the element arr[i] by 1. The task is to return the minimum number of operations needed to make every value in the array arr[] unique.
*/

// Sorting
int minIncrementForUnique(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int count=0;
    for (int i=1;i<n;i++) {
        if (nums[i]<=nums[i-1]) {
            count+=(nums[i-1]+1)-nums[i];
            nums[i]=nums[i-1]+1;
        }
    }
    return count;
}
//time:O(nlogn),space:O(nlogn)

// Frequency Array
int minIncrementForUnique(vector<int>& nums) {
    int n=nums.size();
    int max_element=nums[0];
    for (int i=1;i<n;i++) {
        if (max_element<nums[i]) max_element=nums[i];
    }
    vector<int> freq(n+max_element);
    for (int i=0;i<n;i++) freq[nums[i]]++;
    int count=0;
    for (int i=0;i<freq.size();i++) {
        if (freq[i]>1) {
            count+=(freq[i]-1);
            freq[i+1]+=(freq[i]-1);
            freq[i]=1;
        }
    } 
    return count;
}
//time:O(n+max):space:O(n+max)