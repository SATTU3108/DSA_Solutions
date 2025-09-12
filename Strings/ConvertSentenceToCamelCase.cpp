#include <bits/stdc++.h>
using namespace std;

/*
Given a sentence s, your task is to remove all spaces and convert it to Camel Case. In Camel Case, words are joined without spaces, the first word keeps its original case, and each subsequent word starts with an uppercase letter.

Note: It is guaranteed that the sample test cases don't contain leading spaces.
*/

string convertToCamelCase(string& s) {
    string res="";
    for (int i=0;i<s.length();i++) {
        if (s[i]==' ') {
            while (s[i]==' ') i++;
            res+=toupper(s[i]);
        }
        else res+=s[i];
    }
    return res;
}
//time:O(n),space:O(n)