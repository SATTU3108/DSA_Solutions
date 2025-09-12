#include <bits/stdc++.h>
using namespace std;

// Naive Approach -> substrings starting from every index
int longestUniqueSubstr(string &s) {
    int n=s.size();
    int res=0;
    for (int i=0;i<n;i++) {
        // inititalising all characters as not visited
        vector<bool> vis(26,false);
        for (int j=i;j<n;j++) {
            // if current character is visited, break
            if (vis[j-'a']==true) break;
            // else, update the result if window is larger, and mark current character as visited
            else {
                res=max(res,j-i+1);
                vis[s[j]-'a']=true;
            }
        }
    }
    return res;
}
//time:O(n*26),space:O(1)

// Optimal Approach -> 2 pointer
int longestUniqueSubstr(string &s) {
    if (s.length()==0 || s.length()==1) return s.length();
    int res=0;
    vector<bool> vis(26,false);
    // left and right pointer of sliding window
    int left=0,right=0;
    while (right<s.length()) {
        // if character is repeated, move left pointer marking visited characters as false until the repeating character is no longer part of the current window
        while (s[right-'a']==true) {
            vis[s[left]-'a']=false;
            left++;
        }
        vis[s[right]-'a']=true;
        res=max(res,right-left+1);
        right++;
    }
    return res;
}