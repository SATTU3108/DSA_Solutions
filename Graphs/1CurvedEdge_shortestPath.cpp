/*
Given an undirected, connected graph with n vertices and m double-edges stored in edges[][] 2-D array. Each double-edge is represented by a tuple (x, y, w1, w2), which indicates that there are two edges between vertices x and y: a straight edge with weight w1 and a curved edge with weight w2.

You are given two vertices a and b and you have to go from a to b through a series of edges such that in the entire path, you can use at most 1 curved edge. Your task is to find the shortest path from a to b satisfying the above condition.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n,vector<vector<pair<int,int>>> &adj,int src) {
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while (!pq.empty()) {
        int dis=pq.top().first,u=pq.top().second;
        pq.pop();
        if (dis>dist[u]) continue;
        for (auto it:adj[u]) {
            int v=it.first,wt=it.second;
            if (dis+wt<dist[v]) {
                dist[v]=dis+wt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
    vector<vector<pair<int,int>>> adj(n);
    vector<tuple<int,int,int>> curved;
    // keep note that vertices are 1-based
    for (int i=0;i<m;i++) {
        int u=edges[i][0]-1,v=edges[i][1]-1,w1=edges[i][2],w2=edges[i][3];
        adj[u].push_back({v,w1});
        adj[v].push_back({u,w1});
        curved.push_back({u,v,w2});
    }
    vector<int> da=dijkstra(n,adj,a-1); // shortest path considering a as source
    vector<int> db=dijkstra(n,adj,b-1); // shortest path considering b as source
    int ans=da[b-1];
    for (int i=0;i<curved.size();i++) {
        int u=get<0>(curved[i]),v=get<1>(curved[i]),wt=get<2>(curved[i]);
        if (da[u]!=INT_MAX && db[v]!=INT_MAX) ans=min(ans,da[u]+wt+db[v]); // path: a->u->curved_path->v->b
        if (da[v]!=INT_MAX && db[u]!=INT_MAX) ans=min(ans,da[v]+wt+db[u]); // path: a->v->curved_path->u->b
    }
    if (ans==INT_MAX) return -1;
    return ans;
}
