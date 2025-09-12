#include <bits/stdc++.h>
using namespace std;

/*
Given a string, find all possible subsequences of string
*/

// Method-1 -> Bit Manipulation
vector<string> allPossibleStrings(string s) {
    int n=s.length();
    vector<string> ans;
    for (int num=0;num<(1<<n);num++) {
        string sub="";
        for (int i=0;i<n;i++) {
            if (num&(1<<i)) sub+=s[i];
        }
        if (sub.length()>0) ans.push_back(sub);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// Method-2 -> Recursion
void solve(int i,string s,string &f) {
    if (i=s.length()) {
        cout<<f<<" ";
        return;
    }
    f=f+s[i]; // pick the current character
    solve(i+1,s,f);
    f.pop_back(); // don't pick the current character
    solve(i+1,s,f);
}
