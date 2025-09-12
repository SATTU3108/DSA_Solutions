#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected graph, the task is to determine if cycle is present in it or not.
*/

// BFS approach
bool bfs(vector<vector<int>> &adj,int start,vector<bool> &visited) {
    queue<pair<int,int>> q;
    q.push({start,-1});
    visited[start]=true;
    while (!q.empty()) {
        auto [node,parent]=q.front();
        q.pop();
        for (int neighbour:adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour]=true;
                q.push({neighbour,node});
            }
            else if (neighbour!=parent) return true;
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<bool> visited(V,false);
    for (int i=0;i<V;i++) {
        if (!visited[i]) {
            if (bfs(adj,i,visited)) return true;
        }
    }
    return false;
}

// DFS approach
bool isCycleUtil(vector<vector<int>> &adj,vector<bool> &visited,int v,int parent) {
    visited[v]=true;
    for (int i:adj[v]) {
        if (!visited[i]) {
            if (isCycleUtil(adj,visited,i,v)) return true;
        }
        else if (i!=parent) return true;
    }
    return false;
}
bool isCycle(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<bool> visited(V,false);
    for (int i=0;i<V;i++) {
        if (!visited[i]) {
            if (isCycleUtil(adj,visited,i,-1)) return true;
        }
    }
    return false;
}