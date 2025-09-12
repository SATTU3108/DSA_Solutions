#include <bits/stdc++.h>
using namespace std;

/*
Let 1 maps to 'A', 2 maps to 'B', ..., 26 to 'Z'. Given a digit sequence, count the number of possible decodings of the given digit sequence. 

Consider the input string "123". There are three valid ways to decode it:

"ABC": The grouping is (1, 2, 3) → 'A', 'B', 'C'
"AW": The grouping is (1, 23) → 'A', 'W'
"LC": The grouping is (12, 3) → 'L', 'C'
Note: Groupings that contain invalid codes (e.g., "0" by itself or numbers greater than "26") are not allowed.
For instance, the string "230" is invalid because "0" cannot stand alone, and "30" is greater than "26", so it cannot represent any letter. The task is to find the total number of valid ways to decode a given string.
*/

// Recursion
int decodeHelper(string &digits,int index) {
    int n=digits.length();
    if (index>=n) return 1;
    int ways=0;
    if (digits[index!=0]) ways=decodeHelper(digits,index+1);
    if ((index+1<n) && (digits[index]=='1' && digits[index]<='9') || (digits[index]=='2' && digits[index+1]<='6')) ways+=decodeHelper(digits,index+2);
    return ways;
}
int countWays(string &digits) {
    return decodeHelper(digits,0);
}
//time:O(2^n),space:O(n)

// Memoisation
int decodeHelper(string &digits,int index,vector<int> &memo) {
    int n=digits.length();
    if (index>=n) return 1;
    if (memo[index]!=-1) return memo[index];
    int ways=0;
    if (digits[index]!=0) ways=decodeHelper(digits,index+1,memo);
    if ((index+1<n) && (digits[index]=='1' && digits[index+1]<='9') || (digits[index]=='2' && digits[index+1]<='6')) ways+=decodeHelper(digits,index+2,memo);
    return memo[index]=ways;
}
int countWays(string &digits) {
    int n=digits.length();
    vector<int> memo(n,-1);
    return decodeHelper(digits,0,memo);
}
//time:O(n),space:O(n)

// Tabulation
int countWays(string &digits) {
    int n=digits.length();
    vector<int> dp(n+1,0);
    dp[n]=1;
    for (int i=n-1;i>=0;i--) {
        if (digits[i]!=0) dp[i]=dp[i+1];
        if ((i+1<n) && (digits[i]=='1' && digits[i+1]<'9') || (digits[i]=='2' && digits[i+1]<'6')) dp[i]+=dp[i+2];
    }
    return dp[0];
}
//time:O(n),space:O(n)

// Space-optimised approach
int countWays(string &digits) {
    int n=digits.size();
    if (n==0 || digits[0]=='0') return 0;
    int prev1=0,prev2=0;
    for (int i=1;i<=n;i++) {
        int curr=0;
        if (digits[i-1]!='0') curr+=prev1;
        if (i>1) {
            int twoDigit=(digits[i-2]-'0')*10+(digits[i-1]-'0');
            if (twoDigit>=10 && twoDigit<=26) curr+=prev2;
        }
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
} 
//time:O(n),space:O(1)