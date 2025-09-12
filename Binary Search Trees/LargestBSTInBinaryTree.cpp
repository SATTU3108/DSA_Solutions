#include <bits/stdc++.h>
using namespace std;

/*
Given a Binary Tree, the task is to return the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of the whole tree.
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

// Naive approach -> recursion
bool isValidBST(Node *root,int minValue,int maxValue) {
    if (root==NULL) return true;
    if (root->data<=minValue || root->data>=maxValue) return false;
    return isValidBST(root->left,minValue,root->data) && isValidBST(root->right,root->data,maxValue);
}
int size(Node *root) {
    if (root==NULL) return 0;
    return 1+size(root->left)+size(root->right);
}
int largestBST(Node *root) {
    if (root==NULL) return 0;
    if (isValidBST(root,INT_MIN,INT_MAX)) return size(root);
    return max(largestBST(root->left),largestBST(root->right)); 
}
//time:O(n^2),space:O(n)

// Expected approach -> binary search tree property