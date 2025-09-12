#include <bits/stdc++.h>
using namespace std;

/*
Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
*/

// Approach 1 - Brute-force
/*
1. For every 0, mark all cells of tis row and columns as -1, except the ones that are 0
2. After all 0 are visited, do traversal again and convert -1 to 0
*/
void markRow(vector<vector<int>> &matrix,int n,int m,int i) {
    for (int j=0;j<m;j++) {
        if (matrix[i][j]!=0) matrix[i][j]=-1;
    }
}
void markCol(vector<vector<int>> &matrix,int n,int m,int j) {
    for (int i=0;i<n;i++) {
        if (matrix[i][j]!=0) matrix[i][j]=-1;
    }
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix,int n,int m) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (matrix[i][j]==0) {
                markRow(matrix,n,m,i);
                markCol(matrix,n,m,j);
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (matrix[i][j]==-1) matrix[i][j]=0;
        }
    }
    return matrix;
}
//time:O((n*m)(n+m))+O(n*m),space:O(1)

// Approach 2 -> Using row and column vectors
/*
1. if any cell (i,j) is 0, then push i into row vector and j into column vector
2. then after that, if a row number is there, mark the full row as 0. similar case for column
*/
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix,int n,int m) {
    vector<bool> row(n,false),col(m,false);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (matrix[i][j]==0) {
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (row[i]==true || col[j]==true) matrix[i][j]=0;
        }
    }
    return matrix;
}
//time:O(n*m)+O(n*m)=O(n*m)
//space:O(n)+O(m)=O(n+m)

// This can be done in the matrix itself, by using the first row and the first column itself