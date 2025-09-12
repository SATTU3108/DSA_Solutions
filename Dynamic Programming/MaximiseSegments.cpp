#include <bits/stdc++.h>
using namespace std;

/*
Given a rod of length n, the task is to cut the rod in such a way that the total number of segments of length x, y, and z is maximized. The segments can only be of length x, y, and z. 
Note: If no segment can be cut then return 0.
*/

// Recursion
int maxCutHelper(int n,int x,int y,int z) {
    if (n==0) return 0; 
    if (n<0) return -1; //invalid result
    int cut1=maxCutHelper(n-x,x,y,z);
    int cut2=maxCutHelper(n-y,x,y,z);
    int cut3=maxCutHelper(n-z,x,y,z);
    int maxCut=max({cut1,cut2,cut3});
    if (maxCut==-1) return -1;
    return maxCut+1;
}
int maximiseCuts(int n,int x,int y,int z) {
    int res=maxCutHelper(n,x,y,z);
    if (res==-1) return -1;
    return res;
}
//time:O(3^n),space:O(n)

// Memoisation
int maxCutHelper(int n,int x,int y,int z,vector<int> &memo) {
    if (n==0) return 0;
    if (n<0) return -1;
    if (memo[n]!=-1) return memo[n];
    int cut1=maxCutHelper(n-x,x,y,z,memo);
    int cut2=maxCutHelper(n-y,x,y,z,memo);
    int cut3=maxCutHelper(n-z,x,y,z,memo);
    int maxCut=max({cut1,cut2,cut3});
    if (maxCut==-1) return memo[n]=-1;
    return memo[n]=maxCut+1;
}
int maximiseCuts(int n,int x,int y,int z) {
    vector<int> memo(n+1,-1);
    int res=maxCutHelper(n,x,y,z,memo);
    if (res==-1) return -1;
    return res;
}
//time:O(n),space:O(n)

// Tabulation
int maximiseCuts(int n,int x,int y,int z) {
    vector<int> dp(n+1,0);
    for (int i=1;i<=n;i++) {
        if (i>=x && dp[i-x]!=-1) dp[i]=max(dp[i],dp[i-x]+1);
        if (i>=y && dp[i-y]!=-1) dp[i]=max(dp[i],dp[i-y]+1);
        if (i>=z && dp[i-z]!=-1) dp[i]=max(dp[i],dp[i-z]+1);
        if (dp[i]==0) dp[i]=-1;
    }
    if (dp[n]==-1) return -1;
}
