#include <bits/stdc++.h>
using namespace std;

//Recursive approach -> pass the 'cuts' array only after sorting it
int findMinimumCost(vector <int> &cuts, int i,int j) {
    //Base case: If i>j, there are no cuts to consider
    if (i>j) return 0;
    int mini=INT_MAX;
    for (int ind=i+1;ind<=j;ind++) {
        //Calulate the cost for cutting the stick at the position 'ind'
        int ans=cuts[j+1]-cuts[i-1]+findMinimumCost(cuts,i,ind-1)+findMinimumCost(cuts,ind+1,j);
        mini=min(mini,ans);
    }
    return mini;
}

//DP-based approach:
int minimumCost(vector <int> &cuts,int n,int c) {
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector <vector<int>> dp(c+2,vector<int> (c+2,0));
    for (int i=c;i>=1;i--) {
        for (int j=1;j<=c;j++) {
            if (i>j) continue;
            int mini=INT_MAX;
            for (int ind=1;ind<=j;ind++) {
                int ans=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                mini=min(mini,ans);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][c];
}
//Time complexity:O(N^3)
//Space complexity:O(N^2)
