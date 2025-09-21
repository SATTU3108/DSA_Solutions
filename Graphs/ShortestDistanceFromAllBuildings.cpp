/*
Problem Description
You have an m x n grid where each cell contains one of three values:

0: Empty land that you can walk through freely
1: A building that you cannot pass through
2: An obstacle that you cannot pass through
Your goal is to find the best location on an empty land (a cell with value 0) to build a house such that the total travel distance from this house to all buildings is minimized.

Movement is restricted to four directions: up, down, left, and right (no diagonal movement).

The total travel distance is calculated as the sum of the shortest path distances from your chosen location to each building in the grid. The distance between cells is measured using the Manhattan distance (number of steps needed when moving only horizontally or vertically).

Return the minimum total travel distance if it's possible to find such a location that can reach all buildings. If no valid location exists (for example, if some buildings are unreachable from any empty land), return -1.

Example scenario: If there are 3 buildings in the grid and you choose an empty cell, you need to calculate the shortest path from that cell to each of the 3 buildings, then sum these distances. The answer would be the empty cell that gives you the smallest sum.

Key constraints:

You can only build on empty land (cells with 0)
The chosen location must be able to reach ALL buildings in the grid
Obstacles and buildings block movement paths
*/

#include <bits/stdc++.h>
using namespace std;

int shortestDistance(vector<vector<int>> &grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> total_dist(m,vector<int> (n,0));
    vector<vector<int>> count(m,vector<int> (n,0));
    int total_buildings=0;
    vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j]==1) {
                total_buildings++;
                vector<vector<bool>> visited(m,vector<bool> (n,false));
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j]=true;
                int dist=0;
                while (!q.empty()) {
                    int size=q.size();
                    dist++;
                    for (int s=0;s<size;s++) {
                        int x=q.front().first,y=q.front().second;
                        q.pop();
                        for (auto &d:dirs) {
                            int nx=x+d.first;
                            int ny=y+d.second;
                            if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0 && !visited[nx][ny]) {
                                visited[nx][ny]=true;
                                total_dist[nx][ny]+=dist;
                                count[nx][ny]++;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
    }
    int shortest=INT_MAX;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j]==0 && count[i][j]==total_buildings) shortest=min(shortest,total_dist[i][j]);
        }
    }
    return (shortest==INT_MAX) ? -1:shortest;
}
//time:O(m*n*b),space:O(m*n)
