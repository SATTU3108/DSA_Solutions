/*Check if a graph is tree or not -> a tree has no cycle as well as it is fully connected*/

#include <bits/stdc++.h> 
using namespace std;

// bfs approach
bool hasCycle(vector<vector<int>> &adj,int node,vector<bool> &vis,int parent) {
    vis[node]=true;
    for (int i:adj[node]) {
        if (!vis[i]) {
            if (hasCycle(adj,i,vis,node)) return true;
        }
        else if (i!=parent) return true;
    }
    return false;
}
bool checkgraph(vector<vector<int>> edges, int n, int m) {
    vector<vector<int>> adj(n);
    for (int i=0;i<m;i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> vis(n,false);
    if (hasCycle(adj,0,vis,-1)) return false;
    for (int i=0;i<n;i++) {
        if (!vis[i]) return false;
    }
    return true;
}

// disjoint set approach
class DSU {
    public:
    vector<int> parent,size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for (int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x) {
        if (parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    bool union_sets(int x,int y) {
        int px=find(x),py=find(y);
        if (px==py) return false;
        if (size[px]<size[py]) swap(px,py);
        size[px]+=size[py];
        parent[py]=px;
        return true;
    }
};
bool checkGraph(vector<vector<int>> edges,int n,int m) {
    if (m!=n-1) return false;
    DSU dsu(n);
    for (int i=0;i<n;i++) {
        int u=edges[i][0],v=edges[i][1];
        if (!dsu.union_sets(u,v)) return false;
    }
    return true;
}
