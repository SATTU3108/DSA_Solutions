#include <bits/stdc++.h>
using namespace std;


// Recursion
bool isILRec(string &s1,string &s2,string &s3,int i,int j) {
    int k=i+j;
    if (i==s1.size() && j==s2.size() && k==s3.size()) return true;
    bool a=(i<s1.size() && (s3[k]==s1[i]) && isILRec(s1,s2,s3,i+1,j));
    bool b=(j<s2.size() && (s3[k]==s2[j]) && isILRec(s1,s2,s3,i,j+1));
    return a||b;
}
bool isInterleave(string &s1,string &s2,string &s3) {
    if (s1.size()+s2.size()!=s3.size()) return false;
    return isILRec(s1,s2,s3,0,0);
}
//time:O(2^(m+n)),space:O(m+n)

// Memoisation
bool isILrec(string &s1,string &s2,string &s3,int i,int j,vector<vector<int>> &memo) {
    int k=i+j;
    int m=s1.size(),n=s2.size();
    if (i==m && j==n && k==s3.size()) return true;
    if (memo[i][j]!=-1) return memo[i][j];
    bool a=(i<m && (s1[i]==s3[k]) && isILrec(s1,s2,s3,i+1,j,memo));
    bool b=(j<n && (s2[j]==s3[k]) && isILrec(s1,s2,s3,i,j+1,memo));
    return memo[i][j]=a||b;
}
bool isInterLeave(string &s1,string &s2,string &s3) {
    int m=s1.size(),n=s2.size();
    if (m+n!=s3.size()) return false;
    vector<vector<int>> memo(m+1,vector<int> (n+1,-1));
    return isILrec(s1,s2,s3,m,n,memo);
}