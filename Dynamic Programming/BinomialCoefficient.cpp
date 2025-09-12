#include <bits/stdc++.h>
using namespace std;

// Recursion
int binomialCoeff(int n,int k) {
    if (k>n) return 0;
    if (k==0 || k==n) return 1;
    return binomialCoeff(n-1,k-1)+binomialCoeff(n-1,k);
}
//time:O(2^n),space:O(n)

// Memoisation
int nCk(int n,int k,vector<vector<int>> &memo) {
    if (k>n) return 0;
    if (k==0 || k==n) return 1;
    if (memo[n][k]!=-1) return memo[n][k];
    return memo[n][k]=nCk(n-1,k-1,memo)+nCk(n-1,k,memo);
}
int binomialCoeff(int n,int k) {
    vector<vector<int>> memo(n+1,vector<int> (k+1,-1));
    return nCk(n,k,memo);
}
//time:O(n*k),space:O(n*k)

// Tabulation
int binomialCoeff(int n,int k) {
    vector<vector<int>> dp(n+1,vector<int> (k+1));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=k;j++) {
            if (j>i) dp[i][j]=0;
            else if (j==0 || j==i) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return dp[n][k];
}
//time:O(n*k),space:O(n*k)