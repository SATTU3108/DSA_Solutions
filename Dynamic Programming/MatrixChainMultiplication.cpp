#include <bits/stdc++.h>
using namespace std;

// Recursion
int minMultRec(vector<int> &arr,int i,int j) {
    if (i+1==j) return 0;
    int res=INT_MAX;
    for (int k=i;k<j;k++) {
        int curr=minMultRec(arr,i,k)+minMultRec(arr,k,j)+arr[i]*arr[j]*arr[k];
        res=min(res,curr);
    }
    return res;
}
//time:O(2^n),space:O(n)

// Memoisation
int minMultRec(vector<int> &arr,int i,int j,vector<vector<int>> &memo) {
    if (i+1==j) return 0;
    if (memo[i][j]!=-1) return memo[i][j];
    int res=INT_MAX;
    for (int k=i;k<j;k++) {
        int curr=minMultRec(arr,i,k,memo)+minMultRec(arr,k,j,memo)+arr[i]*arr[j]*arr[k];
        res=min(res,curr);
    }
    return res;
}
//time:O(n^3),space:O(n^2)

// Tabulation
int matrixMultiplication(vector<int> &arr) {
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    for (int len=2;len<n;len++) {
        for (int i=0;i<n-len;i++) {
            int j=i+len;
            dp[i][j]=INT_MAX;
            for (int k=i+1;k<j;k++) {
                int cost=dp[i][k]+dp[j][k]+arr[i]*arr[j]*arr[k];
                dp[i][j]=min(dp[i][j],cost);
            }
        }
    }
    return dp[0][n-1];
}
//time:O(n^3),space:O(n^2)