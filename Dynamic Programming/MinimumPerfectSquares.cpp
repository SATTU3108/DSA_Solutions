#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer n, the task is to find the minimum number of squares that sum to n.

Note: A number can always be represented as a sum of squares of other numbers. Because 1 is a square number and we can always break any number as (1*1 + 1*1 + 1*1 + ... ).
*/

// Recursion
int minSquares(int n) {
    if (n<=3) return n;
    int count=n;
    for (int x=1;x*x<=n;x++) {
        count=min(count,minSquares(n-x*x));
    }
    return count;
}
//time:exponential

// Memoisation
int minSquaresRec(int n,vector<int> &memo) {
    if (n<=3) return n;
    if (memo[n]!=-1) return memo[n];
    int count=n;
    for (int x=1;x*x<=n;x++) {
        count=min(count,minSquaresRec(n-x*x,memo));
    }
    return memo[n]=count;
}
int minSquares(int n) {
    vector<int> memo(n+1,-1);
    return minSquaresRec(n,memo);
}
//time:O(n*sqrt(n)),space:O(n)

// Tabulation
int minSquares(int n) {
    vector<int> dp(n+1);
    dp[0]=0,dp[1]=1;
    for (int i=2;i<=n;i++) {
        dp[i]=i;
        for (int x=1;x*x<=i;x++) dp[i]=min(dp[i],1+dp[i-x*x]);
    }
    return dp[n];
}
//time:O(n*sqrt(n)),space:O(n)

// Lagrange's Four Square Theorem
bool isSquare(int x)  {
    int sqRoot=sqrt(x);
    return (sqRoot*sqRoot==x);
}
int minSquares(int n) {
    //case 1: ans=1
    if (isSquare(n)) return 1;
    // case 2:ans=2 -> sum of 2 perfect squares
    for (int i=1;i*i<=n;i++) {
        if (isSquare(n-i*i)) return 2;
    }
    // case 4: ans=4 -> no. of form 4^a(8b+7)
    while (n>0 && n%4==0) n/=4;
    if (n%8==7) return 4;
    else return 3;
}
//time:O(sqrt(n)),space:O(1)