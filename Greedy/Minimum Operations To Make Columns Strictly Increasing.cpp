/*
You are given a m x n matrix grid consisting of non-negative integers.
In one operation, you can increment the value of any grid[i][j] by 1.
Return the minimum number of operations needed to make all columns of grid strictly increasing.
*/

int minimumOperations(vector<vector<int>>& grid) {
  int rows=grid.size(),cols=grid[0].size();
  int ans=0;
  for (int j=0;j<cols;j++) {
      int col_ops=0;
      for (int i=1;i<rows;i++) {
          int diff=grid[i][j]-grid[i-1][j]-1;
          if (diff<=0) {
              diff=-diff;
              grid[i][j]+=diff;
              col_ops+=diff;
          }
      }
      ans+=col_ops;
  }
  return ans;
}
//Time Complexity:O(N),Space Complexity:O(1)
