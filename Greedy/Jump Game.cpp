/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

//Recursive solution
bool func(vector<int> &nums,int index) {
  if (index==nums.size()-1) return true;
  if (index>nums.size()-1) return false;
  int max_jump=nums[index];
  for (int jump_size=1;jump_size<=max_jump;jump_size++) {
      if (func(nums,index+jump_size)) return true;
  }
  return false;
}
bool canJump(vector<int>& nums) {
    return func(nums,0);
}
//Time complexity:O(2^N),Space complexity:O(N)

//Dynamic Programming solution
bool canJump(vector<int>& nums) {
  int n=nums.size();
  vector <bool> dp(n,false);
  dp[n-1]=true;
  for (int i=n-2;i>=0;i--) {
      int max_jump=nums[i];
      for (int j=1;j<=max_jump;j++) {
          if ((i+j)<n && dp[i+j]==true) {
              dp[i]=true;
              break;
          }
      }
  }
  return dp[0];
}
//Time complexity:O(N^2),Space complexity:O(N)

//Greedy Algorithm
bool canJump(vector<int>& nums) {
  int n=nums.size();
  int goal=n-1;
  for (int i=n-2;i>=0;i--) {
      if (i+nums[i]>=goal) goal=i;
  }
  return (goal==0);
}
//Time complexity:O(N),Space complexity:O(1)
