//Approach 1
int maxProfit(vector<int> &prices) {
  int n=prices.size();
  if (n==1) return 0;
  vector <int> dp(n+1,0);
  dp[1]=0;
  int min_price=prices[0];
  for (int i=2;i<=n;i++) {
      dp[i]=max(dp[i-1],prices[i-1]-min_price);
      min_price=min(min_price,prices[i-1]);
  }
  return dp[n];
}
//Time complexity:O(N),Space complexity:O(N)

//Approach 2
int maxProfit(vector <int> &prices) {
  int n=prices.size();
  if (n==1) return 0;
  int prev=0,min_price=prices[0];
  for (int i=2;i<=n;i++) {
      int curr=max(prev,prices[i-1]-min_price);
      prev=curr;
      min_price=min(min_price,prices[i-1]);
  }
  return prev;
}
//Time complexity:O(N),Space complexity:O(1)
