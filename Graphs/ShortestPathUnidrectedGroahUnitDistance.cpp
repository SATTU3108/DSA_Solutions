#include <bits/stdc++.h>
using namespace std;

/*
Given an Undirected Graph having unit weight, find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.
*/

vector<int> shortestPath(vector<vector<int>> &adj,int src) {
    int V=adj.size();
    vector<int> dist(V,1e9);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for (int v:adj[u]) {
            if (dist[u]+1<dist[v]) {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    for (int i=0;i<V;i++) {
        if (dist[i]==1e9) dist[i]=-1;
    }
    return dist;
}