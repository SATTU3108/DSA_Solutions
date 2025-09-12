#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

/*
Given a binary tree, the task is to check if it is a Sum Tree. A Sum Tree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is Sum Tree and the sum of an empty tree can be considered as 0. A leaf node is also considered a Sum Tree.
*/


// Naive Approach -> Check Every Node
int sum(Node *root) {
    if (root==NULL) return 0;
    return root->data+sum(root->left)+sum(root->right);
}
bool isSumTree(Node *root) {
    if (root==NULL || (root->left==NULL && root->right==NULL)) return true;
    int leftSum=sum(root->left);
    int rightSum=sum(root->right);
    return ((root->data==leftSum+rightSum) && isSumTree(root->left) && isSumTree(root->right));
}
//time:O(n^2),space:O(n)

// Efficient Approach
bool isLeaf(Node *node) {
    if (node==NULL) return false;
    if (node->left==NULL && node->right==NULL) return true;
    return false;
}
bool isSumTree(Node *root) {
    int ls,rs;
    // if node is NULL or it's a leaf node, then return true
    if (root==NULL || isLeaf(root)) return true;
    if (isSumTree(root->left) && isSumTree(root->right)) {
        // get the sum of nodes in left subtree
        if (root->left==NULL) ls=0;
        else if (isLeaf(root->left)) ls=root->left->data;
        else ls=2*root->left->data;
        // get the sum of nodes in right subtree
        if (root->right==NULL) rs=0;
        else if (isLeaf(root->right)) rs=root->right->data;
        else rs=2*root->right->data;
        // if root's data is equal to sum of nodes in left and right subtree, then return true or false accordingly
        return (root->data==ls+rs);
    }
    // if either left or right subtree is not sum tree, return false
    return false;
}
//time:O(n),space:O(h)

// Efficient Approach
int sumTree(Node *root) {
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL) return root->data;
    int ls=sumTree(root->left);
    if (ls==-1) return -1;
    int rs=sumTree(root->right);
    if (rs==-1) return -1;
    if (ls+rs==root->data) return ls+rs+root->data;
    else return -1;
}
//time:O(n),space:O(h)