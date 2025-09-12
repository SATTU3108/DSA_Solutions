#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array arr[], find the subarray (containing at least one element) which has the maximum possible sum, and return that sum.
Note: A subarray is a continuous part of an array.
*/

// Approach 1 -> Brute-force
int maxSubarraySum(vector<int> &arr) {
    int n=arr.size();
    int res=arr[0];
    for (int i=0;i<n;i++) {
        int curr_sum=0;
        for (int j=i;j<n;j++) {
            curr_sum+=arr[j];
            res=max(res,curr_sum);
        }
    }
    return res;
}
//time:O(n^2),space:O(1)

// Approach 2 -> Kadane Algorithm
/*
To calculate the maximum sum of subarray ending at current element, say maxEnding, we can use the maximum sum ending at the previous element.

So for any element, we have two choices:

Choice 1: Extend the maximum sum subarray ending at the previous element by adding the current element to it. If the maximum subarray sum ending at the previous index is positive, then it is always better to extend the subarray.
Choice 2: Start a new subarray starting from the current element. If the maximum subarray sum ending at the previous index is negative, it is always better to start a new subarray from the current element.

This means that maxEnding at index i = max(maxEnding at index (i - 1) + arr[i], arr[i]) and the maximum value of maxEnding at any index will be our answer.
*/

int maxSubarraySum(vector<int> &arr) {
    int n=arr.size();
    int res=arr[0];
    int maxEnding=arr[0];
    for (int i=1;i<n;i++) {
        maxEnding=max(maxEnding+arr[i],arr[i]);
        res=max(res,maxEnding);
    }
    return res;
}
//time:O(n),space:O(1)

/*
If question would be to determine the subarray that causes the maxiimum sum, then how to do?
*/
long long maxSubarraySum(int arr[],int n) {
    long long maxi=INT_MIN;
    long long sum=0;
    int start=0;
    int ansStart=-1,ansEnd=-1;
    for (int i=0;i<n;i++) {
        if (sum==0) start=i;
        sum+=arr[i];
        if (sum>maxi) {
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }
        if (sum<0) sum=0;
    }
    cout<<"The subarray is [";
    for (int i=ansStart;i<=ansEnd;i++) cout<<arr[i]<<" ";
    cout<<"]"<<endl;
    return maxi;
}