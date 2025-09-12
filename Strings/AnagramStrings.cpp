#include <bits/stdc++.h>
using namespace std;

/*
Given two strings, check if two strings are anagrams of each other or not.
*/

// Method 1 -> Sorting
bool checkAnagrams(string str1,string str2) {
    if (str1.length()!=str2.length()) return false;
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    for (int i=0;i<str1.length();i++) {
        if (str1[i]!=str2[i]) return false;
    }
    return true;
}
//time:O(nlogn),space:O(1)

// Method 2 -> Frequency array
bool checkAnagrams(string str1,string str2) {
    if (str1.length()!=str2.length()) return false;
    int freq[26]={0};
    for (int i=0;i<str1.length();i++) {
        freq[str1[i]-'a']++;
        freq[str2[i]-'a']--;
    }
    for (int i=0;i<26;i++) {
        if (freq[i]!=0) return false;
    }
    return true;
}

/*
Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.
*/

int search(string &pat, string &txt) {
    int p=pat.length(),t=txt.length();
    if (p>t) return 0;
    vector<int> freq(26,0),h(26,0);
    int count=0;
    // Frequency of pattern
        for (int i=0;i<p;i++) h[pat[i]-'a']++;
        // Frequency of first window
        for (int i=0;i<p; i++) freq[txt[i]-'a']++;
        // Compare first window
        if (freq==h) count++;
        // Slide the window
        for (int i=p;i<t;i++) {
            freq[txt[i]-'a']++;         // Add new char
            freq[txt[i-p]-'a']--;     // Remove old char
            if (freq==h) count++;
        }
        return count;
    }