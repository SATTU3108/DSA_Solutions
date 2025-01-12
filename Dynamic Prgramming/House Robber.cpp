/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

//Approach 1
int rob(vector<int>& nums) {
  int n=nums.size();
  if (n==1) return nums[0];
  if (n==2) return max(nums[0],nums[1]);
  vector <int> dp(n+1);
  dp[1]=nums[0],dp[2]=max(nums[0],nums[1]);
  for (int i=3;i<=n;i++) {
      int rob=nums[i-1]+dp[i-2];
      int not_rob=dp[i-1];
      dp[i]=max(rob,not_rob);
  }
  return dp[n];
}
//Time complexity:O(N),Space complexity:O(N)

//Approach 2
int rob(vector<int>& nums) {
  int n=nums.size();
  if (n==1) return nums[0];
  if (n==2) return max(nums[0],nums[1]);
  int prev_prev=nums[0],prev=max(nums[0],nums[1]);
  for (int i=3;i<=n;i++) {
      int rob=nums[i-1]+prev_prev;
      int not_rob=prev;
      int curr=max(rob,not_rob);
      prev_prev=prev;
      prev=curr;
  }
  return prev;
}
//Time complexity:O(N),Space complexity:O(1)
