#include <bits/stdc++.h>
using namespace std;

/*
Given a Binary Search Tree and a key, return the ceiling of the given key in the Binary Search Tree.

Ceiling of a value refers to the value of the smallest node in the Binary Search Tree that is greater than or equal to the given key.
If the ceiling node does not exist, return nullptr.
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

int findCeil(Node *root,int key) {
    int ceil=-1;
    while (root!=NULL) {
        if (root->data==key) {
            ceil=root->data;
            return ceil;
        }
        if (key>root->data) root=root->right;
        else {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}
//time:O(logn),space:O(1)
