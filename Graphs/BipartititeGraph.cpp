#include <bits/stdc++.h>
using namespace std;

/*
Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, it is called a bipartite graph.
*/

// BFS approach
bool check(vector<vector<int>> &adj,int start,vector<int> color) {
    queue<int> q;
    q.push(start);
    color[start]=0;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        for (auto it:adj[node]) {
            if (color[it]==-1) {
                color[it]=!color[node];
                q.push(it);
            }
            else if (color[it]==color[node]) return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> adj) {
    int V=adj.size();
    vector<int> color(V);
    for (int i=0;i<V;i++) color[i]=-1;
    for (int i=0;i<V;i++) {
        if (color[i]==-1) {
            if (check(adj,i,color)==false) return false;
        }
    }
    return true;
}