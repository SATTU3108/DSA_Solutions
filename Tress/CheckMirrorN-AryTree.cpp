#include <bits/stdc++.h>
using namespace std;

/*
Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.
*/

// Approach 1 - Hash Map
/*
The main idea is to use a Hash Map or Dictionary to store the relationships between nodes in the first tree. They key in the map is node number and values is a stack of nodes connected with it (or children of it) from left to right. 
We then traverse the second tree and check if the children of the nodes are in reverse order compared to the first tree. This is how we check if the two trees are mirrors.
*/
int checkMirrorTree(int n, int e, int A[], int B[]) {
    unordered_map<int,stack<int>> mp;
    for (int i=0;i<e;i++) {
        mp[A[2*i]].push(A[2*i+1]);
    }
    for (int i=0;i<e;i++) {
        if (mp[B[2*i]].top()!=B[2*i+1]) return 0;
        mp[B[2*i]].pop();
    }
    return 1;
}
//time:O(e),space:O(n+e)


// Approach 2
int checkMirror(int n,int e,int A[],int B[]) {
    vector<stack<int>> s;
    vector<queue<int>> q;
    for (int i=0;i<=n;i++) {
        s.push_back(stack<int>());
        queue<int>queue;
        q.push_back(queue);
    }
    for (int i=0;i<=2*e;i+=2) {
        s[A[i]].push(A[i+1]);
        q[B[i]].push(B[i+1]);
    }
    for (int i=1;i<=n;i++) {
        while (!s[i].empty() && !q[i].empty()) {
            int a=s[i].top();
            s[i].pop();
            int b=q[i].front();
            q[i].pop();if (a!=b) return 0;
        }
    }
    return 1;
}
//time:O(e),space:O(e)