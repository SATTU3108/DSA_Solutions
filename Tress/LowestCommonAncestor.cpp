#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node (int x) {
        data=x;
        left=right=NULL;
    }
};

// Arrays - Storing Path from Root to Node
bool findPath(Node *root,vector<Node*> &path,int k) {
    if (root==NULL) return false;
    path.push_back(root);
    if (root->data==k || findPath(root->left,path,k) || findPath(root->right,path,k)) return true;
    path.pop_back();
    return false;
}
Node *lca(Node *root,int n1,int n2) {
    vector<Node*> path1,path2;
    if (!findPath(root,path1,n1) ||!findPath(root,path2,n2)) return NULL;
    int i;
    for (int i=0;i<path1.size() && i<path2.size();i++) {
        if (path1[i]!=path2[i]) return path1[i-1];
    }
    return path1[i-1];
}
//time:O(n),space:O(n)

// Single Traversal
Node *lca(Node *root,int n1,int n2) {
    if (root==NULL) return NULL;
    if (root->data==n1 || root->data==n2) return root;
    Node *left=lca(root->left,n1,n2);
    Node *right=lca(root->right,n1,n2);
    if (left==NULL) return right;
    else if (right==NULL) return left;
    else return root;
}
//time:O(n),space:O(h)
// The only problem with above approach is that if there is a guarantee that n1 and n2 are present in the tree, then it will give correct result. But if even if one of them is not presemt, it will return true instead of false


/*
Application of LCA:
    1. Shortest distance between pairs of nides in a tree: shortest distance from n1 to n2 is computed as distnace from LCA to n1 + distnace from LCA to n2
*/