/*
You are given a graph with n vertices and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to make the graph connected. If it is not possible to make the graph connected, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

// DFS Approach
void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited) {
    visited[node]=true;
    for (int neighbour:adj[node]) {
        if (!visited[neighbour]) dfs(neighbour,adj,visited);
    }
}
int minOperations(int n,vector<pair<int,int>> &edges) {
    if ((int)edges.size()<n-1) return -1;
    vector<vector<int>> adj(n);
    for (auto &e:edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    vector<bool> visited(n,false);
    int components=0;
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            dfs(i,adj,visited);
            components++;
        }
    }
    return components-1;
}

// BFS Approach
int minOperations(int n,vector<pair<int,int>> &edges) {
    if ((int)edges.size()<n-1) return -1;
    vector<vector<int>> adj(n);
    for (auto &e:edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    vector<bool> visited(n,false);
    int components=0;
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            components++;
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while (!q.empty()) {
                int node=q.front();
                q.pop();
                for (int neighbour:adj[node]) {
                    if (!visited[neighbour]) {
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }
        }
    }
    return components-1;
}

// Disjoint Sets Union (DSU) 
class DSU {
  private:
    vector<int> parent,size;
  public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for (int i=0;i<n;i++) parent[i]=i;
    }
    int find(int v) {
        if (parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }
    void unite(int a,int b) {
        a=find(a);
        b=find(b);
        if (a!=b) {
            if (size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
int minOperations(int n,vector<pair<int,int>> &edges) {
    int m=edges.size();
    if (m<n-1) return -1; // not enough edges
    DSU dsu(n);
    for (auto &e:edges) {
        dsu.unite(e.first,e.second);
    }
    // count connected components
    int components=0;
    for (int i=0;i<n;i++) {
        if (dsu.find(i)==i) components++;
    }
    return components-1;
}