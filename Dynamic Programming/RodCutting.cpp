#include <bits/stdc++.h>
using namespace std;

/*
Given a rod of length n inches and an array price[]. price[i] denotes the value of a piece of length i. The task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: price[] is 1-indexed array.
*/

// Recursion
int cutRodRecur(int i,vector<int> &price) {
    if (i==0) return 0;
    int ans=0;
    for (int j=1;j<=i;j++) {
        ans=max(ans,price[j-1]+cutRodRecur(i-j,price));
    }
    return ans;
}
//time:O(2^n),space:O(n)

// Memoisation
int cutRodRecur(int i,vector<int> &price,vector<int> &memo) {
    if (i==0) return 0;
    if (memo[i]!=-1) return memo[i];
    int ans=0;
    for (int j=1;j<=i;j++) {
        ans=max(ans,price[j-1]+cutRodRecur(i-j,price,memo));
    }
    return memo[i]=ans;
}
int cutRod(vector<int> &price) {
    int n=price.size();
    vector<int> memo(n+1,-1);
    return cutRodRecur(n,price,memo);
}
//time:O(n^2),space:O(n)

// Tabulation
int cutRod(vector<int> &price) {
    int n=price.size();
    vector <int> dp(n+1,0);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            dp[i]=max(dp[i],price[j-1]+dp[i-j]);
        }
    }
    return dp[n];
}
//time:O(n^2),space:O(n)

