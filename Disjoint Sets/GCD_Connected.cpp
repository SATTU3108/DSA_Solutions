/*
You are given n nodes, each associated with an integer value. Two nodes are considered connected if the greatest common divisor (GCD) of their values is greater than 1. A cluster is defined as a connected component formed under this rule.
*/

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent,size;
    DSU (int n) {
        parent.resize(n);
        size.resize(n,1);
        for (int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x) {
        if (x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int a,int b) {
        a=find(a),b=find(b);
        if (a!=b) {
            if (size[a]<size[b]) swap(a,b);
            size[a]+=size[b];
            parent[b]=a;
        }
    }
};

// naive approach: pairwise gcd check + DSU
vector<int> clusterSizes(vector<int> &nums) {
    int n=nums.size();
    DSU dsu(n);
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (__gcd(nums[i],nums[j])>1) dsu.unite(i,j);
        }
    }
    unordered_map<int,int> comp_size;
    for (int i=0;i<n;i++) {
        int root=dsu.find(i);
        comp_size[root]=dsu.size[root];
    }
    vector<int> res(n);
    for (int i=0;i<n;i++) {
        res[i]=comp_size[dsu.find(i)];
    }
    return res;
}
//time:O(n^2*logM), where M=max(nums[i])

// optimal approach: group by prime factors
vector<int> clusterSizes(vector<int> &nums) {
    int n=nums.size();
    DSU dsu(n);
    unordered_map<int,int> prime_to_index; // key: prime, value: 1st index of prime no.
    for (int i=0;i<n;i++) {
        int x=nums[i];
        int temp=x;
        for (int p=2;p*p<=x;p++) {
            if (x%p==0) {
                if (prime_to_index.find(p)!=prime_to_index.end()) dsu.unite(i,prime_to_index[p]);
                else prime_to_index[p]=i;
                while (x%p==0) x/=p; 
            }
        }
        if (x>1) {
            if (prime_to_index.find(x)!=prime_to_index.end()) dsu.unite(i,prime_to_index[x]);
            else prime_to_index[x]=1;
        }
    }
    unordered_map<int,int> comp_size;
    for (int i=0;i<n;i++) {
        comp_size[dsu.find(i)]=dsu.size[dsu.find(i)];
    }
    vector<int> res(n);
    for (int i=0;i<n;i++) {
        res[i]=comp_size[dsu.find(i)];
    }
    return res;
}
//time:O(nlogM), where M=max(nums[i])
