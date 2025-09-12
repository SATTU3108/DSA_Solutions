#include <bits/stdc++.h>
using namespace std;

/*
Given a Directed Acyclic Graph (DAG) with V vertices and a list of directed edges represented by a 2D array edgeList[][], where each edge is defined as (u, v) meaning there is a directed edge from u to v.
The task is to add the maximum number of edges to the given DAG such that it remains a DAG (i.e., no cycles are introduced). Print all the newly added edges in the format a-b, meaning there is a directed edge from a to b.
Note: The resulting graph should be such that adding even one more edge would create a cycle.
*/

void topoSort(vector<vector<int>> &adj,vector<int> &topo) {
    int V=adj.size();
    vector<int> indegree(V,0);
    for (int i=0;i<V;i++) {
        for (auto it:adj[i]) indegree[it]++;
    }
    queue<int> q;
    for (int i=0;i<V;i++) {
        if (indegree[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for (int v:adj[u]) {
            indegree[v]--;
            if (indegree[v]==0) q.push(v);
        }
    }
}
vector<vector<int>> addEdgesToDAG(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<int> topo;
    topoSort(adj,topo);
    vector<vector<int>> result;
    for (int i=0;i<V;i++) {
        for (int j=i+1;j<V;j++) {
            int u=topo[i];
            int v=topo[j];
            bool flag=false;
            for (int neighbour:adj[u]) {
                if (neighbour==v) {
                    flag=true;
                    break;
                }
            }
            if (!flag) result.push_back({u,v});
        }
    }
    return result;
}