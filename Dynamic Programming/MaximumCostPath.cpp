#include <bits/stdc++.h>
using namespace std;

// Recursion
int findMinCost(vector<vector<int>> &cost,int x,int y) {
    int m=cost.size(),n=cost[0].size();
    if (x>=m || y>=n) return INT_MAX;
    if (x==m-1 && y==n-1) return cost[x][y];
    return cost[x][y]+min({findMinCost(cost,x,y+1),findMinCost(cost,x+1,y),findMinCost(cost,x+1,y+1)});
}
int minCost(vector<vector<int>> &cost) {
    return findMinCost(cost,0,0);
}
//time:O(3^(m*n)),space:O(n)

// Memoisation
int memoHelper(vector<vector<int>> &cost,int x,int y,vector<vector<int>> &memo) {
    int m=cost.size(),n=cost[0].size();    
    if (x>=m || y>=n) return INT_MAX;
    if (x==m-1 && y==n-1) return cost[x][y];
    if (memo[x][y]!=-1) return memo[x][y];
    return memo[x][y]=cost[x][y]+min({memoHelper(cost,x,y+1,memo),memoHelper(cost,x+1,y,memo),memoHelper(cost,x+1,y+1,memo)});    
}
int minCost(vector<vector<int>> &cost) {
    int m=cost.size(),n=cost[0].size();
    vector<vector<int>> memo(m,vector<int> (n,-1));
    return memoHelper(cost,0,0,memo);
}

// Tabulation
int minCost(vector<vector<int>> &cost) {
    int m=cost.size(),n=cost[0].size();
    vector<vector<int>> dp(m,vector<int> (n));
    dp[0][0]=cost[0][0];
    for (int j=1;j<n;j++) dp[0][j]=cost[0][j]+dp[0][j-1];
    for (int i=1;i<m;i++) dp[i][0]=cost[i][0]+dp[i-1][0];
    for (int i=1;i<m;i++) {
        for (int j=1;j<n;j++) {
            dp[i][j]=cost[i][j]+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
    }
    return dp[m-1][n-1];
}
//time:O(m*n),space:O(m*n)

// Space-optimised approach
int minCost(vector<vector<int>> &cost) {
    int m=cost.size(),n=cost[0].size();
    vector<int> dp(n,0);
    dp[0]=cost[0][0];
    for (int j=1;j<n;j++) dp[j]=dp[j-1]+cost[0][j];
    for (int i=1;i<m;i++) {
        int prev=dp[0];
        dp[0]=cost[i][0]+dp[0];
        for (int j=1;j<n;j++) {
            int temp=dp[j];
            dp[j]=cost[i][j]+min({dp[j],dp[j-1],prev});
            prev=temp;
        }
    }
    return dp[n-1];
}
//time:O(m*n),space:O(n)