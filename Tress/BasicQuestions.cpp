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
--------SIZE---------
*/

int getSize(Node *root) {
    if (root==NULL) return 0;
    return 1+getSize(root->left)+getSize(root->right);
}
//time:O(n),space:O(h)

/*
-------MAXIMUM--------
*/

int findMax(Node *root) {
    if (root==NULL) return INT_MIN;
    int res=root->data;
    int lres=findMax(root->left);
    int rres=findMax(root->right);
    return max({res,lres,rres});
}
//time:O(n),space:O(h)