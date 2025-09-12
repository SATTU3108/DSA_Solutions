#include <bits/stdc++.h>
using namespace std;

/*
Given a square chessboard of n x n size, the position of the Knight and the position of a target are given. We need to find out the minimum steps a Knight will take to reach the target position.
*/

// BFS
bool isInside(int x,int y,int n) {
    return (x>=1 && x<=n && y>=1 && y<=n);
}
int minSteps(int knightPos[],int targetPos[],int n) {
    int dx[]={1,2,-1,-2,1,-2,2,-1};
    int dy[]={2,1,-2,-1,-2,1,-1,2};
    queue<tuple<int,int,int>> q;
    q.push({knightPos[0],knightPos[1],0});
    vector<vector<bool>> visit(n+1,vector<bool> (n+1,false));
    visit[knightPos[0]][knightPos[1]]=true;
    while (!q.empty()) {
        int x=get<0>(q.front()),y=get<1>(q.front()),dis=get<2>(q.front());
        q.pop();
        if (x==targetPos[0] && y==targetPos[1]) return dis;
        for (int i=0;i<8;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (isInside(nx,ny,n) && !visit[nx][ny]) {
                visit[nx][ny]=true;
                q.push({nx,ny,dis+1});
            }
        }
    }
    return -1;
}
//time:O(n^2),space:O(n^20)