#include <bits/stdc++.h>
using namespace std;

/*
Given a square matrix mat[][] of size n x n, such that mat[i][j] = 1 means ith person knows jth person, the task is to find the celebrity. A celebrity is a person who is known to all but does not know anyone. Return the index of the celebrity, if there is no celebrity return -1.

Note: Follow 0-based indexing and mat[i][i] will always be 1.
*/

// Naive Approach -> Graphs
int celebrity(vector<vector<int>> &mat) {
    int n=mat.size();
    vector<int> indegree(n,0),outdegree(n,0);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i!=j && mat[i][j]==1) {
                outdegree[i]++;
                indegree[j]++;
            }
        }
    }
    for (int i=0;i<n;i++) {
        if (indegree[i]==n-1 && outdegree[i]==0) return i;
    }
    return -1;
}
//time:O(n^2),space:O(n)

// Better Approach -> Stacks
int celebrity(vector<vector<int>> &mat) {
    int n=mat.size();
    stack<int> st;
    for (int i=0;i<n;i++) st.push(i);
    while (st.size()>1) {
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        // if a knows b
        if (mat[a][b]==1) st.push(b);
        else st.push(a);
    }
    int candidate=st.top();
    st.pop();
    for (int i=0;i<n;i++) {
        if (i==candidate) continue;
        if (mat[candidate][i] || !mat[i][candidate]) return -1;
    }
    return candidate;
}
//time:O(n),space:O(n)

// Optimal Approach -> 2 pointers
int celebrity(vector<vector<int>> &mat) {
    int n=mat.size();
    int i=0,j=n-1;
    while (i<j) {
        if (mat[i][j]==1) i++;
        else j--;
    }
    int candidate=i;
    for (int i=0;i<n;i++) {
        if (i==candidate) continue;
        if (mat[candidate][i] || !mat[i][candidate]) return -1;
    }
    return candidate;
}
//time:O(n),space:O(1)