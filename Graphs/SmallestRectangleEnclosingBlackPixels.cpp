#include <bits/stdc++.h>
using namespace std;

// BFS approach
int minArea(vector<vector<int>> &image,int x,int y) {
    int m=image.size(),n=image[0].size();
    vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    pair<int,int> top_left={x,y},bottom_right={x,y};
    queue<pair<int,int>> q;
    q.push({x,y});
    image[x][y]=2; // mark the pixel as visited
    while (!q.empty()) {
        int i=q.front().first,j=q.front().second;
        q.pop();
        for (int k=0;k<4;k++) {
            int nr=i+dirs[k].first;
            int nc=j+dirs[k].second;
            if (nr<0 || nc>=m || nc<0 || nc>=n || image[nr][nc]!=1) continue;
            top_left.first=min(top_left.first,nr);
            top_left.second=min(top_left.second,nc);
            bottom_right.first=max(bottom_right.first,nr);
            bottom_right.second=max(bottom_right.second,nc);
            q.push({nr,nc});
            image[nr][nc]=2;
        } 
    }
    int width=bottom_right.second-top_left.second+1;
    int height=bottom_right.first-top_left.first+1;
    return width*height;
}
//time:O(m*n),space:O(m*n)

// Binary Search approach
int minArea(vector<vector<int>> &image,int x,int y) {
    int m=image.size(),n=image[0].size();
    // binary search for top boundary
    int top=0,bottom=x;
    while (top<bottom) {
        int mid=top+(bottom-top+1)/2;
        bool found_black=false;
        for (int col=0;col<n;col++) {
            if (image[mid][col]==1) {
                found_black=true;
                break;
            }
        }
        if (found_black) bottom=mid;
        else top=mid+1;
    }
    int upper=top;
    // binary seach for bottom boundary
    top=x,bottom=m-1;
    while (top<bottom) {
        int mid=top+(bottom-top+1)/2;
        bool found_black=false;
        for (int col=0;col<n;col++) {
            if (image[mid][col]==1) {
                found_black=true;
                break;
            }
        }
        if (found_black) top=mid;
        else bottom=mid-1;
    }
    int lower=top;
    // binary search for left boundary
    int left=0,right=y;
    while (left<right) {
        int mid=left+(right-left+1)/2;
        bool found_black=false;
        for (int row=0;row<m;row++) {
            if (image[row][mid]==1) {
                found_black=true;
                break;
            }
        }
        if (found_black) right=mid;
        else left=mid+1;
    }
    int left_most=left;
    // binary search for right boundary
    left=y,right=n-1;
    while (left<right) {
        int mid=left+(right-left+1)/2;
        bool found_black=false;
        for (int row=0;row<m;row++) {
            if (image[row][mid]==1) {
                found_black=true;
                break;
            }
        }
        if (found_black) left=mid;
        else right=mid-1;
    }
    int right_most=left;
    int width=right_most-left_most+1;
    int height=lower-upper+1;
    return width*height;
}
//time:O(mlogn+nlogm),space:O(1)
