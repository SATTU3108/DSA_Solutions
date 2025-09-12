#include <bits/stdc++.h>
using namespace std;

/*
Given a BST, the task is to insert a new node in this BST.
*/

struct Node {
    int data;
    Node *left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

Node *insert(Node *root,int x) {
    Node *temp=new Node (x);
    if (root==NULL) return temp;
    Node *parent=NULL,*curr=root;
    while (curr!=NULL) {
        parent=curr;
        if (curr->data>x) curr=curr->left;
        else if (curr->data<x) curr=curr->right;
        else return root;
    }
    if (parent->data>x) parent->left=temp;
    else parent->right=temp;
    return root;
}
//time:O(h),space:O(1)