#include <bits/stdc++.h>
using namespace std;

/*
BFS from given source
*/

vector<int> bfsSource(vector<vector<int>> &adj,int s=0) {
    int V=adj.size();
    vector<int> res;
    queue<int> q;
    vector<bool> visited(V,false);
    visited[s]=0;
    q.push(s);
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        for (int x:adj[curr]) {
            if (!visited[x]) {
                visited[x]=true;
                q.push(x);
            }
        }
    }
    return res;
}

/*
BFS of discinnected graph
*/

void bfsHelper(vector<vector<int>> &adj,int s,vector<bool> &visited,vector<int> &res) {
    queue <int> q;
    q.push(s);
    visited[s]=true;
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        for (int x:adj[curr]) {
            if (!visited[x]) {
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
vector<int> bfsDisconnected(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<int> res;
    vector<bool> visited(V,false);
    for (int i=0;i<V;i++) {
        if (!visited[i]) bfsHelper(adj,i,visited,res);
    }
    return res;
}

/*
DFS from given source
*/
void dfsRec(vector<vector<int>> &adj,vector<bool> &visited,vector<int> &res,int s) {
    visited[s]=true;
    res.push_back(s);
    for (int i:adj[s]) {
        if (!visited[i]) dfsRec(adj,visited,res,i);
    }
}
vector<int> dfs(vector<vector<int>> &adj) {
    int V=adj.size();
    vector<bool> visited(V,false);
    vector<int> res;
    dfsRec(adj,visited,res,0);
    return res;
}