#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &heights, queue<pair<int,int>> q,vector<vector<bool>> &visited) {
    int rows=heights.size(),cols=heights[0].size();
    vector<int> directions={-1,0,1,0,-1};
    while (!q.empty()) {
        auto [r,c]=q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int x=r+directions[i];
            int y=c+directions[i+1];
            if (x>=0 && x<rows && y>=0 && y<cols && !visited[x][y] && heights[x][y]>=heights[r][c]) {
                visited[x][y]=true;
                q.push({x,y});
            }
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows=heights.size(),cols=heights[0].size();
    queue<pair<int,int>> pacificQueue,atlanticQueue;
    vector<vector<bool>> pacificVisited(rows,vector<bool> (cols,false));
    vector<vector<bool>> atlanticVisited(rows,vector<bool> (cols,false));
    for (int i=0;i<rows;i++) {
        pacificQueue.push({i,0});
        pacificVisited[i][0]=true;
        atlanticQueue.push({i,cols-1});
        atlanticVisited[i][cols-1]=true;
    }
    for (int j=0;j<cols;j++) {
        pacificQueue.push({0,j});
        pacificVisited[0][j]=true;
        atlanticQueue.push({rows-1,j});
        atlanticVisited[rows-1][j]=true;
    }
    bfs(heights,pacificQueue,pacificVisited);
    bfs(heights,atlanticQueue,atlanticVisited);
    vector<vector<int>> ans;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (pacificVisited[i][j] && atlanticVisited[i][j]) ans.push_back({i,j});
        }
    }
    return ans;
}