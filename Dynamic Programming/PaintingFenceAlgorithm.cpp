#include <bits/stdc++.h>
using namespace std;

/*
Given a fence with n posts and k colors, the task is to find out the number of ways of painting the fence so that not more than two consecutive posts have the same color.
*/

// Recursion
int countWays(int n,int k) {
    if (n==1) return k;
    if (n==2) return k*k;
    int cnt1=countWays(n-1,k)*(k-1);
    int cnt2=countWays(n-2,k)*(k-1);
    return cnt1+cnt2;
}
//time:O(2^n),space:O(k)

// Memoisation
int countWaysRecur(int n,int k,vector<int> &memo) {
    if (n==1) return k;
    if (n==2) return k*k;
    if (memo[n]!=-1) return memo[n];
    int cnt1=countWaysRecur(n-1,k,memo)*(k-1);
    int cnt2=countWaysRecur(n-2,k,memo)*(k-1);
    return memo[n]=cnt1+cnt2;
}
//time:O(n),space:O(n)

// Tabulation
int countWays(int n,int k) {
    if (n==1) return k;
    if (n==2) return k*k;
    vector<int> dp(n+1);
    dp[1]=k,dp[2]=k*k;
    for (int i=3;i<=n;i++) {
        dp[i]=dp[i-1]*(k-1)+dp[i-2]*(k-1);
    }
    return dp[n];
}
//time:O(n),space:O(n)

// Space-optimised DP
int countWays(int n,int k) {
    if (n==1) return k;
    if (n==2) return k*k;
    int prev=k*k,prev2=k;
    for (int i=3;i<=n;i++) {
        int curr=prev*(k-1)+prev2*(k-1);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
//time:O(n),space:O(1)