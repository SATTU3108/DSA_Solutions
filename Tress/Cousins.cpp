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
Given a binary tree (having distinct node values) root and two node values. The task is to check whether the two nodes with values a and b are cousins.
Note: Two nodes of a binary tree are cousins if they have the same depth with different parents.
*/

// DFS
bool isSibling(Node *root,int a,int b) {
    if (root==NULL) return false;
    if (root->left && root->right) {
        int l=root->left->data;
        int r=root->right->data;
        if ((l==a && r==b) || (l==b && r==a)) return true;
    }
    return isSibling(root->left,a,b) || isSibling(root->right,a,b);
}
int level(Node *root,int key,int lev) {
    if (root==NULL) return 0;
    if (root->data==key) return lev;
    int l=level(root->left,key,lev+1);
    if (l!=0) return l;
    return level(root->right,key,lev+1);
}
bool isCousins(Node* root, int x, int y) {
    if (x==y) return false;
    int x_level=level(root,x,1);
    int y_level=level(root,y,1);
    if (x_level==0 || y_level==0) return false;
    if (x_level==y_level && !isSibling(root,x,y)) return true;
    else return false;
}
//time:O(n),space:O(h)
