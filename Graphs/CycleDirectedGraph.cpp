#include <bits/stdc++.h>
using namespace std;

// DFS approach
bool dfsCheck(vector<vector<int>> &adj,int node,vector<bool> &vis,vector <bool> &pathVis) {
    vis[node]=true;
    pathVis[node]=true;
    for (auto it:adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(adj,it,vis,pathVis)) return true;
        }
        else if (pathVis[it]) return true;
    }
    pathVis[node]=false;
    return false;
}
bool isCycle(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<bool> vis(V,false);
    vector<bool> pathVis(V,false);
    for (int i=0;i<V;i++) {
        if (!vis[i]) {
            if (dfsCheck(adj,i,vis,pathVis)) return true;
        }
    }
    return false;
}
//time:O(V+E),space:O(V)

// Topo-sort approach
bool isCyclic(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<int> indegree(V,0);
    queue<int> q;
    for (int u=0;u<V;u++) {
        for (int v:adj[u]) indegree[v]++;
    }
    for (int u=0;u<V;u++) {
        if (indegree[u]==0) q.push(u);
    }
    int size=0;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        size++;
        for (int v:adj[u]) {
            indegree[v]--;
            if (indegree[v]==0) q.push(v);
        }
    }
    if (size!=V) return false;
    return true;
}
//time:O(V+E),space:O(V)

// Coloring approach
bool dfsutil(vector<vector<int>> &adj,int u,vector<int> &color) {
    const int gray=1,black=2;
    color[u]=gray;
    for (int v:adj[u]) {
        if (color[v]==gray) return true;
        if (color[v]==0 && dfsutil(adj,v,color)) return true;
    }
    color[u]=black;
    return false;
}
bool isCyclic(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<int> color(V,0);
    for (int i=0;i<V;i++) {
        if (color[i]==0) {
            if (dfsutil(adj,i,color)) return true;
        }
    }
    return false;
}
//time:O(V+E),space:O(V)