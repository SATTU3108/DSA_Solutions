#include <bits/stdc++.h>
using namespace std;

/*
Given a string S, return the sum of beauty of all its substrings.
The beauty of a string is defined as the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of string "aaac" is 3 - 1 = 2.
*/

int beautySum(string s) {
    int n=s.size();
    int sum=0;
    for (int i=0;i<n;i++) {
        int freq[26]={0};
        for (int j=i;j<n;j++) {
            freq[s[j]-'a']++;
            int max_freq=INT_MIN,min_freq=INT_MAX;
            for (int k=0;k<26;k++) {
                if (freq[k]>0) {
                    max_freq=max(max_freq,freq[k]);
                    min_freq=min(min_freq,freq[k]);
                }
            }
            sum+=(max_freq-min_freq);
        }
    }
    return sum;
}