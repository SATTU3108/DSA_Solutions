#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[], the task is to find the sum of the maximum elements of every possible non-empty sub-arrays of the given array arr[].
*/

// Naive Method -> Generate All Subarrays
int sumOfMax(vector<int> &arr) {
    int n=arr.size(),res=0;
    for (int i=0;i<n;i++) {
        int curr_max=arr[i];
        for (int j=i;j<n;j++) {
            curr_max=max(curr_max,arr[j]);
            res+=curr_max;
        }
    }
    return res;
}
//time:O(n^2),space:O(1)

// Expected Approach -> Monotonic Stack
int sumOfMax(vector<int> &arr) {
    int n=arr.size(),res=0;
    stack<int> st;
    vector<int> left(n);
    for (int i=0;i<n;i++) {
        while (!st.empty() && arr[st.top()]<arr[i]) st.pop();
        if (st.empty()) left[i]=i+1;
        else left[i]=i-st.top();
        st.push(i);
    }
    vector<int> right(n);
    while (!st.empty()) st.pop();
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && arr[st.top()]<arr[i]) st.pop();
        if (st.empty()) right[i]=n-i;
        else right[i]=st.top()-i;
        st.push(i);
    }
    for (int i=0;i<n;i++) res+=arr[i]*left[i]*right[i];
    return res;
}
//time:O(n),space:O(n)