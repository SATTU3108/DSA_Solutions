/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

int maxProfit(vector<int>& prices) {
  int n=prices.size();
  vector<vector<int>> dp(n+2,vector<int> (2,0));
  for (int ind=n-1;ind>=0;ind--) {
      for (int buy=0;buy<=1;buy++) {
          if (buy==0) dp[ind][buy]=max(0+dp[ind+1][0],-prices[ind]+dp[ind+1][1]);
          else dp[ind][buy]=max(0+dp[ind+1][1],prices[ind]+dp[ind+2][0]);
      } 
  }
  return dp[0][0];
}
//Time complexity:O(N),Space complexity:O(N)

int maxProfit(vector<int>& prices) {
  int n=prices.size();
  vector<int> curr(2,0),front1(2,0),front2(2,0);
  for (int ind=n-1;ind>=0;ind--) {
      for (int buy=0;buy<=1;buy++) {
          int profit=0;
          if (buy==0) profit=max(0+front1[0],-prices[ind]+front1[1]);
          else profit=max(0+front1[1],prices[ind]+front2[0]);
          curr[buy]=profit;
      }
      front2=front1;
      front1=curr;
  }
  return curr[0];
}
//Time complexity:O(N), Space complexity:O(1)
