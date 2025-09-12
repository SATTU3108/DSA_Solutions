#include <bits/stdc++.h>
using namespace std;

/*
You are given a 2D grid image[][], where each image[i][j] represents the color of a pixel in the image. Also provided is a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color and the color of all connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.
*/

// DFS Approach
void dfs(vector<vector<int>> &image,int x,int y,int oldColor,int newColor) {
    if (x<0 || x>=image.size() || y<0 || y>=image[0].size() || image[x][y]!=oldColor) return;
    image[x][y]=newColor;
    dfs(image,x+1,y,oldColor,newColor);
    dfs(image,x-1,y,oldColor,newColor);
    dfs(image,x,y+1,oldColor,newColor);
    dfs(image,x,y-1,oldColor,newColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image,int sr,int sc, int newColor) {
    if (image[sr][sc]==newColor) return image;
    int oldColor=image[sr][sc];
    dfs(image,sr,sc,oldColor,newColor);
    return image;
}

// BFS Approach
vector<vector<int>> floodFill(vector<vector<int>> &image,int sr,int sc,int newColor) {
    if (image[sr][sc]==newColor) return image;
    vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,int>> q;
    int oldColor=image[sr][sc];
    q.push({sr,sc});
    image[sr][sc]=newColor;
    while (!q.empty()) {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for (auto dir:directions) {
            int nx=x+dir.first,ny=y+dir.second;
            if (nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size() && image[nx][ny]==oldColor) {
                image[nx][ny]=newColor;
                q.push({nx,ny});
            }
        }
    }
    return image;
}