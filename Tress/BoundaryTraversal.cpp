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

bool isLeaf(Node *root) {
    return (root->left==NULL && root->right==NULL);
}
void addLeftBoundary(Node *root,vector<int> &res) {
    Node *curr=root->left;
    while (curr!=NULL) {
        if (!isLeaf(curr)) res.push_back(curr->data);
        if (curr->left!=NULL) curr=curr->left;
        else curr=curr->right;
    }
}
void addRightBoundary(Node *root,vector<int> &res) {
    Node *curr=root->right;
    while (curr!=NULL) {
        if (!isLeaf(curr)) res.push_back(curr->data);
        if (curr->right!=NULL) curr=curr->right;
        else curr=curr->left;
    }
    reverse(res.begin(),res.end());
}
void addLeaves(Node *root,vector<int> &res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left!=NULL) addLeaves(root->left,res);
    if (root->right!=NULL) addLeaves(root->right,res);
}
vector<int> boundary(Node *root) {
    vector<int> res;
    if (root==NULL) return res;
    if (!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
}