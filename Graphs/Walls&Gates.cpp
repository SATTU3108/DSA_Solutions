/*
You are given a matrix having ‘N’ rows and ‘M’ columns. Each cell of the matrix can only contain three values as given below:

-1 -> It denotes a wall or an obstacle

0  -> It denotes a gate

2^31 - 1 =  2147483647 ( INF ) -> An infinitely large value  denotes the empty room.

For each empty room (denoted by INF), you have to refill it with the distance to its nearest gate. If none of the gates is reachable from an empty room then the value ‘INF’ will remain as it is.
*/

#include <bits/stdc++.h>
using namespace std;

// BFS approach
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    queue<pair<int,int>> q;
    // directions {right,up,left,down}
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    // push all gates into queue as starting point
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (a[i][j]==0) q.push({i,j});
        }
    }
    // bfs to fill distances for all empty rooms
    while (!q.empty()) {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for (int i=0;i<4;i++) {
            int nx=x+dir[i].first,ny=y+dir[i].second;
            // check bounds and onlu update if the neighbour is an empty room
            if (nx<0 || nx>=n || ny<0 || ny>=m || a[nx][ny]!=INT_MAX) continue;
            // update distances to nearest gate
            a[nx][ny]=1+a[x][y];
            q.push({nx,ny}); 
        }
    }
    return a; // return the updated grid with distances
}
