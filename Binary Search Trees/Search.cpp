#include <bits/stdc++.h>
using namespace std;

/*
Given a Binary Search Tree and a key value return the node in the BST having data equal to ‘key’ otherwise return nullptr.
*/

struct Node {
    int data;
    Node* left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

// Recursive Method
Node *search(Node *root,int key) {
    if (root==NULL || root->data==key) return root;
    if (root->data<key) return search(root->right,key);
    return search(root->left,key);
}
//time:O(logN),space:O(h)

// Iterative Method
Node* search(Node *root,int x) {
    Node *curr=root;
    while (curr!=NULL) {
        if (curr->data==x) return curr;
        else if (curr->data<x) curr=curr->right;
        else curr=curr->left;
    }
    return NULL;
}
//time:O(logn),space:O(1)