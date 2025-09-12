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

/*Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.*/

bool hasPathSum(Node *root,int target) {
    if (root==NULL) return false;
    if (root->left==NULL && root->right==NULL && root->data==target) return true;
    bool l=hasPathSum(root->left,target-root->data);
    bool r=hasPathSum(root->right,target-root->data);
    return (l||r);
}
//time:O(n),space:O(h)

/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/
void helper(Node *root,int targetSum,vector<vector<int>> &ans,vector<int> &path) {
    if (root==NULL) return;
    path.push_back(root->data);
    if (root->left==NULL && root->right==NULL && root->data==targetSum) ans.push_back(path);
    else {
        helper(root->left,targetSum-root->data,ans,path);
        helper(root->right,targetSum-root->data,ans,path);
    }
    path.pop_back();
}
vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    helper(root,targetSum,ans,path);
    return ans;
}