#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree. Check whether it is a Binary Search Tree or not. A Binary Search Tree (BST) is a node-based binary tree data structure with the following properties. 

All keys in the left subtree are smaller than the root and all keys in the right subtree are greater.
Both the left and right subtrees must also be binary search trees.
Each key must be distinct.
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int x) {
        data=x;
        left=right=NULL;
    }
};

// Approach -> Ranges of min. and max.values
bool isBSTUtil(Node *node,int min,int max) {
    if (node==NULL) return true;
    if (node->data<min || node->data>max) return false;
    return isBSTUtil(node->left,min,node->data-1) && isBSTUtil(node->right,node->data+1,max);
}
bool isBST(Node *root) {
    return isBSTUtil(root,INT_MIN,INT_MAX);
}
//time:O(n),space:O(h)