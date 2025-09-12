#include <bits/stdc++.h>
using namespace std;

/*
Given a Directed Acyclic Graph having V vertices and E edges, your task is to find any Topological Sorted order of the graph.

Topological Sorted order: It is a linear ordering of vertices such that for every directed edge u -> v, where vertex u comes before v in the ordering.
*/

// Kahn's Algorithm -> BFS Approach
vector<int> topoSort(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<int> indegree(V,0);
    for (int i=0;i<V;i++) {
        for (auto it:adj[i]) indegree[it]++;
    }
    queue<int> q;
    for (int i=0;i<V;i++) {
        if (indegree[i]==0) q.push(i);
    }
    vector<int> topo;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for (auto it:adj[node]) {
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }
    if (topo.size()!=V) return {-1}; // directed graph contains a cycle and it is not a DAG
    else return topo;
}