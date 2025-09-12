#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected connected graph with v nodes, and e edges, with adjacency list adj. We need to write a function that returns 2 if the graph contains an eulerian circuit or cycle, else if the graph contains an eulerian path, returns 1, otherwise, returns 0.

A graph is said to be Eulerian if it contains an Eulerian Cycle, a cycle that visits every edge exactly once and starts and ends at the same vertex.
If a graph contains an Eulerian Path, a path that visits every edge exactly once but starts and ends at different vertices, it is called Semi-Eulerian.
*/

// DFS approach
void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited) {
    visited[node]=true;
    for (int neighbour:adj[node]) {
        if (!visited[neighbour]) dfs(neighbour,adj,visited);
    }
}
int isEulerCircuit(int V,vector<vector<int>> &adj) {
    vector<bool> visited(V,false);
    int start=-1;
    for (int i=0;i<V;i++) {
        if (adj[i].size()>0) {
            start=i;
            break;
        }
    }
    // No edges: graph is trivially Eulerian
    if (start==-1) return 2;
    // DFS from first non-zero degree vertex
    dfs(start,adj,visited);
    // Check is all non-zero degree vertices are connected
    for (int i=0;i<V;i++) {
        if (adj[i].size()>0 && !visited[i]) return 0; // Not connected
    }
    // Count vertices with odd degree
    int odd=0;
    for (int i=0;i<V;i++) {
        if (adj[i].size()%2!=0) odd++;
    }
    // Apply Eulerian rules
    if (odd==0) return 2;
    else if (odd==2) return 1;
    else return 0;
}
//time:O(V+E),space:O(V+E)