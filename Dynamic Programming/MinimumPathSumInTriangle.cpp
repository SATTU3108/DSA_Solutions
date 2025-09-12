#include <bits/stdc++.h>
using namespace std;

/*
Given a triangular array, find the minimum path sum from top to bottom. For each step, we can move to the adjacent numbers of the row below. i.e., if we are on an index i of the current row, we can move to either index i or index i + 1 on the next row.
*/

// Recursion
int minSumPathRec(vector<vector<int>> &triangle,int i,int j) {
    if (i==triangle.size()) return 0;
    return triangle[i][j]+min(minSumPathRec(triangle,i+1,j),minSumPathRec(triangle,i+1,j+1));
}
int minSumPath(vector<vector<int>> &triangle) {
    return minSumPathRec(triangle,0,0);
}
//time:O(2^(n^2)),space:O(n)

// Memoisation
int helperFunc(vector<vector<int>> &triangle,int i,int j,vector<vector<int>> &memo) {
    if (i==triangle.size()) return 0;
    if (memo[i][j]!=-1) return memo[i][j];
    return memo[i][j]=triangle[i][j]+min(helperFunc(triangle,i+1,j,memo),helperFunc(triangle,i+1,j=1,memo));
}
int minSumPath(vector<vector<int>> &triangle) {
    int n=triangle.size();
    vector<vector<int>> memo(n,vector<int> (n,-1));
    return helperFunc(triangle,0,0,memo);
}
//time:O(n^2),space:O(1)

// Tabulation
int minSumPath(vector<vector<int>> &triangle) {
    int n=triangle.size();
    vector<vector<int>> dp(n,vector<int> (n));
    for (int i=0;i<n;i++) dp[n-1][i]=triangle[n-1][i];
    for (int i=n-2;i>=0;i--) {
        for (int j=0;j<triangle[i].size();j++) {
            dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}
//time:O(n^2),space:O(n^2)

// Space-optimised 
int minSumPath(vector<vector<int>> &triangle) {
    int n=triangle.size();
    vector<int> dp(n);
    for (int i=0;i<n;i++) dp[i]=triangle[n-1][i];
    for (int i=triangle.size()-2;i>=0;i--) {
        for (int j=0;j<triangle[i].size();j++) {
            dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
        }
    }
    return dp[0];
}
//time:O(n^2),space:O(n)