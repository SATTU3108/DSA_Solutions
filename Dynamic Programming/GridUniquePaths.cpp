#include <bits/stdc++.h>
using namespace std;

/*
Given an matrix of size m x n, the task is to find the count of all unique possible paths from top left to the bottom right with the constraints that from each cell we can either move only to the right or down.
*/

// Recursion
int numberOfPaths(int m,int n) {
    if (m==1 || n==1) return 1;
    return numberOfPaths(m-1,n)+numberOfPaths(m,n-1);
}
//time:O(2^(m+n),space:O(m+n)

// Memoisation
int countPaths(int m,int n,vector<vector<int>> &memo) {
    if (n==1 || m==1) return 1;
    if (memo[m][n]!=-1) return memo[m][n];
    return memo[m][n]=countPaths(m-1,n,memo)+countPaths(m,n-1,memo);
}
int numberOfPaths(int m,int n) {
    vector<vector<int>> memo(m+1,vector<int> (n+1,-1));
    return countPaths(m,n,memo);
}
//time:O(m*n),space:O(m*n)

// Tabulation
int numberOfPaths(int m,int n) {
    vector<vector<int>> dp(m,vector<int> (n));
    for (int i=0;i<m;i++) dp[i][0]=1;
    for (int j=0;j<n;j++) dp[0][j]=1;
    for (int i=1;i<m;i++) {
        for (int j=1;j<n;j++) {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
//time:O(m*n),space:O(m*n)


/*
Given a matrix mat[][] of size n * m, where mat[i][j] = 1 indicates an obstacle and mat[i][j] = 0 indicates an empty space. The task is to find the number of unique paths to reach (n-1, m-1) starting from (0, 0). You are allowed to move in the right or downward direction.

Note: In the grid, cells marked with 1 represent obstacles, and 0 represent free space. Movement is restricted to only right (i, j+1) or down (i+1, j) from the current cell (i, j).
*/

// Recursion
int uniquePathsRecur(int i,int j,vector<vector<int>> &grid) {
    int r=grid.size(),c=grid[0].size();
    if (i==r || j==c) return 0;
    if (grid[i][j]==1) return 0;
    if (i==r-1 && j==c-1) return 1;
    return uniquePathsRecur(i+1,j,grid)+uniquePathsRecur(i,j+1,grid);
}

// Memoisation
int uniquePathsRecur(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &memo) {
    int r=grid.size(),c=grid[0].size();
    if (i==r || j==c) return 0;
    if (grid[i][j]==1) return 0;
    if (i==r-1 && j==c-1) return 1;
    if (memo[i][j]!=-1) return memo[i][j];
    return memo[i][j]=uniquePathsRecur(i+1,j,grid,memo)+uniquePathsRecur(i,j+1,grid,memo);
}
int uniquePaths(vector<vector<int>> &grid) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>> memo(n,vector<int> (m,-1));
    return uniquePathsRecur(0,0,grid,memo);
}
//time:O(m*n),space:O(m*n)

// Tabulation
int uniquePaths(vector<vector<int>> &grid) {
    int n=grid.size(),m=grid[0].size();
    // if starting or ending cell is an obstacle
    if (grid[0][0]==1 ||grid[n-1][m-1]==1) return 0;
    vector<vector<int>> dp(n,vector<int> (m,0));
    dp[n-1][m-1]=1;
    // Fill the bottom row
    for (int j=m-2;j>=0;j--) {
        if (grid[n-1][j]==1) break;
        else dp[n-1][j]=1;
    }
    // Fill the rightmost column
    for (int i=n-2;i>=0;i--) {
        if (grid[i][m-1]==1) break;
        else dp[i][m-1]=1;
    }
    // Fill the inner cells bottom up and right left
    for (int i=n-2;i>=0;i--) {
        for (int j=m-2;j>=0;j--) {
            if (grid[i][j]==0) {
                dp[i][j]=dp[i+1][j]+dp[j+1][i];
            }
        }
    }
    return dp[0][0];
}
//time:O(m*n),space:O(m*n)