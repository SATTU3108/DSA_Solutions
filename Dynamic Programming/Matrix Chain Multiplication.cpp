#include <bits/stdc++.h>
using namespace std;

//Recursive solution -> call f(arr,0,n-1)
int minMultiplicationRecursive(vector <int> arr,int i,int j) {
    if (i+1==j) return 0; //If there is only one matrix
    int res=INT_MAX;
    for (int k=i+1;k<j;k++) {
        //Place the first bracket ar different positions of k and for that every placed bracket, compute the value using that subproblem
        int curr=minMultiplicationRecursive(arr,i,k)+minMultiplicationRecursive(arr,k,j)+arr[i]*arr[j]*arr[k];
        res=min(res,curr);
    }
    return res;
}
//Time complexity:O(2^n)
//Space complexity:O(1)

//DP-based solution
int minMultiplication(vector <int> arr,int n) {
    vector <vector<int>> dp(n,vector<int> (n,0));
    //len is the chain length
    for (int len=2;len<n;len++) {
        for (int i=0;i<n-len;i++) {
            int j=i+len-1;
            for (int k=i+1;k<j;k++) {
                int cost=dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k];
                dp[i][j]=min(dp[i][j],cost);
            }
        }
    }
    return dp[0][n-1];
}
//Time complexity:O(n^3)
//Space complexity:O(n^2)
