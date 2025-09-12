#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s1 and s2 and below operations that can be performed on s1. The task is to find the minimum number of edits (operations) to convert 's1' into 's2'.  

Insert: Insert any character before or after any index of s1
Remove: Remove a character of s1
Replace: Replace a character at any index of s1 with some other character.
*/

int editDistanceRec(string &s1,string &s2,int m,int n) {
    if (m==0) return n;
    if (n==0) return m;
    if (s1[m-1]==s2[n-1]) return editDistanceRec(s1,s2,m-1,n-1);
    return 1+min({editDistanceRec(s1,s2,m,n-1),editDistanceRec(s1,s2,m-1,n),editDistanceRec(s1,s2,m-1,n-1)});
}
int editDistace(string &s1,string &s2) {
    return editDistanceRec(s1,s2,s1.size(),s2.size());
}
//time:O(3^(m+n)),space:O(m*n)

// Memoisation
int editDistanceRec(string &s1,string &s2,int m,int n,vector<vector<int>> &memo) {
    if (m==0) return n;
    if (n==0) return m;
    if (memo[m][n]!=-1) return memo[m][n];
    if (s1[m-1]==s2[n-1]) return memo[m][n]=editDistanceRec(s1,s2,m-1,n-1,memo);
    return memo[m][n]=1+min({editDistanceRec(s1,s2,m,n-1,memo),editDistanceRec(s1,s2,m-1,n,memo),editDistanceRec(s1,s2,m-1,n-1,memo)});
}
int editDistance(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<vector<int>> memo(m+1,vector<int> (n+1,-1));
    return editDistanceRec(s1,s2,m,n,memo);
}
//time:O(m*n),space:O(m*n)

// Tabulation
int editDistance(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<vector<int>> dp(m+1,vector<int> (n+1));
    for (int i=0;i<=m;i++) dp[i][0]=i;
    for (int j=0;j<=n;j++) dp[0][j]=j;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
        }
    }
    return dp[m][n];
}
//time:O(m*n),space:O(n)

// Space-optimised DP
int editDistance(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<int> prev(n+1,0),curr(n+1,0);
    for (int j=0;j<n;j++) prev[j]=j;
    for (int i=1;i<=m;i++) {
        curr[0]=i;
        for (int j=1;j<=n;j++) {
            if (s1[i-1]==s2[j-1]) curr[j]=prev[j-1];
            else curr[j]=1+min({prev[j-1],prev[j],curr[j-1]});
        }
        prev=curr;
    }
    return prev[n];
}
//time:O(m*n),sapce:O(n)