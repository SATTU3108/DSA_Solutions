#include <bits/stdc++.h>
using namespace std;

/*
iven a binary grid of N*M. Find the distance of the nearest 1 in the grid for each cell.

The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
*/

vector<vector<int>> nearest(vector<vector<int>> &grid) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    vector<vector<int>> dist(n,vector<int> (m,0));
    queue<tuple<int,int,int>> q;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j]==1) {
                q.push({i,j,0});
                vis[i][j]=true;
            }
        }
    }
    int delRow[]={1,0,-1,0};
    int delCol[]={0,1,0,-1};
    while (!q.empty()) {
        int row=get<0>(q.front());
        int col=get<1>(q.front());
        int steps=get<2>(q.front());
        q.pop();
        dist[row][col]=steps;
        for (int i=0;i<4;i++) {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==false) {
                vis[nrow][ncol]=true;
                q.push({nrow,ncol,steps+1});
            }
        }
    }
    return dist;
}