#include <bits/stdc++.h>
using namespace std;

/*
You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form
*/

vector<int> spirallyTraverse(vector<vector<int>> matrix,int r,int c) {
    vector<int> res;
    int top=0,left=0,bottom=r-1,right=c-1;
    while (left<=right && top<=bottom) {
        for (int i=left;i<=right;i++) res.push_back(matrix[top][i]);
        top++;
        for (int i=top;i<=bottom;i++) res.push_back(matrix[i][right]);
        right--;
        if (top<=bottom) {
            for (int i=right;i>=left;i--) res.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left<=right) {
            for (int i=bottom;i>=top;i--) res.push_back(matrix[i][left]);
            left++;
        }
    }
    return res;
} 