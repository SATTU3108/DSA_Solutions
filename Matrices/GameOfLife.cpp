#include <bits/stdc++.h>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int m=board.size(),n=board[0].size();
    vector<vector<int>> copyBoard=board; // duplicate board
    // directions for 8 neighbours
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            int live_neighbours=0;
            for (int k=0;k<8;k++) {
                int nx=i+dir[k].first;
                int ny=j+dir[k].second;
                if (nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]==1) live_neighbours++;
            }
            if (board[i][j]==1) {
                if (live_neighbours<2 || live_neighbours>3) copyBoard[i][j]=0; 
                // else remains alive, no change needed
            }
            else {
                if (live_neighbours==3) copyBoard[i][j]=1;
            }
        }
    }
    board=copyBoard; // update the original board with new state
}
//time:O(m*n),space:O(m*n)

/*
Above space complexity of using a duplicate matrix can be removed if we do in-place state encoding
00=0:state moves from 0 to 0 (dead->dead)
10=2:state moves from 0 to 1(dead->live)
11=3:state moves from 1 to 1(live->live)
01=1:state moves from 1 to 0(live->dead)
*/

void gameOfLife(vector<vector<int>> &board) {
    int m=board.size(),n=board[0].size();
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            int live_neighbours=0;
            for (int k=0;k<8;k++) {
                int nx=i+dir[k].first;
                int ny=j+dir[k].second;
                if (nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]&1==1) live_neighbours++;
            }
            if ((board[i][j]&1)==1) {
                if (live_neighbours==2 || live_neighbours==3) board[i][j]=3;
            }
            else {
                if (live_neighbours==3) board[i][j]=2;
            }
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            board[i][j]>>=1;
        }
    }
}
//time:O(m*n),space:O(1)
