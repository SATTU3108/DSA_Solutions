#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[1..n], for each element at position i (1 <= i <= n), define the following:

left(i) is the closest index j such that j < i and arr[j] > arr[i]. If no such j exists, then left(i) = 0.
right(i) is the closest index k such that k > i and arr[k] > arr[i]. If no such k exists, then right(i) = 0.
LRproduct(i) = left(i) * right(i).
The task is to find the maximum LR product of the given array.
*/

int findMaxLRProduct(vector<int> &arr) {
    int n=arr.size();
    vector<int> left(n,0),right(n,0);
    stack<int> st;
    // Compute left(i) using monotonic stack
    for (int i=0;i<n;i++) {
        while (!st.empty() && arr[st.top()]<=arr[i]) st.pop();
        if (!st.empty()) left[i]=st.top()+1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && arr[st.top()]<=arr[i]) st.pop();
        if (!st.empty()) right[i]=st.top()+1;
        st.push(i);
    } 
    int max_product=0;
    for (int i=0;i<n;i++) {
        max_product=max(max_product,left[i]*right[i]);
    }
    return max_product;
}
//time:O(n),space:O(n)