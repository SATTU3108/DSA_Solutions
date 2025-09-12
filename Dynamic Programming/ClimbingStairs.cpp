#include <bits/stdc++.h>
using namespace std;

/*
There are n stairs, and a person standing at the bottom wants to climb stairs to reach the top. The person can climb either 1 stair or 2 stairs at a time, the task is to count the number of ways that a person can reach at the top.
*/

// Tabulation
int countWays(int n) {
    vector<int> dp(n+1,0);
    dp[0]=1,dp[1]=1;
    for (int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
//time:O(n),space:O(n)

// Space Optimised Approach
int countWays(int n) {
    int prev1=1,prev2=1;
    for (int i=2;i<=n;i++) {
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
//time:O(n),space:O(1)