#include <bits/stdc++.h>
using namespace std;

/*
We are given an array ‘ARR’ with N positive integers. We need to find if there is a subset in “ARR” with a sum equal to K. If there is, return true else return false.
*/

// Recursion
bool isSubsetSumRec(vector<int> &arr,int ind,int sum) {
    if (sum==0) return true;
    if (ind==0) return (arr[0]==true);
    bool notTaken=isSubsetSumRec(arr,ind-1,sum);
    bool taken=false;
    if (arr[ind]<=sum) taken=isSubsetSumRec(arr,ind-1,sum-arr[ind]);
    return taken || notTaken;
}

// Memoisation
bool isSubsetMemo(vector<int> &arr,int n,int sum,vector<vector<int>> &memo) {
    if (sum==0) return true;
    if (n<=0) return false;
    if (memo[n][sum]!=-1) return memo[n][sum];
    // If last element is greater than target, we cannot include it
    if (arr[n-1]>sum) return memo[n][sum]=isSubsetMemo(arr,n-1,sum,memo);
    // otherwise, we have two options: include or esclude
    return memo[n][sum]=isSubsetMemo(arr,n-1,sum,memo)||isSubsetMemo(arr,n-1,sum-arr[n-1],memo);
}
bool isSubsetSum(vector<int> &arr,int sum) {
    int n=arr.size();
    vector<vector<int>> memo(n+1,vector<int> (sum+1,-1));
    return isSubsetMemo(arr,n,sum,memo);
}
//time:O(n*sum),space:O(n*sum)

// Tabulation
bool isSubsetSum(vector<int> &arr,int sum) {
    int n=arr.size();
    vector<vector<bool>> dp(n+1,vector<bool> (sum+1,false));
    for (int i=0;i<=n;i++) dp[i][0]=true;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=sum;j++) {
            if (arr[i-1]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}
//time:O(n*sum),space:O(n*sum)

bool isSubsetSum(vector<int> &arr,int sum) {
    int n=arr.size();
    vector<bool> prev(sum+1,false),curr(sum+1,false);
    prev[0]=true;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=sum;j++) {
            if (arr[i-1]>j) curr[j]=prev[j];
            else curr[j]=prev[j] || prev[j-arr[i-1]];
        }
        prev=curr;
    }
    return prev[sum];
}
//time:O(n*sum),space:O(sum)