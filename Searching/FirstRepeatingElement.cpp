#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

Note:- The position you return should be according to 1-based indexing.
*/

// Naive Approach
int firstRepeated(vector<int> &arr) {
    int n=arr.size();
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[j]==arr[i]) return i+1;
        }
    }
    return -1;
}
// Time complexity:O(N^2), Space complexity:O(N)

// Optimal Approach -> Hashing
int firstRepeated(vector<int> &arr) {
    unordered_set <int> st;
    int n=arr.size();
    int min_element=INT_MAX;
    for (int i=n-1;i>=0;i--) {
        if (st.find(arr[i])!=st.end()) min_element=min(min_element,i+1);
        st.insert(arr[i]);
    }
    if (min_element==INT_MAX) return -1;
    else return min_element;
}
// Time complexity:O(N),Space complexity:O(N)
