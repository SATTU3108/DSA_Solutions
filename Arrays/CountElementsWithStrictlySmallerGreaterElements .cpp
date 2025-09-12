#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.
*/

// Approach 1: 2 pass
int countElements(vector<int>& a) {
    int n=a.size();
    int min_value=a[0],max_value=a[0];
    for (int i=1;i<n;i++) {
        if (a[i]>max_value) max_value=a[i];
        if (a[i]<min_value) min_value=a[i];
    }
    int count=0;
    for (int i=0;i<n;i++) {
        if (a[i]==min_value || a[i]==max_value) continue;
        count++;
    }
    return count;
}
// time:O(n),space:O(1)

// Approach 2: 1 pass
int countElements(vector<int>& a) {
    int n=a.size();
    int min_value=a[0],min_occurences=1;
    int max_value=a[0],max_occurences=1;
    for (int i=1;i<n;i++) {
        if (a[i]<min_value) {
            min_value=a[i];
            min_occurences=1;
        }
        else if (a[i]==min_value) min_occurences++;
        if (a[i]>max_value) {
            max_value=a[i];
            max_occurences=1;
        }
        else if (a[i]==max_value) max_occurences++;
    }
    if (min_value==max_value) return 0;
    return n-min_occurences-max_occurences;
}
//time:O(n),space:O(n)