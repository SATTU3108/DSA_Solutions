/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

//Approach 1
int climbStairs(int n) {
  if (n==1) return 1;
  vector <int> dp(n+1);
  dp[1]=1,dp[2]=2;
  for (int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
  return dp[n];
}
//Time complexity:O(N),Space complexity:O(N)

//Approach 2
int climbStairs(int n) {
  if (n==1) return 1;
  int prev=1,curr=2;
  for (int i=3;i<=n;i++) {
      int next=prev+curr;
      prev=curr;
      curr=next;
  }
  return curr;
}
//Time complexity:O(N),Space complexity:O(1)
