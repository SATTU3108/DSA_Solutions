#include <bits/stdc++.h>
using namespace std;

/*
Given a string S of valid parentheses "(" and ")", the task is to print the string obtained by removing the outermost parentheses of every primitive substring from S.

A valid parentheses substring S is primitive if it is non-empty, and cannot be split into two or more non-empty substrings which are also a valid parentheses.
*/

string removeOuterParantheses(string s) {
    int open_count=0,close_count=0;
    string result="";
    int start=0;
    for (int i=0;i<s.length();i++) {
        char c=s[i];
        if (c=='(') open_count++;
        else if (c==')') close_count++;
        if (open_count==close_count) {
            result+=s.substr(start+1,i-start-1);
            start=i+1;
        }
    }
    return result;
}
//time:O(n),space:O(1)