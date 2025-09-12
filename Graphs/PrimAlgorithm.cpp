#include <bits/stdc++.h>
using namespace std;

int spanningTree(vector<vector<pair<int,int>>> adj) {
    int V=adj.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(V,false);
    int res=0;
    pq.push({0, 0}); // (weight, vertex)
    while (!pq.empty()) {
        auto [wt, u]=pq.top(); // (weight, vertex)
        pq.pop();
        if (visited[u]) continue;
        res+=wt;
        visited[u]=true;
        for (auto [v,w]:adj[u]) {
            if (!visited[v]) pq.push({w, v}); // Push (weight, vertex)
        }
    }
    return res;
}
