#include <bits/stdc++.h>
using namespace std;

/*
The stock span problem is a financial problem where we have a series of daily price quotes for a stock denoted by an array arr[] and the task is to calculate the span of the stock's price for all days. 

The span of the stock's price on ith day represents the maximum number of consecutive days leading up to ith day (including the current day) where the stock's price was less than or equal to its price on day i.
*/

// Naive Approach -> Nested Loops
vector<int> calculateSpan(vector<int> &arr) {
    int n=arr.size();
    vector<int> span(n,1);
    for (int i=1;i<n;i++) {
        for (int j=i-1;(j>=0) && arr[j]<=arr[i];j--) span[i]++;
    }
    return span;
}
//time:O(n^2),space:O(1)

// Expected Approach -> Stacks
vector<int> calculateSpan(vector<int> &arr) {
    int n=arr.size();
    vector<int> span(n);
    stack<int> st;
    for (int i=0;i<n;i++) {
        while (!st.empty() && arr[st.top()]<=arr[i]) st.pop();
        if (st.empty()) span[i]=i+1;
        else span[i]=i-st.top();
        st.push(i);
    }
    return span;
} 
//time:O(n),space:O(n)