#include <bits/stdc++.h>
using namespace std;

/*
Given 2 strings s1and s2, find length of longest common substring
*/

// Naive iterative method
int longestCommonSubstring(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    int res=0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            int curr=0;
            while ((i+curr)<m && (j+curr)<n && s1[i+curr]==s2[j+curr]) curr++;
            res=max(res,curr);
        }
    }
    return res;
}
//time:O(mxnxmin(m,n)),space:O(1)

// Recursive
int helper(string &s1,string &s2,int m,int n) {
    if (m==0 || n==0 || s1[m-1]!=s2[n-1]) return 0;
    return 1+helper(s1,s2,m-1,n-1);
}
int longestCommongSubstring(string &s1,string &s2) {
    int res=0;
    for (int i=1;i<=s1.size();i++) {
        for (int j=1;j<=s2.size();j++) {
            res=max(res,helper(s1,s2,i,j));
        }
    }
    return res;
}
//time:O(mxnxmin(m,n)),space:O(min(m,n))

// DP solution
int longestCommonSubstring(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<vector<int>> dp(m+1,vector<int> (n+1,0));
    int res=0;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s1[i-1]==s2[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
                res=max(res,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return res;
}
//time:O(m*n),space:O(m*n)

// Space-optimised DP
int longestCommonSubstring(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<int> prev(n+1,0);
    int res=0;
    for (int i=1;i<=m;i++) {
        vector<int> curr(n+1,0);
        for (int j=1;j<=n;j++) {
            if (s1[i-1]==s2[j-1]) {
                curr[j]=prev[j-1]+1;
                res=max(res,curr[j]);
            }
            else curr[j]=0;
        }
        prev=curr;
    }
    return res;
}
//time:O(m*n),space:O(n)