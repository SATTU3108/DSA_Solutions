#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

// Naive Approach -> Inorder Traversal
void inorder(Node *root,vector<int> &sortedInorder) {
    if (root==NULL) return;
    inorder(root->left,sortedInorder);
    sortedInorder.push_back(root->data);
    inorder(root->right,sortedInorder);
}
int minValue(Node *root) {
    if (root==NULL) return -1;
    vector<int> sortedInorder;
    inorder(root,sortedInorder);
    return sortedInorder[0];
}
//time:O(n),space:O(n)

// Expected Approach -> Only traverse left edges
int minValue(Node *root) {
    if (root==NULL) return -1;
    Node *curr=root;
    while (curr->left!=NULL) curr=curr->left;
    return curr->data;
}
//time:O(h),space:O(1)