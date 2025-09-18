#include <bits/stdc++.h>
using namespace std;

int minTotalDistance(vector<vector<int>> &grid) {
    int rows=grid.size(),cols=grid[0].size();
    vector<int> row_indices,col_indices;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (grid[i][j]==1) {
                row_indices.push_back(i);
                col_indices.push_back(j);
            }
        }
    }
    sort(col_indices.begin(),col_indices.end());
    int median_row=row_indices[row_indices.size()/2];
    int median_col=col_indices[col_indices.size()/2];
    return calculateTotalDistance(row_indices,median_row)+calculateTotalDistance(col_indices,median_col);
}
int calculateTotalDistance(vector<int> &positions,int target_position) {
    int total_distance=0;
    for (int pos:positions) {
        total_distance+=abs(pos-target_position);
    }
    return total_distance;
}
//time:O(m*n*log(m*n)),space:O(m*n)
