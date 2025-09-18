/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/

#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix) {
    int m=matrix.size(),n=matrix[0].size();
    vector<vector<int>> dp(m,vector<int> (n,0));
    dp[0][0]=(matrix[0][0]=='1') ? 1:0;
    int largest=dp[0][0];
    for (int i=1;i<m;i++) {
        if (matrix[i][0]=='1') {
            dp[i][0]=1;
            largest=1;
        }
    }
    for (int j=1;j<n;j++) {
        if (matrix[0][j]=='1') {
            dp[0][j]=1;
            largest=1;
        }
    }
    for (int i=1;i<m;i++) {
        for (int j=1;j<n;j++) {
            if (matrix[i][j]=='1') {
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                largest=max(largest,dp[i][j]);
            }
        }
    }
    return largest*largest;
}
//time:O(m*n),sapce:O(m*n)

// Space-optimised DP
int maximalSquare(vector<vector<char>> &matrix) {
    int m=matrix.size(),n=matrix[0].size();
    vector<int> prev(n,0),curr(n,0);
    if (matrix[0][0]=='1') prev[0]=1;
    int largest=prev[0];
    for (int j=1;j<n;j++) {
        if (matrix[0][j]=='1') {
            prev[j]=1;
            largest=1;
        }
    }
    for (int i=1;i<m;i++) {
        for (int j=0;j<n;j++) curr[j]=0;
        if (matrix[i][0]=='1') {
            curr[0]=1;
            largest=max(largest,1);
        }
        for (int j=1;j<n;j++) {
            if (matrix[i][j]=='1') {
                curr[j]=1+min({prev[j],curr[j-1],prev[j-1]});
                largest=max(largest,curr[j]);
            }
        }
        prev=curr;
    }
    return largest*largest;
}
//time:O(m*n),space:O(n)
