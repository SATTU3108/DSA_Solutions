#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.
For example:

If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

Note: Print -1 if you can't reach the end of the array.
*/

// Recursion
int minJumpsRec(int i,vector<int> &arr) {
    int n=arr.size();
    if (i>=n-1) return 0;
    int min_jumps=INT_MAX;
    for (int j=i+1;j<=i+arr[i];j++) {
        int jumps=minJumpsRec(j,arr);
        if (jumps!=INT_MAX) min_jumps=min(min_jumps,1+jumps);
    }
    return min_jumps;
}
int minJumps(vector<int> &arr) {
    int ans=minJumpsRec(0,arr);
    if (ans==INT_MAX) return -1;
    return ans;
}
//time:O(n^n),space:O(n)

// Memoisation
int minJumpsRec(int i,vector<int> &arr,vector<int> &memo) {
    int n=arr.size();
    if (i==n-1) return 0;
    if (memo[i]!=-1) return memo[i];
    int min_jumps=INT_MAX;
    for (int j=i+1;j<=i+arr[i] && j<n;j++) {
        int jumps=minJumpsRec(j,arr,memo);
        if (jumps!=INT_MAX) min_jumps=min(min_jumps,1+jumps);
    }
    return memo[i]=min_jumps;
}
int minJumps(vector<int> &arr) {
    int n=arr.size();
    vector<int> memo(n,-1);
    int ans=minJumpsRec(0,arr,memo);
    if (ans==INT_MAX) return -1;
    return ans;
}
//time:O(n^2),sapce:O(n)

// Tabulation
int minJumps(vector<int> &arr) {
    int n=arr.size();
    vector<int> dp(n,INT_MAX);
    dp[n-1]=0;
    for (int i=n-2;i>=0;i--) {
        for (int j=i+1;j<=i+arr[i] && j<n;j++) {
            if (dp[j]!=INT_MAX) {
                dp[i]=min(dp[i],1+dp[j]);
            }
        }
    }
    if (dp[0]==INT_MAX) return -1;
    return dp[0];
}
//time:O(n^2),space:O(n)

// Greedy 
