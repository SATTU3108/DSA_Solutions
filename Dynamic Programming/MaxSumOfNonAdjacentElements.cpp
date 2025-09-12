#include <bits/stdc++.h>
using namespace std;

// Recursion
int maxSumHelper(vector<int> &arr,int n) {
    if (n<=0) return 0;
    if (n==1) return arr[0];
    int pick=arr[n-1]+maxSumHelper(arr,n-2);
    int nonPick=maxSumHelper(arr,n-1);
    return max(pick,nonPick);
}
int findMaxSum(vector<int> &arr) {
    int n=arr.size();
    return maxSumHelper(arr,n);
}
//time:O(2^n),space:O(1)

// Memoisation
int maxSumHelper(vector<int> &arr,int n,vector<int> &memo) {
    if (n<=0) return 0;
    if (n==1) return arr[0];
    if (memo[n]!=-1) return memo[n];
    int pick=arr[n-1]+maxSumHelper(arr,n-2,memo);
    int nonPick=maxSumHelper(arr,n-1,memo);
    return memo[n]=max(pick,nonPick);
}
int findMaxSum(vector<int> &arr) {
    int n=arr.size();
    vector<int> memo(n+1,-1);
    return maxSumHelper(arr,n,memo);
}
//time:O(n),space:O(n)

// Tabulation
int findMaxSum(vector<int> &arr) {
    int n=arr.size();
    vector<int> dp(n+1);
    if (n==1) return arr[0];
    if (n==2) return max(arr[0],arr[1]);
    dp[1]=arr[0],dp[2]=max(arr[0],arr[1]);
    for (int i=3;i<=n;i++) dp[i]=max(arr[i-1]+dp[i-2],dp[i-1]);
    return dp[n];
}
//time:O(n),space:O(n)
int findMaxSum(vector<int> &arr) {
    int n=arr.size();
    if (n==1) return arr[0];
    int prev=arr[0],prev2=0;
    for (int i=1;i<n;i++) {
        int pick=arr[i];
        if (i>1) pick+=prev2;
        int nonPick=0+prev;
        int curr=max(prev,prev2);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
//time:O(n),space:O(1)

/*
House Robber Question:
A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. Therefore the first and the last house are adjacent to each other. The security system in the street is such that if adjacent houses are robbed, the police will get notified.

Given an array of integers “Arr'' which represents money at each house, we need to return the maximum amount of money that the thief can rob without alerting the police.


The approach here is the same as maximum sum of non adjacent elements. just remove first element and then consider max sum and then remove last element and then re-evaulate max sum and final answer will be the maximum of these both sums
*/