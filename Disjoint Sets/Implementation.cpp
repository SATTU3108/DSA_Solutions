#include <bits/stdc++.h>
using namespace std;

class DSU {
  private:
    vector<int> parent,sz;
  public:
    DSU(int n) {
        parent.resize(n+1);
        sz.resize(n+1,1);
        for (int i=1;i<=n;i++) parent[i]=i;
    }
    // find with path compression
    int find_set(int v) {
        if (v==parent[v]) return v;
        return parent[v]=find_set(parent[v]);
    }
    // union by size
    void union_sets(int a,int b) {
        a=find_set(a);
        b=find_set(b);
        if (a!=b) {
            if (sz[a]<sz[b]) swap(a,b);
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
    // optional: size of a set
    int get_size(int v) {
        return sz[find_set(v)];
    }
};

int main() {
    int n=5;
    DSU dsu(n);
    dsu.union_sets(1,2);
    dsu.union_sets(2,3);
    dsu.union_sets(4,5);
    cout<<"Find(3) "<<dsu.find_set(3)<<endl;
    cout<<"Find(5) "<<dsu.find_set(5)<<endl;
    dsu.union_sets(3,5);
    cout<<"Find(5) after merging with 3: "<<dsu.find_set(5)<<endl;
    cout<<"Size of set containing 1: "<<dsu.get_size(1)<<endl;
}
