#include <bits/stdc++.h>
using namespace std;

/*
Given an n x m grid of 'W' (Water) and 'L' (Land), the task is to count the number of islands. An island is a group of adjacent 'L' cells connected horizontally, vertically, or diagonally, and it is surrounded by water or the grid boundary. The goal is to determine how many distinct islands exist in the grid.
*/

// DFS approach
void dfs(vector<vector<char>> &grid,int r,int c) {
    int row=grid.size(),col=grid[0].size();
    if (r<0 || c<0 || r>=row || c>=col || grid[r][c]!='L') return;
    grid[r][c]='W';
    vector<int> row_neighbours={1,1,0,-1,-1,-1,0,1};
    vector<int> col_neighbours={0,1,1,1,0,-1,-1,-1};
    for (int i=0;i<8;i++) {
        int new_row=r+row_neighbours[i];
        int new_col=c+col_neighbours[i];
        dfs(grid,new_row,new_col);
    }
}
int countIslands(vector<vector<char>> &grid) {
    int row=grid.size(),col=grid[0].size();
    int count=0;
    for (int r=0;r<row;r++) {
        for (int c=0;c<col;c++) {
            if (grid[r][c]=='L') {
                count++;
                dfs(grid,r,c);
            }
        }
    }
    return count;
}

// BFS Approach
bool isSafe(vector<vector<char>> &grid,int r,int c) {
    int rows=grid.size(),cols=grid[0].size();
    return r>=0 && r<rows && c>=0 && c<cols && grid[r][c]=='L';
}
void bfs(vector<vector<char>> &grid,int sr,int sc) {
    vector<int> row_neighbours={1,1,0,-1,-1,-1,0,1};
    vector<int> col_neighbours={0,1,1,1,0,-1,-1,-1};
    queue<pair<int,int>> q;
    q.push({sr,sc});
    grid[sr][sc]='W';
    while (!q.empty()) {
        int r=q.front().first,c=q.front().second;
        q.pop();
        for (int k=0;k<8;k++) {
            int new_row=r+row_neighbours[k];
            int new_col=c+col_neighbours[k];
            if (isSafe(grid,new_row,new_col)) {
                grid[new_row][new_col]='W';
                q.push({new_row,new_col});
            }
        }
    }
}
int countIslands(vector<vector<char>> &grid) {
    int rows=grid.size(),cols=grid[0].size();
    int count=0;
    for (int r=0;r<rows;r++) {
        for (int c=0;c<cols;c++) {
            if (grid[r][c]=='L') {
                bfs(grid,r,c);
                count++;
            }
        }
    }
    return count;
}