#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of n integers and an integer target, the task is to find the sum of triplets such that the sum is closest to target. Note: If there are multiple sums closest to target, print the maximum one.
*/

// Naive Approach
int closest3Sum(vector<int> &arr,int target) {
    int n=arr.size();
    int min_diff=INT_MAX,res=0;
    for (int i=0;i<n-2;i++) {
        for (int j=i+1;j<n-1;j++) {
            for (int k=j+1;k<n;k++) {
                int curr_sum=arr[i]+arr[j]+arr[j];
                int curr_diff=abs(target-curr_sum);
                if (curr_diff<min_diff) {
                    min_diff=curr_diff;
                    res=curr_sum;
                }
                else if (curr_diff==min_diff) res=max(res,curr_sum);
            }
        }
    }
    return res;
}
//time:O(n^3),space:O(1)

// Efficient Approach
int closest3Sum(vector<int> &arr,int target) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int min_diff=INT_MAX,res=0;
    for (int i=0;i<n-2;i++) {
        int left=i+1,right=n-1;
        while (left<right) {
            int curr_sum=arr[i]+arr[left]+arr[right];
            if (abs(curr_sum-target)<min_diff) {
                min_diff=abs(curr_sum-target);
                res=curr_sum;
            }
            else if (abs(curr_sum-target)==min_diff) res=max(res,curr_sum);
            if (curr_sum>target) right--;
            else left++;
        }
    }
    return res;
}
//time:O(n^2),space:O(1)