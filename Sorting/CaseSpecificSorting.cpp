#include <bits/stdc++.h>
using namespace std;

/*

Given string s consisting of uppercase and lowercase characters. The task is to sort uppercase and lowercase characters separately such that if the ith place in the original string had an uppercase character, then it should not have a lowercase character after being sorted and vice versa.*/

// Method 1 -> 2 Arrays + Sorting
string caseSort(string s) {
    int n=s.length();
    vector<char> lower,upper;
    for (char ch:s) {
        if (islower(ch)) lower.push_back(ch);
        else upper.push_back(ch);
    }
    sort(lower.begin(),lower.end());
    sort(upper.begin(),upper.end());
    string result=s;
    int lower_index=0,upper_index=0;
    for (int i=0;i<n;i++) {
        if (islower(s[i])) {
            result[i]=lower[lower_index];
            lower_index++;
        }
        else {
            result[i]=upper[upper_index];
            upper_index++;
        }
    }
    return result;
}
//time:O(nlogn),space:O(n)

// Method 2 -> 2 Count arrays
string caseSort(string s) {
    int n=s.length();
    vector <int> lower(26,0),upper(26,0);
    for (char ch:s) {
        if (islower(ch)) lower[ch-'a']++;
        else upper[ch-'A']++;
    }
    string result=s;
    int lower_index=0,upper_index=0;
    for (int i=0;i<n;i++) {
        if (islower(s[i])) {
            while (lower[lower_index]==0) lower_index++;
            result[i]=lower_index+'a';
            lower[lower_index]--;
        }
        else {
            while (upper[upper_index]==0) upper_index++;
            result[i]=upper_index+'A';
            upper[upper_index]--;
        }
    }
    return result;
}
//time:O(n),space:O(1)