/*
Find the longest increasing subsequence of a given array of integers, A.

In other words, find a subsequence of array in which the subsequence's elements are in strictly increasing order, and in which the subsequence is as long as possible.

In this case, return the length of the longest increasing subsequence.
*/

#include <bits/stdc++.h>
using namespace std;

// bottom-up approach
int lis(vector<int> &arr) {
    int n=arr.size();
    // dp[i] will hols the length of the LIS ending at index i
    vector<int> dp(n,1);
    for (int i=0;i<n;i++) {
        // check all elements to the left of 
        for (int j=0;j<i;j++) {
            // if arr[i] can be appended to the sequence ending at index j
            if (arr[j]<arr[i]) {
                // update dp[i] if it leads to a longer sequence
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    // find the maximum value of a lis ending at any index i
    int ans=0;
    for (int i=0;i<n;i++) {
        ans=max(ans,dp[i]);
    }
    return ans;
}
//time:O(n^2),space:O(n)
