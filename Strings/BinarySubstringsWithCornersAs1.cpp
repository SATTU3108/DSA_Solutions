#include <bits/stdc++.h>
using namespace std;

/*
Given a binary string, count the number of substrings that start and end with 1. 
*/

// Naive Method
int countSubstr(string s) {
    int res=0;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='1') {
            for (int j=i+1;j<s.length();j++) {
                if (s[j]=='1') res++;
            }
        }
    }
    return res;
}
//time:O(n^2),space:O(1)

// Optimal Approach
int countSubstr(string s) {
    int count=0;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='1') count++;
    }
    return ((count)*(count-1))/2;
}
//time:O(n),space:O(1)