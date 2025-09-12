#include <bits/stdc++.h>
using namespace std;

/*
Given two string s1 and s2 of same length, the task is to check whether s2 is a rotation of s1.
*/

// Naive Method
bool areRotations(string &s1,string &s2) {
    int n=s1.size();
    for (int i=0;i<n;i++) {
        if (s1==s2) return true;
        char last=s1.back();
        s1.pop_back();
        s1=last+s1;
    }
    return false;
}
//time:O(n^2),space:O(1)

// Optimal Approach
bool areRotations(string &s1,string &s2) {
    s1+=s1;
    if (s1.find(s1)!=string::npos) return true;
    return false;
}
//time:O(n),space:O(1)