#include <bits/stdc++.h>
using namespace std;

/*
Fibonacci Series
*/

// Recursive solution
int nthFibonacci(int n) {
    if (n<=1) return n;
    return nthFibonacci(n-1)+nthFibonacci(n-2);
}
//time:O(2^n),space:O(n)

// Memoisation
int nthFibonacciUtil(int n,vector<int> memo) {
    if (n<=1) return n;
    if (memo[n]!=-1) return memo[n];
    memo[n]=nthFibonacciUtil(n-1,memo)+nthFibonacciUtil(n-2,memo);
    return memo[n];
}
int nthFibonacci(int n) {
    vector<int> memo(n+1,-1);
    return nthFibonacciUtil(n,memo);
}
//time:O(n),space:O(n)

// Tabulation
int nthFibonacci(int n) {
    if (n<=1) return n;
    vector<int> dp(n+1);
    dp[0]=0,dp[1]=1;
    for (int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
//time:O(n),space:O(n)

// Space Optimised Approach
int nthFibonacci(int n) {
    if (n<=1) return n;
    int curr=0;
    int prev1=1,prev2=0;
    for (int i=2;i<=n;i++) {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}
//time:O(n).space:O(1)

// Matrix Exponentiation
// multiplication of 2X2 matrices
void multiply(vector<vector<int>> &mat1,vector<vector<int>> &mat2) {
    int x=mat1[0][0]*mat2[0][0]+mat1[0][1]*mat2[1][0];
    int y=mat1[0][0]*mat2[0][1]+mat1[0][1]*mat2[1][1];
    int z=mat1[1][1]*mat2[0][0]+mat1[1][1]*mat2[1][0];
    int w=mat1[1][0]*mat2[0][1]+mat1[1][1]*mat2[1][1];
    mat1[0][0]=x,mat1[0][1]=y,mat1[1][0]=z,mat1[1][1]=w;
}
void matrixPower(vector<vector<int>> &mat1,int n) {
    if (n==0 || n==1) return;
    vector<vector<int>> mat2={{1,1},{1,0}};
    matrixPower(mat1,n/2);
    multiply(mat1,mat1);
    if (n%2!=0) multiply(mat1,mat2);
}
int nthFibonacci(int n) {
    if (n<=1) return n;
    vector<vector<int>> mat1={{1,1},{1,0}};
    matrixPower(mat1,n-1);
    return mat1[0][0];
}
//time:O(logn),space:O(1)