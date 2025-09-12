#include <bits/stdc++.h>
using namespace std;

/*
ou will be given an m x n grid, where each cell has the following values : 

2  -  represents a rotten orange
1  -  represents a Fresh orange
0  -  represents an Empty Cell
Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward, downwards, right, and left ) it becomes Rotten. 

Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1.
*/

// BFS approach
int orangesRotting(vector<vector<int>> &grid) {
    if (grid.empty()) return 0;
    int m=grid.size(),n=grid[0].size();
    int total=0;
    queue<pair<int,int>> q;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j]!=0) total++;
            if (grid[i][j]==2) q.push({i,j});
        }
    }
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int count=0,days=0;
    while (!q.empty()) {
        int k=q.size();
        count+=k;
        for (int i=0;i<k;i++) {
            int x=q.front().first,y=q.front().second;
            q.pop();
            for (int j=0;j<4;j++) {
                int nx=x+dx[j],ny=y+dy[i];
                if (nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1) continue;
                grid[nx][ny]=2;
                q.push({nx,ny});
            }
        }
        if (!q.empty()) days++;
    }
    if (count==total) return days;
    else return -1;
}