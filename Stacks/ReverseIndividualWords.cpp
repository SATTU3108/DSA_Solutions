#include <bits/stdc++.h>
using namespace std;

string reverseWords(string str) {
    stack<char> st;
    string res="";
    for (int i=0;i<str.length();i++) {
        if (str[i]!=' ') st.push(str[i]);
        else {
            while (!st.empty()) {
                res+=st.top();
                st.pop();
            }
            res+=" ";
        }
    }
    while (!st.empty()) {
        res+=st.top();
        st.pop();
    }
    return res;
}



/*
You are given a string s. You need to reverse each word in it where the words are separated by spaces and return the modified string.

Note: The string may contain leading or trailing spaces, or multiple spaces between two words. The returned string should only have a single space separating the words, and no extra spaces should be included.
*/
string reverseWords(string &s) {
    stack<char> st;
    string res="";
    int i=0;
    int n=s.length();
    while (i<n) {
        // Skip leading spaces
        while (i<n && s[i]==' ') i++;
        // Process word
        while (i<n && s[i] != ' ') {
            st.push(s[i]);
            i++;
        }
        // Add reversed word
        if (!st.empty()) {
            if (!res.empty()) res+=" ";  // Add space before appending next word
            while (!st.empty()) {
                res+=st.top();
                st.pop();
            }
        }
    }
    return res;
}