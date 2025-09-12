#include <bits/stdc++.h>
using namespace std;

/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labeled with a distinct integer in the range 0 to V - 1. A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node. You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/

// DFS Approach -> Detect cycle in directed graph similar
bool dfsCheck(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &pathVis,vector<bool> &check) {
    vis[node]=true;
    pathVis[node]=true;
    check[node]=0;
    for (auto it:adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(it,adj,vis,pathVis,check)==true) {
                check[node]=0;
                return true;
            }
        }
        else if (pathVis[it]) {
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=false;
    return false;
}
vector<int> eventualSafeStates(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<bool> vis(V,false),pathVis(V,false),check(V,false);
    vector<int> safeNodes;
    for (int i=0;i<V;i++) {
        if (!vis[i]) dfsCheck(i,adj,vis,pathVis,check);
    }
    for (int i=0;i<V;i++) {
        if (check[i]) safeNodes.push_back(i);
    }
    return safeNodes;
}
//time:O(V+E),space:O(V)

// BFS Approach -> Topological Sorting
vector<int> eventualSafeStates(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<vector<int>> adjRev(V);
    vector<int> indegree(V,0);
    for (int i=0;i<V;i++) {
        for (auto it:adj[i]) {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i=0;i<V;i++) {
        if (indegree[i]==0) q.push(i);
    }
    vector<int> safeNodes;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        safeNodes.push_back(node);
        for (auto it:adjRev[node]) {
            indegree[it]--;
            if (indegree[it]==0) q.push(it);
        }
    }
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
}