#include <bits/stdc++.h>
using namespace std;

/*
Buy and Sell Stock I
We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

We can buy and sell a stock only once.
We can buy and sell the stock on any day but to sell the stock, we need to first buy it on the same or any previous day.
We need to tell the maximum profit one can get by buying and selling this stock.

--------APPPROACH-----------
Assume that u are selling on ith day. so before that u are buying on some day that maximises the profit
*/

int maximumProfit(vector<int> &arr) {
    int n=arr.size();
    int max_profit=0,mini=arr[0];
    for (int i=1;i<n;i++) {
        int curr_profit=arr[i]-mini;
        max_profit=max(max_profit,curr_profit);
        mini=min(mini,arr[i]);
    }
    return max_profit;
}
//time:O(n),sapce:O(1)

/*
Buy and Sell Stock II
We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any previous day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
*/

// Approach 1 -> Memoisation
long getAns(vector<long> arr,int ind,int buy,int n,vector<vector<long>> &memo) {
    if (ind==n) return 0;
    if (memo[ind][buy]!=-1) return memo[ind][buy];
    long profit=0;
    if (buy==0) {
        profit=max(0+getAns(arr,ind+1,0,n,memo),-arr[ind]+getAns(arr,ind+1,1,n,memo));
    }
    if (buy==1) {
        profit=max(0+getAns(arr,ind+1,1,n,memo),arr[ind]+getAns(arr,ind+1,0,n,memo));
    }
    return memo[ind][buy]=profit;
}
long getMaximumProfit(vector<long> arr,int n) {
    vector<vector<long>> memo(n,vector<long> (2,-1));
    if (n==0) return 0;
    long ans=getAns(arr,0,0,n,memo);
    return ans;
}
//time:O(n*2)=O(n)
//space:O(n*2)+O(n)=O(n)

// Tabulation
long getMaximumProfit(vector<long> arr,int n) {
    vector<vector<long>> dp(n+1,vector<long> (2,-1));
    dp[n][0]=0,dp[n][1]=0;
    long profit;
    for (int ind=n-1;ind>=0;ind--) {
        for (int buy=0;buy<=1;buy++) {
            if (buy==0) {
                profit=max(0+dp[ind+1][0],-arr[ind]+dp[ind+1][1]);
            }
            if (buy==1) {
                profit=max(0+dp[ind+1][1],arr[ind]+dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][0];
}

// Space optimised
long getMaximumProfit(vector<long> arr,int n) {
    vector<long> ahead(2,0);
    vector<long> curr(2,0);
    ahead[0]=ahead[1]=0;
    long profit;
    for (int ind=n-1;ind>=0;ind--) {
        for (int buy=0;buy<=1;buy++) {
            if (buy==0) profit=max(0+ahead[0],-arr[ind]+ahead[1]);
            if (buy==1) profit=max(0+ahead[1],arr[ind]+ahead[0]);
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return curr[0];
}
//time:O(n),sapace:O(1)

/*
Buy and Sell Stock III
We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any previous day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
We can do at most 2 transactions.
*/

// Approach 1 -> Memoisation
int getAns(vector<int> &arr,int n,int ind,int buy,int cap,vector<vector<vector<int>>> &memo) {
    if (ind==n || cap==0) return 0;
    if (memo[ind][buy][cap]!=-1) return memo[ind][buy][cap];
    int profit;
    if (buy==0) {
        profit=max(0+getAns(arr,n,ind+1,0,cap,memo),-arr[ind]+getAns(arr,n,ind+1,1,cap,memo));
    }
    if (buy==1) {
        profit=max(0+getAns(arr,n,ind+1,1,cap,memo),arr[ind]+getAns(arr,n,ind+1,0,cap-1,memo));
    }
    return memo[ind][buy][cap]=profit;
}
int maxProfit(vector<int> &prices,int n) {
    vector<vector<vector<int>>> memo(n,vector<vector<int>> (2,vector<int> (3,-1)));
    return getAns(prices,n,0,0,2,memo);
}

// Approach 2 -> Tabulation
int maxProfit(vector<int> &arr,int n) {
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
    for (int ind=n-1;ind>=0;ind--) {
        for (int buy=0;buy<=1;buy++) {
            for (int cap=1;cap<=2;cap++) {
                if (buy==0) {
                    dp[ind][buy][cap]=max(0+dp[ind+1][0][cap],-arr[ind]+dp[ind+1][1][cap]);
                }
                if (buy==1) {
                    dp[ind][buy][cap]=max(0+dp[ind+1][1][cap],arr[ind+1]+dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    return dp[0][0][2];
}

/*
Buy and Sell Stock V
We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any previous day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
We can’t buy a stock on the very next day of selling it. This is the cooldown clause.
*/

// Approach 1 -> Memoisation
int getAns(vector<int> &arr,int n,int ind,int buy,vector<vector<int>> &memo) {
    if (ind>=n) return 0;
    if (memo[ind][buy]!=-1) return memo[ind][buy];
    int profit;
    if (buy==0) {
        profit=max(0+getAns(arr,n,ind+1,0,memo),-arr[ind]+getAns(arr,n,ind+1,1,memo));
    }
    if (buy==1) {
        profit=max(0+getAns(arr,n,ind+1,1,memo),arr[ind]+getAns(arr,n,ind+2,0,memo));
    }
    return memo[ind][buy]=profit;
}
//time:O(n*2)=O(n)
//space:O(n*2)+O(n)=O(n)

// Approach 2 -> Tabulation
int stockProfit(vector<int> &arr) {
    int n=arr.size();
    vector<vector<int>> dp(n+2,vector<int> (2,0));
    for (int ind=n-1;ind>=0;ind--) {
        for (int buy=0;buy<=1;buy++) {
            int profit;
            if (buy==0) {
                profit=max(0+dp[ind+1][0],-arr[ind]+dp[ind+1][1]);
            }
            if (buy==1) {
                profit=max(0+dp[ind+1][1],arr[ind]+dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][0];
}
//time:O(n*2)=O(n)
//space:O(n*2)=O(n)

// Space optimisation
int stockProfit(vector<int> &arr) {
    int n=arr.size();
    vector<int> curr(2,0),front1(2,0),front2(2,0);
    for (int ind=n-1;ind>=0;ind--) {
        for (int buy=0;buy<=1;buy++) {
            int profit;
            if (buy==0) {
                profit=max(0+front1[0],-arr[ind]+front1[1]);
            }
            if (buy==1) {
                profit=max(0+front1[1],arr[ind]+front2[0]);
            }
            curr[buy]=profit;
        }
        front2=front1;
        front1=curr;
    }
    return curr[0];
}
//time:O(n*2)=O(n)
//space:O(1)

/*
We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any previous day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
After every transaction, there is a transaction fee (‘fee’) associated with it.
*/

// Approach 1 -> Memoisation
int getAns(vector<int> &arr,int ind,int buy,int n,int fee,vector<vector<int>> &memo) {
    if (ind==n) return 0;
    if (memo[ind][buy]!=-1) return memo[ind][buy];
    int profit;
    if (buy==0) {
        profit=max(0+getAns(arr,ind+1,0,n,fee,memo),-arr[ind]+getAns(arr,ind+1,1,n,fee,memo));
    }
    if (buy==1) {
        profit=max(0+getAns(arr,ind+1,1,n,fee,memo),arr[ind]-fee+getAns(arr,ind+1,0,n,fee,memo));
    }
    return memo[ind][buy]=profit;
}
int maximumProfit(vector<int> &arr,int n,int fee) {
    vector<vector<int>> memo(n,vector<int> (2,-1));
    int ans=getAns(arr,0,0,n,fee,memo);
}

// Approach 2 -> Tabulation
int maximumProfit(vector<int> &arr,int n,int fee) {
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    for (int ind=n-1;ind>=0;ind--) {
        for (int buy=0;buy<=1;buy++) {
            int profit;
            if (buy==0) {
                profit=max(0+dp[ind+1][0],-arr[ind]+dp[ind+1][1]);
            }
            if (buy==1) {
                profit=max(0+dp[ind+1][1],arr[ind]-fee+dp[ind+1][0]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][0];
}

// Approach 3 -> Space-optimised approach
int maximumProfit(vector<int> &arr,int n,int fee) {
    vector<int> ahead(2,0),curr(2,0);
    int profit;
    for (int ind=n-1;ind>=0;ind--) {
        for (int buy=0;buy<=1;buy++) {
            if (buy==0) {
                profit=max(0+ahead[0],-arr[ind]+ahead[1]);
            }
            if (buy==1) {
                profit=max(0+ahead[1],arr[ind]-fee+ahead[0]);
            }
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return curr[0];
}