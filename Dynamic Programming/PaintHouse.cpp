#include <bits/stdc++.h>
using namespace std;

/*
Given an integer N and a 2D array cost[][3], where cost[i][0], cost[i][1], and cost[i][2] is the cost of painting ith house with colors red, blue, and green respectively, the task is to find the minimum cost to paint all the houses such that no two adjacent houses have the same color.
*/

// Tabulation
int minCost(vector<vector<int>> &cost,int n) {
    if (n==0) return 0;
    vector<vector<int>> dp(n,vector<int> (3,0));
    dp[0][0]=cost[0][0],dp[0][1]=cost[0][1],dp[0][2]=cost[0][2];
    for (int i=1;i<n;i++) {
        // current house is coloured red
        dp[i][0]=cost[i][0]+min(dp[i-1][1],dp[i-1][2]);
        // current house is coloured blue
        dp[i][1]=cost[i][1]+min(dp[i-1][0],dp[i-1][2]);
        // current house is coloured green
        dp[i][2]=cost[i][2]+min(dp[i-1][0],dp[i-1][1]);
    }
    return min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}
//time:O(n),space:O(n)

// Space optimisation
int minCost(vector<vector<int>> &cost,int n) {
    int previous_red=cost[0][0],previous_blue=cost[0][1],previous_green=cost[0][2];
    int current_red,current_blue,current_green;
    for (int i=1;i<n;i++) {
        current_red=cost[i][0]+min(previous_blue,previous_green);
        current_blue=cost[i][1]+min(previous_red,previous_green);
        current_green=cost[i][2]+min(previous_red,previous_blue);
        previous_red=current_red;
        previous_blue=current_blue;
        previous_green=current_green;
    }
    return min({previous_red,previous_blue,previous_green});
}
//time:O(n),space:O(1)