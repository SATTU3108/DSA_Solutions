#include <bits/stdc++.h>
using namespace std;

/*
Given a weighted graph with V vertices and E edges, along with a source vertex src, the task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. In the presence of a negative weight cycle, return -1 to signify that shortest path calculations are not feasible.
*/

vector<int> bellmanFord(int V,vector<vector<int>> &edges,int src) {
    vector<int> dist(V,1e8);
    dist[src]=0;
    for (int i=0;i<V-1;i++) {
        for (auto edge:edges) {
            int u=edge[0],v=edge[1],wt=edge[2];
            if (dist[u]!=1e8 && dist[u]+wt<dist[v]) {
                dist[v]=dist[u]+wt;
            }
        }
    }
    // Vth relaxation to check negative cycle
    for (auto edge:edges) {
        int u=edge[0],v=edge[1],wt=edge[2];
        if (dist[u]!=1e8 && dist[u]+wt<dist[v]) return {-1};
    }
    return dist;
}
//time:O(V*E),space:O(V)