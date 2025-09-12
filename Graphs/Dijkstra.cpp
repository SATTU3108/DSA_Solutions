#include <bits/stdc++.h>
using namespace std;

/*
Given a weighted undirected graph represented as an edge list and a source vertex src, find the shortest path distances from the source vertex to all other vertices in the graph. The graph contains V vertices, numbered from 0 to V - 1.

Note: The given graph does not contain any negative edge.
*/

vector<int> dijkstra(vector<vector<vector<int>>> &adj,int src) {
    int V=adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    pq.push({src,0});
    while (!pq.empty()) {
        int node=pq.top().first;
        int dis=pq.top().second;
        pq.pop();
        for (auto it:adj[node]) {
            int v=it[0],wt=it[1];
            if (dis+wt<dist[v]) {
                dist[v]=dis+wt;
                pq.push({v,dis+wt});
            }
        }
    }
    return dist;
}
//time:O(ElogV),space:O(E+V)