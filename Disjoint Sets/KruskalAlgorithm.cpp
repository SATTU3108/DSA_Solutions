#include <bits/stdc++.h>
using namespace std;

class DSU {
  private:
    vector<int> parent,size;
  public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);
        for (int i=1;i<=n;i++) parent[i]=i;
    }
    int find_set(int v) {
        if (parent[v]==v) return v;
        return parent[v]=find_set(parent[v]);
    }
    bool unite(int a,int b) {
        a=find_set(a);
        b=find_set(b);
        if (a==b) return false;
        if (size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        return true;
    }
};

struct Edge {
    int u,v,weight;
};

int kruskal(int n,vector<Edge> &edges) {
    // sort edges by weight using lambda
    sort(edges.begin(),edges.end(),[](Edge &a,Edge &b) {
        return a.weight<b.weight;
    });
    DSU dsu(n);
    int mst_weight=0,edges_used=0;
    for (auto &e:edges) {
        if (dsu.unite(e.u,e.v)) {
            mst_weight+=e.weight;
            edges_used++;
            if (edges_used==n-1) break; // MST complete
        }
    }
    return mst_weight;
}