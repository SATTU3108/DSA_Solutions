#include <bits/stdc++.h>
using namespace std;

/*
Given a matrix, your task is to rotate the matrix 90 degrees clockwise.
*/

// Brute-force approach -> dummy matrix
vector<vector<int>> rotate(vector<vector<int>> &matrix) {
    int n=matrix.size();
    vector<vector<int>> rotated(n,vector<int> (n,0));
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) rotated[j][n-i-1]=matrix[i][j];
    }
    return rotated;
}
//time:O(n^2),space:O(n^2)

// Optimal Approach
vector<vector<int>> rotate(vector<vector<int>> &matrix) {
    int n=matrix.size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for (int i=0;i<n;i++) {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}