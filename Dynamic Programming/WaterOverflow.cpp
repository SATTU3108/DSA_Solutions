#include <bits/stdc++.h>
using namespace std;

/*
here is a stack of water glasses in the form of a Pascal triangle and a person wants to pour the water at the topmost glass, but the capacity of each glass is 1 unit. Overflow occurs in such a way that after 1 unit, 1/2 of the remaining unit gets into the bottom left glass and the other half in the bottom right glass. We pour k units of water into the topmost glass. The task is to find how much water is there in the c'th glass of the r'th row.

Note: Assume that there are enough glasses in the triangle till no glass overflows.
*/

// Dynamic Programming
double waterOverflow(int k,int r,int c) {
    vector<vector<double>> dp(r,vector<double> (r,0.0));
    dp[0][0]=k;
    for (int row=0;row<r-1;row++) {
        for (int col=0;col<=r;col++) {
            double overflow=max(0.0,dp[row][col]-1.0);
            if (overflow>0) {
                dp[row][col]=1.0;
                dp[row+1][col]+=overflow/2.0;
                dp[row+1][col+1]+=overflow/2.0;
            }
        }
    }
    return min(1.0,dp[r-1][c-1]);
}

double waterOverflow(int k, int r, int c) {
    r--;
    c--;
    // Initialize queue with total water units
    queue<double> q;
    q.push(1.0*k);
    // Variable to track overflow from previous glasses
    double prev = 0;
    // Simulate water flow row by row
    for (int i=0;i<=r;i++) {
        // Process current row's glasses
        int size=q.size();
        for (int j=0;j<size;j++) {
            // Get current glass water amount
            double curr=q.front();
            // Check if target glass is reached
            if (i==r && j==c) return min(curr,1.0);
            // Reduce water in current glass
            curr--;
            q.pop();
            // Calculate and distribute overflow
            double val = max(curr/2.0, 0.0) + prev;
            q.push(val);
            // Track overflow for next iteration
            prev = max(0.0, curr/2.0);
        }
        // Add previous row's overflow to next row
        q.push(prev);
        prev = 0;
    }
}