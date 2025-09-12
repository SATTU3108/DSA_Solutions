#include <bits/stdc++.h>
using namespace std;

/*
Two strings s1 and s2 are called isomorphic if there is a one-to-one mapping possible for every character of s1 to every character of s2. And all occurrences of every character in 's1' map to the same character in 's2'.
*/

// Naive Approach -> Two Loops
bool areIsomorphic(string &s1, string &s2) {
    if (s1.length()!=s2.length()) return false;
    int n=s1.length();
    for (int i=0;i<n;i++) {
        char c1=s1[i],c2=s2[i];
        for (int j=0;j<n;j++) {
            if (s1[j]==c1 && s2[j]!=c2) return false;
            if (s2[j]==c2 && s1[j]!=c1) return false;
        }
    }
    return true;
}
//time:O(n^2),space:O(1)

// Better Approach -> Hash Maps
bool areIsomorphic(string &s1, string &s2) {
    if (s1.length()!=s2.length()) return false;
    unordered_map <char,int> m1,m2;
    int n=s1.length();
    for (int i=0;i<n;i++) {
        if (m1.find(s1[i])==m1.end()) m1[s1[i]]=i;
        if (m2.find(s2[i])==m2.end()) m2[s2[i]]=i;
        if (m1[s1[i]]!=m2[s2[i]]) return false;
    }
    return true;
}
//time:O(n),space:O(MAX_CHAR

// Optimal Approach -> optimised over method 2
bool areIsomorphic(string &s1, string &s2) {
    if (s1.length()!=s2.length()) return false;
    vector<int> m1(256,-1);
    vector<int> m2(256,-1);
    int n=s1.length();
    for (int i=0;i<n;i++) {
        if (m1[s1[i]]==-1) m1[s1[i]]=i;
        if (m2[s2[i]]==-1) m2[s2[i]]=i;
        if (m1[s1[i]]!=m2[s2[i]]) return false;
    }
    return true;
}
//time:O(n),space:O(1)