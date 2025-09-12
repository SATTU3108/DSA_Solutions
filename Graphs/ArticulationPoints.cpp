#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected graph with V vertices and E edges (edges[][]),
Your task is to return all the articulation points in the graph. If no such point exists, return {-1}.

Note:

An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.
The graph may contain more than one connected component.
*/

// DFS approach
void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited) {
    visited[node]=true;
    for (int neighbour:adj[node]) {
        if (!visited[neighbour]) dfs(neighbour,adj,visited);
    }
}
vector<vector<int>> constructAdj(int V,vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (auto it:edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
}
vector<int> articulationPoints(int V,vector<vector<int>> &edges) {
    vector<vector<int>> adj=constructAdj(V,edges);
    vector<int> res;
    for (int i=0;i<V;i++) {
        vector<bool> visited(V,false);
        visited[i]=true;
        int comp=0;
        for (auto it:adj[i]) {
            if (comp>1) break; // early stop if laready more than 1 component
            if (!visited[it]) {
                dfs(it,adj,visited);
                comp++;
            }
        }
        if (comp>1) res.push_back(i);
    }
    if (res.empty()) return {-1};
    return res;
}
//time:O(V*(V+E)),space:O(V)


// Tarjan's Algorithm
vector<vector<int>> constructAdj(int V,vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (auto it:edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
}
void findPoints(vector<vector<int>> &adj,int u,vector<int> &visited,vector<int> &disc,vector<int> &low,int &time,int parent,vector<int> &isAP) {
    visited[u]=1;
    disc[u]=low[u]=++time;
    int children=0;
    for (int v:adj[u]) {
        if (!visited[v]) {
            children++;
            findPoints(adj,v,visited,disc,low,time,u,isAP);
            low[u]=min(low[u],low[v]);
            if (parent!=-1 && low[v]>=disc[u]) isAP[u]=1;
        }
        else if (v!=parent) low[u]=min(low[u],disc[v]);
    }
    if (parent==-1 && children>1) isAP[u]=1;
}
vector<int> articulationPoints(int V,vector<vector<int>> &edges) {
    vector<vector<int>> adj=constructAdj(V,edges);
    vector<int> disc(V,0),low(V,0),visited(V,0),isAP(V,0);
    int time=0;
    for (int u=0;u<V;u++) {
        if (!visited[u]) {
            findPoints(adj,u,visited,disc,low,time,-1,isAP);
        }
    }
    vector<int> result;
    for (int u=0;u<V;u++) {
        if (isAP[u]) result.push_back(u);
    }
    if (result.empty()) return {-1};
    return result;
}
//time:O(V+E),space:O(V)
