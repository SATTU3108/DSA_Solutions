/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/

int minCostClimbingStairs(vector<int>& cost) {
  int n=cost.size();
  if (n==2) return min(cost[0],cost[1]);
  cost.push_back(0);
  vector <int> dp(n+1);
  dp[1]=cost[0],dp[2]=cost[1];
  for (int i=3;i<=n;i++) {
      int cost1=dp[i-2]+cost[i-1];
      int cost2=dp[i-1]+cost[i-1];
      int cost3=dp[i-1]+cost[i];
      dp[i]=min({cost1,cost2,cost3});
  }
  return dp[n];
}
//Time complexity:O(N),Space complexity:O(N)

int minCostClimbingStairs(vector<int> &cost) {
  int n=cost.size();
  if (n==2) return min(cost[0],cost[1]);
  cost.push_back(0);
  int prev_prev=cost[0],prev=cost[1];
  for (int i=3;i<=n;i++) {
      int cost1=prev_prev+cost[i-1];
      int cost2=prev+cost[i-1];
      int cost3=prev+cost[i];
      int curr=min({cost1,cost2,cost3});
      prev_prev=prev;
      prev=curr;
  }
  return prev;
}
//Time complexity:O(N),Space complexity:O(1)
