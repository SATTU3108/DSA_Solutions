#include <bits/stdc++.h>
using namespace std;

/*
Given a Binary Search Tree (with all values unique) and two nodes n1 and n2 (n1 != n2). You may assume that both nodes exist in the tree. Find the Lowest Common Ancestor (LCA) of the given two nodes in the BST.

LCA between two nodes n1 and n2 is defined as the lowest node that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int x) {
        data=x;
        left=right=NULL;
    }
};

// Recursive
Node *LCA (Node *root,Node *n1,Node *n2) {
    if (root==NULL) return NULL;
    // if both n1 and n2 aare smaller than root, go to left subtree
    if (root->data>n1->data && root->data>n2->data) return LCA(root->left,n1,n2);
    // if both n1 and n2 are greater than root, go to right subtree
    if (root->data<n1->data && root->data<n2->data) return LCA(root->right,n1,n2);
    // if nodes n1 and n2 are on the opposite sides, then root is the LCA
    return root;
}
//time:O(h),space:O(h)

// Iterative
Node *LCA(Node *root,Node *n1,Node *n2) {
    while (root!=NULL) {
        if (root->data>n1->data && root->data>n2->data) root=root->left;
        else if (root->data<n1->data && root->data<n2->data) root=root->right;
        else break;
    }
    return root;
}
//time:O(h),space:O(1)