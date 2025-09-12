#include <bits/stdc++.h>
using namespace std;

/*Given n pairs of parantheses, write a function to generate all combinations of well-formed parantheses*/

void dfs(int openP,int closeP,int n,string &s,vector<string> &res) {
    if (openP==n && closeP==n) {
        res.push_back(s);
        return;
    }
    if (openP<n) {
        s.push_back('(');
        dfs(openP+1,closeP,n,s,res);
        s.pop_back();
    }
    if (closeP<openP) {
        s.push_back(')');
        dfs(openP,closeP+1,n,s,res);
        s.pop_back();
    }
}
vector<string> generateParanthess(int n) {
    vector<string> res;
    string s;
    dfs(0,0,n,s,res);
}