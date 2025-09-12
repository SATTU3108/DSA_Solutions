#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array of coins[] of size n representing different types of denominations and an integer sum, the task is to count all combinations of coins to make a given value sum.  

Note: Assume that you have an infinite supply of each type of coin. 
*/

// Recursion
int countRecur(vector<int> &coins,int n,int sum) {
    if (sum==0) return 1;
    if (sum<0 || n==0) return 0;
    return countRecur(coins,n,sum-coins[n-1])+countRecur(coins,n-1,sum);
}
//time:O(2^n),space:O(n)

// Memoisation
int countRecur(vector<int> &coins,int n,int sum,vector<vector<int>> &memo) {
    if (sum==0) return 1;
    if (sum<0 || n==0) return 0;
    if (memo[n-1][sum]!=-1) return memo[n-1][sum];
    return memo[n-1][sum]=countRecur(coins,n,sum-coins[n-1],memo)+countRecur(coins,n-1,sum,memo);
}
//time:O(n*sum),space:O(n*sum)

// Tabulation
int count(vector<int> &coins,int sum) {
    int n=coins.size();
    vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
    dp[0][0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=sum;j++) {
            dp[i][j]+=dp[i-1][j];
            if (coins[i-1]<=j) dp[i][j]+=dp[i][j-coins[i-1]];
        }
    }
    return dp[n][sum];
}
//time:O(n*sum),space:O(n*sum)

// Space-optimsed approach
int count(vector<int> &coins,int sum) {
    int n=coins.size();
    vector<int> dp(sum+1);
    dp[0]=1;
    for (int i=0;i<n;i++) {
        for (int j=coins[i];j<=sum;j++) dp[j]+=dp[j-coins[i-1]];
    }
    return dp[sum];
}
//time:O(n*sum),space:O(sum)