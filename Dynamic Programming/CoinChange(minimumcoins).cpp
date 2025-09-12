#include <bits/stdc++.h>
using namespace std;

int minCoinsRec(int i,int sum,vector<int> &coins) {
    if (sum==0) return 0;
    if (sum<0 || i==coins.size()) return INT_MAX;
    int take=INT_MAX;
    if (coins[i]>0) {
        take=minCoinsRec(i,sum-coins[i],coins);
        if (take!=INT_MAX) take++;
    }
    int notTake=minCoinsRec(i+1,sum,coins);
    return min(take,notTake);
} 
//time:O(n^sum),space:O(sum)

// Memoisation
int minCoinsRec(int i,int sum,vector<int> &coins,vector<vector<int>> &memo) {
    if (sum==0) return 0;
    if (sum<0 || i==coins.size()) return INT_MAX;
    if (memo[i][sum]!=-1) return memo[i][sum];
    int take=INT_MAX;
    if (coins[i]>0) {
        take=minCoinsRec(i,sum-coins[i],coins,memo);
        if (take!=INT_MAX) take++;
    }
    int notTake=minCoinsRec(i+1,sum,coins,memo);
    return memo[i][sum]=min(take,notTake);
}
int minCoins(vector<int> &coins,int sum) {
    vector<vector<int>> memo(coins.size(),vector<int> (sum+1,-1));
    int res=minCoinsRec(0,sum,coins,memo);
    if (res==INT_MAX) return -1;
    return res;
}