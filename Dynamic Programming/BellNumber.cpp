#include <bits/stdc++.h>
using namespace std;

/*
Given a set of n elements, find the number of ways of partitioning it. 
*/

// Recursion
int stirling(int n,int k) {
    if (n==0 && k==0) return 1;
    if (n==0 || k==0) return 0;
    if (n==k) return 1;
    if (k==1) return 1;
    return k*stirling(n-1,k)+stirling(n-1,k-1);
}
int bellNumber(int n) {
    int result=0;
    for (int k=1;k<=n;k++) result+=stirling(n,k);
    return result;
}
//time:O(2^n),space:O(n)

// Memoisation
int stirling(int n,int k,vector<vector<int>> &memo) {
    if (n==0 && k==0) return 1;
    if (n==0 || k==0) return 0;
    if (n==k) return 1;
    if (k==1) return 1;
    if (memo[n][k]!=-1) return memo[n][k];
    memo[n][k]=k*stirling(n-1,k,memo)+stirling(n-1,k-1,memo);
} 
int bellNumber(int n) {
    vector<vector<int>> memo(n+1,vector<int> (n+1,-1));
    int result=0;
    for (int k=1;k<=n;k++) result+=stirling(n,k,memo);
    return result;
}
//time:O(n^2),space:O(n^2)

// Tabulation
int stilring(int n,int k) {
    vector<vector<int>> dp(n+1,vector<int> (k+1));
    
}
int bellNumber(int n) {
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            if (j>i) dp[i][j]=0;
            else if (j==i) dp[i][j]=1;
            else if (i==0 || j==0) dp[i][j]=0;
            else dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
        }
    }
    int ans=0;
    for (int i=0;i<=n;i++) ans+=dp[n][i];
    return ans;
}
//time:O(n^2),space:O(n^2)

// Bell Triangle
int bellNumber(int n) {
    int dp[n+1][n+1];
    dp[0][0]=1;
    for (int i=1;i<=n;i++) {
        dp[i][0]=dp[i-1][i-1];
        for (int j=1;j<=i;j++) dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
    }
    return dp[n][0];
}
//time:O(n^2),space:O(n^2)

// Space Optimised Bell Triangle
int bellNumber(int n) {
    vector<int> dp(n+1,0);
    dp[0]=1;
    for (int i=1;i<=n;i++) {
        int prev=dp[0];
        dp[0]=dp[i-1];
        for (int j=1;j<=i;j++) {
            int temp=dp[j];
            dp[j]=prev+dp[j-1];
            prev=temp;
        }
    }
    return dp[0];
}
//time:O(n^2),sapce:O(n)