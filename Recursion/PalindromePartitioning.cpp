#include <bits/stdc++.h>
using namespace std;

/*
You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.

Note: A palindrome string is a string that reads the same backward as forward.
*/

bool isPalindrome(string s,int start,int end) {
    while (start<=end) {
        if (s[start]!=s[end]) return false;
        start++;
        end--;
    }
    return true;
}
void partitionHelper(int index,string s,vector<string> &path,vector<vector<string>> &res) {
    if (index==s.size()) {
        res.push_back(path);
        return;
    }
    for (int i=index;i<s.size();i++) {
        if (isPalindrome(s,index,i)) {
            path.push_back(s.substr(index,i-index+1));
            partitionHelper(i+1,s,path,res);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<string> path;
    vector<vector<string>> res;
    partitionHelper(0,s,path,res);
    return res;
}

