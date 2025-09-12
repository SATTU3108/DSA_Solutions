#include <bits/stdc++.h>
using namespace std;

// DFS approach
void dfs(int row,int col,vector<vector<bool>> &vis,vector<vector<char>> &mat,int delRow[],int delCol[]) {
    int n=mat.size(),m=mat[0].size();
    vis[row][col]=true;
    for (int i=0;i<4;i++) {
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='0') dfs(nrow,ncol,vis,mat,delRow,delCol);
    }
}
vector<vector<char>> fill(int n,int m,vector<vector<char>> mat) {
    int delRow[]={1,0,-1,0};
    int delCol[]={0,1,0,-1};
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    for (int j=0;j<m;j++) {
        if (!vis[0][j] && mat[0][j]=='0') dfs(0,j,vis,mat,delRow,delCol);
        if (!vis[n-1][j] && mat[n-1][j]=='0') dfs(n-1,j,vis,mat,delRow,delCol);
    }
    for (int i=0;i<n;i++) {
        if (!vis[i][0] && mat[i][0]=='0') dfs(i,0,vis,mat,delRow,delCol);
        if (!vis[i][m-1] && mat[i][m-1]=='0') dfs(i,m-1,vis,mat,delRow,delCol);
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!vis[i][j] && mat[i][j]=='0') mat[i][j]='X';
        }
    }
    return mat;
}