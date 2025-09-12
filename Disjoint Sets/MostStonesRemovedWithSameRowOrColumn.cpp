#include <bits/stdc++.h>
using namespace std;

/*
There are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have at most one stone.

You need to remove some stones. 

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array of stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the maximum possible number of stones that you can remove.
*/

class DSU {
  private:
    vector<int> parent,size;
  public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i=0;i<n;i++) {
            parent[i]=i; // initially, each nodes is its own parent
            size[i]=1;
        }
    }
    // path compression
    int find(int v) {
        if (parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }
    void unite(int a,int b) {
        a=find(a);
        b=find(b);
        if (a==b) return; // akready in the same component
        if (size[a]<size[b]) swap(a,b); // attach smaller tree under big one
        parent[b]=a;
        size[a]+=size[b];
    }
};
int removeStones(vector<vector<int>> &stones) {
    int n=stones.size();
    int max_row=0,max_col=0;
    // finding maximum row and column values to size DSU properly
    for (auto &s:stones) {
        max_row=max(max_row,s[0]);
        max_col=max(max_col,s[1]);
    }
    // offest ensures that the avlues of row and column id's don't overlap for any stone
    int offset=max_row+1;
    DSU dsu(offset+max_col+1);
    unordered_set<int> used; // track only nodes that appear
    for (auto &s:  stones) {
        int r=s[0],c=s[1]+offset;
        dsu.unite(r,c);
        used.insert(r);
        used.insert(c);
    }
    // count connected components
    int count=0;
    for (int node:used) {
        if (dsu.find(node)==node) count++;
    }
    // answer=total stones - # connected components, because in each component, we can keep 1 stone and remove the rest
    return n-count;
}