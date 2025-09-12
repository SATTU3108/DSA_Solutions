#include <bits/stdc++.h>
using namespace std;

/*
Given two strings, s1 and s2, the task is to find the length of the Longest Common Subsequence. If there is no common subsequence, return 0. A subsequence is a string generated from the original string by deleting 0 or more characters, without changing the relative order of the remaining characters.

For example, subsequences of "ABC" are "", "A", "B", "C", "AB", "AC", "BC" and "ABC". In general, a string of length n has 2n subsequences.
*/

// Recursion
int lcsRec(string &s1,string &s2,int m,int n) {
    if (m==0 || n==0) return 0;
    if (s1[m-1]==s2[n-1]) return (1+lcsRec(s1,s2,m-1,n-1));
    else return max(lcsRec(s1,s2,m,n-1),lcsRec(s1,s2,m-1,n));
}
int lcs(string &s1,string &s2) {
    int m=s1.size(),n=s2.size();
    return lcsRec(s1,s2,m,n);
}
//time:O(2^min(m,n)),space:O(min(m,n))

// Memoisation
int lcsRec(string &s1,string &s2,int m,int n,vector<vector<int>> &memo) {
    if (m==0 || n==0) return 0;
    if (memo[m][n]!=-1) return memo[m][n];
    if (s1[m-1]==s2[n-1]) return memo[m][n]=1+lcsRec(s1,s2,m-1,n-1,memo);
    return memo[m][n]=max(lcsRec(s1,s2,m,n-1,memo),lcsRec(s1,s2,m-1,n,memo));
}
int lcs(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<vector<int>> memo(m+1,vector<int> (n+1,-1));
    return lcsRec(s1,s2,m,n,memo);
}
//time:O(m*n),space:O(m*n)

// Tabulation
int lcs(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<vector<int>> dp(m+1,vector<int> (n+1,0));
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
//time:O(m*n),sapce:O(m*n)

// Space optimised DP
int lcs(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<int> prev(n+1,0),curr(n+1,0);
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[n];
}
//time:O(m*n),sapce:O(2n)
