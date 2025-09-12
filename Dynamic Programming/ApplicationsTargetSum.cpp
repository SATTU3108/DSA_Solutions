#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/

// Recursion + Memoisation
bool canPartition(vector<int>& nums) {
    int total=accumulate(nums.begin(),nums.end(),0);
    if (total%2!=0) return false;
    int target=total/2;
    int n=nums.size();
    vector<vector<int>> memo(n,vector<int>(target+1,-1));
    return solve(nums,memo,n-1,target);
}
bool solve(vector<int> &nums,vector<vector<int>> &memo,int ind,int target) {
    if (target==0) return true;
    if (ind<0) return false;
    if (memo[ind][target]!=-1) return memo[ind][target];
    bool not_take=solve(nums,memo,ind-1,target);
    bool take=false;
    if (nums[ind]<=target) take=solve(nums,memo,ind-1,target-nums[ind]);
    return memo[ind][target]=not_take || take;
}
//time:O(n*target)

// Tabulation
bool canPartition(vector<int>& nums) {
    int n=nums.size();
    int total=accumulate(nums.begin(),nums.end(),0);
    if (total%2!=0) return false;
    int target=total/2;
    vector<vector<bool>> dp(n+1,vector<bool> (target+1,false));
    for (int i=0;i<=n;i++) dp[i][0]=true;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=target;j++) {
            bool not_take=dp[i-1][j];
            bool take=false;
            if (nums[i-1]<=j) take=dp[i-1][j-nums[i-1]];
            dp[i][j]=take || not_take;
        }
    }
    return dp[n][target];
}

/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

int findTargetSumWays(vector<int> &nums,int target) {
    int total=accumulate(nums.begin(),nums.end(),0);
    if ((total+target)%2!=0 || total<abs(target)) return 0;
    int subset_sum=(total+target)/2;
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int> (subset_sum+1,0));
    for (int i=0;i<=n;i++) dp[i][0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=subset_sum;j++) {
            int not_take=dp[i-1][j];
            int take=0;
            if (nums[i-1]<=j) take=dp[i-1][j-nums[i-1]];
            dp[i][j]=take+not_take;
        }
    } 
    return dp[n][subset_sum];
}