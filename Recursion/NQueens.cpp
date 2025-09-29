/*
Given an integer n, place n queens on an n × n chessboard such that no two queens attack each other. A queen can attack another queen if they are placed in the same row, the same column, or on the same diagonal.

Find all possible distinct arrangements of the queens on the board that satisfy these conditions.

The output should be an array of solutions, where each solution is represented as an array of integers of size n, and the i-th integer denotes the column position of the queen in the i-th row. If no solution exists, return an empty array.
*/

#include <bits/stdc++.h>
using namespace std;

// brute-force approach -> backtracking
bool isSafe(vector<vector<int>> &mat,int row,int col) {
    int n=mat.size();
    // check this column on upper side
    for (int i=0;i<row;i++) {
        if (mat[i][col]) return false;
    }
    // check upper diagonal on left side
    for (int i=row-1,j=col-1;i>=0 && j>=0;i--,j--) {
        if (mat[i][j]) return false;
    }
    // check upper diagonal on right side
    for (int i=row-1,j=col+1;i>=0 && j<n;i--,j++) {
        if (mat[i][j]) return false;
    }
    return true;
}
void placeQueens(int row,vector<vector<int>> &mat,vector<vector<int>> &result) {
    int n=mat.size();
    if (row==n) {
        vector<int> ans;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (mat[i][j]) ans.push_back(j+1);
            }
        }
        result.push_back(ans);
        return;
    }
    for (int i=0;i<n;i++) {
        if (isSafe(mat,row,i)) {
            mat[row][i]=1;
            placeQueens(row+1,mat,result);
            // backtrack
            mat[row][i]=0;
        }
    }
}
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> mat(n,vector<int> (n,0));
    vector<vector<int>> result;
    placeQueens(0,mat,result);
    return result;
}
//time:O(n!),space:O(n^2)

// better approach -> hashing for space efficiency
void placeQueens(int row,int n,vector<int> &ans,vector<vector<int>> &result,vector<bool> &col,vector<bool> &diag1,vector<bool> &diag2) {
    if (row==n) {
        result.push_back(ans);
        return;
    }
    for (int c=0;c<n;c++) {
        if (!col[c] && !diag1[row+c] && !diag2[row-c+n-1]) {
            ans[row]=c+1;
            col[c]=diag1[row+c]=diag2[row-c+n-1]=true;
            placeQueens(row+1,n,ans,result,col,diag1,diag2);
            col[c]=diag1[row+c]=diag2[row-c+n-1]=false;
        }
    }
}
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> result;
    vector<int> ans(n);
    vector<bool> col(n,false),diag1(2*n-1,false),diag2(2*n-1,false);
    placeQueens(0,n,ans,result,col,diag1,diag2);
    return result;
}
