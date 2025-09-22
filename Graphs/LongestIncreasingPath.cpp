#include <bits/stdc++.h>
using namespace std;

// recursion
int dfs(int i,int j,vector<vector<int>> &matrix) {
    int m=matrix.size(),n=matrix[0].size();
    int ans=1;
    vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    for (auto &d:dirs) {
        int x=i+d.first,y=j+d.second;
        if (x>=0 && x<m && y>=0 && y<n && matrix[x][y]>matrix[i][j]) ans=max(ans,1+dfs(x,y,matrix));
    }
    return ans;
}
int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m=matrix.size(),n=matrix[0].size();
    int ans=0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            ans=max(ans,dfs(i,j,matrix));
        }
    }
    return ans;
}
//time:O(4^m*n),space:O(m*n)

// memoisation
int dfs(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &memo) {
    if (memo[i][j]!=0) return memo[i][j];
    int m=matrix.size(),n=matrix[0].size();
    int ans=1;
    vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    for (auto &d:dirs) {
        int x=i+d.first,y=j+d.second;
        if (x>=0 && x<m && y>=0 && y<n && matrix[x][y]>matrix[i][j]) ans=max(ans,1+dfs(x,y,matrix,memo));
    }
    return memo[i][j]=ans;
}
int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m=matrix.size(),n=matrix[0].size();
    int ans=0;
    vector<vector<int>> memo(m,vector<int> (n,0));
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            ans=max(ans,dfs(i,j,matrix,memo));
        }
    }
    return ans;  
}
//time:O(m*n),sapce:O(m*n)
