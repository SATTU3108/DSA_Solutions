#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, the task is to find the longest substring which is a palindrome. If there are multiple answers, then return the first appearing substring.
*/

// Naive Approach -> Generating Substrings
bool isPalindrome(string &s,int low,int high) {
    while (low<high) {
        if (s[low]!=s[high]) return false;
        low++;
        high--;
    }
    return true;
}
string longestPalindrome(string &s) {
    int n=s.size();
    int max_len=1,start=0;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            if (isPalindrome(s,i,j) && (j-i+1)>max_len) {
                start=i;
                max_len=j-i+1;
            }
        }
    }
    return s.substr(start,max_len);
} 
//time:O(n^3),space:O(1)

// DP Approach
string longestPalindrome(string &s) {
    int n=s.size();
    vector<vector<bool>> dp(n,vector<bool> (n,false));
    int start=0,max_len=1;
    for (int i=0;i<n;i++) dp[i][i]=true;
    for (int i=0;i<n-1;i++) {
        if (s[i]==s[i+1]) {
            dp[i][i+1]=true;
            if (max_len<2) {
                start=i;
                max_len=2;
            }
        }
    }
    for (int k=3;k<=n;k++) {
        for (int i=0;i<n-k;i++) {
            int j=i+k-1;
            if (dp[i+1][j-1]==true && s[i]==s[j]) {
                dp[i][j]=true;
                if (k>max_len) {
                    start=i;
                    max_len=k;
                }
            }
        }
    }
    return s.substr(start,max_len);
}
//time:O(n^2),space:O(n^2)

// Expansion from Centre
string longestPalindrome(string &s) {
    int n=s.length();
    if (n==0) return "";
    int start=0,max_len=1;
    for (int i=0;i<n;i++) {
        // j=0 means odd length palindrome
        // j=1 means even length palindromes
        for (int j=0;j<=1;j++) {
            int low=i,high=i+j;
            // Expand substring, keeping low and high in bounds and ensuring that they form palindrome
            while (low>=0 && high<n && s[low]==s[high]) {
                int curr_len=high-low+1;
                if (curr_len>max_len) {
                    start=low;
                    max_len=curr_len;
                }
                low--;
                high++;
            }
        }
    }
    return s.substr(start,max_len);
}