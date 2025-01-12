/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
*/

int numTrees(int n) {
  vector <int> dp(n+1,0);
  dp[0]=1;
  for (int nodes=1;nodes<=n;nodes++) {
      for (int left=0;left<nodes;left++) {
          int right=nodes-left-1;
          dp[nodes]+=dp[left]*dp[right];
      }
  }
  return dp[n];
}
//Time complexity:O(N),Space complexity:O(N)
