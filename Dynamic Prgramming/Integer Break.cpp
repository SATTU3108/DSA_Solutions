/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.
*/

int integerBreak(int n) {
  vector <int> dp(n+1,0);
  if (n==2) return 1;
  dp[1]=1;
  for (int i=2;i<=n;i++) {
      for (int j=1;j<i;j++) dp[i]=max({dp[i],j*(i-j),j*dp[i-j]});
  }
  return dp[n];
}
//Time complexity:O(N^2),Space complexity:O(N)
