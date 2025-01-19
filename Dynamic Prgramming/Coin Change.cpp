/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
*/  

int coinChange(vector<int>& coins, int amount) {
  vector <int> dp(amount+1,1e5);
  dp[0]=0;
  for (int i=1;i<=amount;i++) {
      for (int coin:coins) {
          if (i>=coin) dp[i]=min(dp[i],dp[i-coin]+1);
      }
  }
  if (dp[amount]==1e5) return -1;
  return dp[amount];
}
//Time complexity:O(amount*n),Space complexity:O(amount)
