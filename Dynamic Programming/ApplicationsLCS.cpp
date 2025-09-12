#include <bits/stdc++.h>
using namespace std;

/*
LCS of three strings
*/

// Recursion
int findLCSOf3(string &s1,string &s2,string &s3,int n1,int n2,int n3) {
    if (n1==0 || n2==0 || n3==0) return 0;
    if (s1[n1-1]==s2[n2-1] && s2[n2-1]==s3[n3-1]) return 1+findLCSOf3(s1,s2,s3,n1-1,n2-1,n3-1);
    return max({findLCSOf3(s1,s2,s3,n1,n2,n3-1),findLCSOf3(s1,s2,s3,n1,n2-1,n3),findLCSOf3(s1,s2,s3,n1-1,n2,n3)});
}
int lcsOf3(string &s1,string &s2,string &s3) {
    int n1=s1.size(),n2=s2.size(),n3=s3.size();
    int res=findLCSOf3(s1,s2,s3,n1,n2,n3);
}

// Memoisation
int findLCSOf3(string &s1,string &s2,string &s3,int n1,int n2,int n3,vector<vector<vector<int>>> &memo) {
    if (n1==0 || n2==0 || n3==0) return 0;
    if (memo[n1][n2][n3]!=-1) return memo[n1][n2][n3];
    if (s1[n1-1]==s2[n2-1] && s2[n2-1]==s3[n3-1]) return memo[n1][n2][n3]=1+findLCSOf3(s1,s2,s3,n1-1,n2-1,n3-1,memo);
    return memo[n1][n2][n3]=max({findLCSOf3(s1,s2,s3,n1,n2,n3-1),findLCSOf3(s1,s2,s3,n1,n2-1,n3),findLCSOf3(s1,s2,s3,n1-1,n2,n3)});
}
int lcsOf3(string &s1,string &s2,string &s3) {
    int n1=s1.size(),n2=s2.size(),n3=s3.size();
    vector<vector<vector<int>>> memo(n1+1,vector<vector<int>> (n2+1,vector<int> (n3+1,-1)));
    int res=findLCSOf3(s1,s2,s3,n1,n2,n3,memo);
}

// Tabulation
int lcsOf3(string &s1,string &s2,string &s3) {
    int n1=s1.size(),n2=s2.size(),n3=s3.size();
    int dp[n1+1][n2+1][n3+1];
    for (int i=0;i<=n1;i++) {
        for (int j=0;j<=n2;j++) {
            for (int k=0;k<=n3;k++) {
                if (i==0 || j==0 || k==0) dp[i][j][k]=0;
                else if (s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]) dp[i][j][k]=1+dp[i-1][j-1][k-1];
                else dp[i][j][k]=max({dp[i][j][k-1],dp[i][j-1][k],dp[i-1][j][k]});
            }
        }
    }
    return dp[n1][n2][n3];
}

// Space-optimised tabulation
int lcsOf3(string &s1,string &s2,string &s3) {
    int n1=s1.size(),n2=s2.size(),n3=s3.size();
    vector<vector<int>> prev(n2+1,vector<int> (n3+1,0));
    vector<vector<int>> curr(n2+1,vector<int> (n3+1));
    for (int i=1;i<=n1;i++) {
        for (int j=1;j<=n2;j++) {
            for (int k=1;k<=n3;k++) {
                if (s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]) curr[j][k]=1+prev[j-1][k-1];
                else curr[j][k]=max({prev[j][k],curr[j-1][k],curr[j][k-1]});
            }
        }
        prev=curr;
    }
    return prev[n2][n3];
}

/*
Longest Palindromic Subsequence(LPS)
*/

// Recursion
int lps(string &s,int low,int high) {
    if (low>high) return 0;
    if (low==high) return 1;
    if (s[low]==s[high]) return (2+lps(s,low+1,high-1));
    return max(lps(s,low,high-1),lps(s,low+1,high));
}
int longestPalindromicSubsequence(string &s) {
    return lps(s,0,s.size()-1);
}

// Memoisation
int lps(string &s,int low,int high,vector<vector<int>> &memo) {
    if (low>high) return 0;
    if (low==high) return 1;
    if (memo[low][high]!=-1) return memo[low][high];
    if (s[low]==s[high]) return memo[low][high]=lps(s,low+1,high-1,memo)+2;
    return memo[low][high]=max(lps(s,low,high-1,memo),lps(s,low+1,high,memo));
}
int longestPalindromicSubsequence(string &s) {
    int n=s.size();
    vector<vector<int>> memo(n,vector<int> (n,-1));
    return lps(s,0,n-1,memo);
}

// Tabulation
int longestPalindromicSubsequence(string &s) {
    int n=s.length();
    vector<vector<int>> dp(n,vector<int> (n));
    for (int i=n-1;i>=0;i--) {
        for (int j=i;j<n;j++) {
            if (i==j) {
                dp[i][j]=1;
                continue;
            }
            if (s[i]==s[j]) {
                if ((i+1)==j) dp[i][j]=2;
                else dp[i][j]=dp[i+1][j-1]+2;
            }
            else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

// Using LCS
int lcs(string &s1,string &s2) {
    int m=s1.length(),n=s2.length();
    vector<int> prev(n+1,0),curr(n+1,0);
    for (int i=1;i<=m;i++) {
        for (int j=1;j<+n;j++) {
            if (s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[n];
}
int longestPalindromicSubsequence(string &s) {
    string t=s;
    reverse(t.begin(),t.end());
    return lcs(s,t);
}
