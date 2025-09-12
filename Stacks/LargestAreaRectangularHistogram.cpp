#include <bits/stdc++.h>
using namespace std;

// Naive Approach 
int getMaxArea(vector<int> &arr) {
    int n=arr.size(),res=0;
    for (int i=0;i<n;i++) {
        // Consider the current element as the minimum height bar
        int curr=arr[i];
        // Traverse left while we have a greater height bar
        for (int j=i-1;j>=0 && arr[j]>=arr[i];j--) curr+=arr[i];
        // Traverse right while we have a greater height bar
        for (int j=i+1;j<n && arr[j]>=arr[i];j++) curr+=arr[i];
        res=max(res,curr);
    }
    return res;
}
//time:O(n^2),space:O(1)

// Efficient Approach -> Using 2 Stacks
vector<int> nextSmaller(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n, n);
    stack<int> st;
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && arr[i]<=arr[st.top()]) st.pop();
        if (!st.empty()) res[i]=st.top();
        st.push(i);
    }
    return res;
}
vector<int> prevSmaller(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n,-1);
    stack<int> st;
    for (int i=0;i<n;i++) {
        while (!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if (!st.empty()) res[i]=st.top();
        st.push(i);
    }
    return res;
}
int getMaxArea(vector<int> &arr) {
    int n=arr.size();
    vector<int> left=prevSmaller(arr);
    vector<int> right=nextSmaller(arr);
    int max_area=0;
    for (int i=0;i<n;i++) {
        int width=right[i]-left[i]-1;
        max_area=max(max_area,arr[i]*width);
    }   
    return max_area;
}
//time:O(n),space:O(n)