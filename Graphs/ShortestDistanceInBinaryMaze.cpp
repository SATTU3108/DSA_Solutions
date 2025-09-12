#include <bits/stdc++.h>
using namespace std;

/*
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.
*/

bool isValid(int rows,int cols,int x,int y) {
    return (x>=0 && x<rows && y>=0 && y<cols);
}
int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    if (source.first==destination.first && source.second==destination.second) return 0;
    if (grid[source.first][source.second]==0 || grid[destination.first][destination.second]==0) return -1;
    int rows=grid.size(),cols=grid[0].size();
    vector<vector<int>> dist(rows,vector<int> (cols,1e8));
    dist[source.first][source.second]=0;
    queue<vector<int>> q;
    q.push({source.first,source.second,0});
    int delX[]={1,0,-1,0};
    int delY[]={0,1,0,-1};
    while (!q.empty()) {
        int x=q.front()[0],y=q.front()[1],dis=q.front()[2];
        q.pop();
        if (x==destination.first && y==destination.second) return dis;
        for (int i=0;i<4;i++) {
            int nx=x+delX[i],ny=y+delY[i];
            if (isValid(rows,cols,nx,ny) && grid[nx][ny]==1 && dist[nx][ny]==1e8) {
                dist[nx][ny]=dis+1;
                q.push({nx,ny,dis+1});
            }
        }
    }
    return -1;
}