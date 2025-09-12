#include <bits/stdc++.h>
using namespace std;

/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/



// Approach -> Trimming Leaves Layer by Layer
/*
The root of the Minimum Height Tree (MHT) lies in the "center" of the graph.

Leaves (degree = 1 nodes) can never be centers because they maximize height.

Process (Like Onion Peeling 🧅):

Start with all leaves (degree = 1).

Remove them → graph shrinks.

New leaves emerge.

Repeat until only 1 or 2 nodes remain → these are the centers (roots of MHT).

Why 1 or 2 nodes?

A tree has either one center (odd diameter) or two centers (even diameter).
*/

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (edges.empty()) return {0};
    vector<vector<int>> adj(n);
    vector<int> degree(n,0);
    for (auto &it:edges) {
        int u=it[0],v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    queue<int> q;
    for (int i=0;i<n;i++) {
        if (degree[i]==1) q.push(i);
    }
    int remaining=n;
    while (remaining>2) {
        int sz=q.size();
        remaining-=sz;
        for (int i=0;i<sz;i++) {
            int leaf=q.front();
            q.pop();
            for (int neighbour:adj[leaf]) {
                degree[neighbour]--;
                if (degree[neighbour]==1) q.push(neighbour);
            }
        }
    }
    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}