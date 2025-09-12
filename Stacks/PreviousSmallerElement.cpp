#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the nearest smaller number for every element such that the smaller element is on the left side.
*/

// Naive Approach -> Nested Loops
vector<int> leftSmaller(vector<int> arr) {
    int n=arr.size();
    vector<int> res(n,-1);
    for (int i=1;i<n;i++) {
        for (int j=(i-1);j>=0;j--) {
            if (arr[j]<arr[i]) {
                res[i]=arr[j];
                break;
            }
        }
    }
    return res;
}
//time:O(n^2),space:O(1)

// Efficient Approach -> Stacks
vector<int> leftSmaller(vector<int> arr) {
    int n=arr.size();
    vector<int> res(n);
    stack<int> st;
    for (int i=0;i<n;i++) {
        while (!st.empty() && st.top()>=arr[i]) st.pop();
        if (st.empty()) res[i]=-1;
        else res[i]=st.top();
        st.push(arr[i]);
    }
    return res;
}
//time:O(n),space:O(n)