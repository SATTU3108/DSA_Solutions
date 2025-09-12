#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int x) {
        data=x;
        left=right=NULL;
    }
};

int helper(Node *root,int &res) {
    if (root==NULL) return 0;
    int l=max(0,helper(root->left,res));
    int r=max(0,helper(root->right,res));
    res=max(res,root->data+l+r); // res is like the global variable
    return root->data+max(l,r); // it returns the maximum sum possible rooted at that node
}
int findMaxSum(Node *root) {
    int res=root->data;
    helper(root,res);
    return res;
}