#include <bits/stdc++.h>
using namespace std;

void topoSort(vector<vector<vector<int>>> &adj,vector<int> &topo) {
    int V=adj.size();
    vector<int> indegree(V,0);
    for (int u=0;u<V;u++) {
        for (auto it:adj[u]) indegree[it[0]]++;
    }
    queue<int> q;
    for (int u=0;u<V;u++) {
        if (indegree[u]==0) q.push(u);
    }
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for (auto it:adj[node]) {
            indegree[it[0]]--;
            if (indegree[it[0]]==0) q.push(it[0]);
        }
    }
}
vector<int> longestPath(vector<vector<vector<int>>> &adj,int src) {
    int V=adj.size();
    vector<int> topo;
    topoSort(adj,topo);
    vector<int> dist(V,INT_MIN);
    dist[src]=0;
    for (int i=0;i<V;i++) {
        int u=topo[i];
        for (auto it:adj[u]) {
            int v=it[0];
            int wt=it[1];
            if (dist[u]+wt>dist[v]) dist[v]=dist[u]+wt;
        }
    }
    return dist;
}