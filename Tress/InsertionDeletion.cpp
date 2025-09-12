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
--------INSERTION--------
Given a binary tree and a key, the task is to insert the key into the binary tree at the first position available in level order manner.
*/

Node *insertNode (Node *root,int key) {
    if (root==NULL) {
        root=new Node(key);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *curr=q.front();
        q.pop();
        if (curr->left!=NULL) q.push(curr->left);
        else {
            curr->left=new Node(key);
            return root;
        }
        if (curr->right!=NULL) q.push(curr->right);
        else {
            curr->right=new Node(key);
            return root;
        }
    }
}


/*
---------DELETION----------
Given a binary tree, the task is to delete a given node from it by making sure that the tree shrinks from the bottom (i.e. the deleted node is replaced by the bottom-most and rightmost node). This is different from BST deletion. Here we do not have any order among elements, so we replace them with the last element.
*/

void deleteDeepest(Node *root,Node *dNode) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *curr=q.front();
        q.pop();
        if (curr==dNode) {
            curr=NULL;
            delete (dNode);
            return;
        }
        if (curr->right!=NULL) {
            if (curr->right==dNode) {
                curr->right=NULL;
                delete (dNode);
                return;
            }
            q.push(curr->right);
        }
        if (curr->left!=NULL) {
            if (curr->left==dNode) {
                curr->left=NULL;
                delete (dNode);
                return;
            }
            q.push(curr->left);
        }
    }
}
Node *deletion(Node *root,int key) {
    if (root==NULL) NULL;
    if (root->left==NULL && root->right==NULL) {
        if (root->data==key) return NULL;
        else return root;
    }
    queue<Node*> q;
    q.push(root);
    Node *keyNode;
    Node *curr;
    while (!q.empty()) {
        Node *curr=q.front();
        q.pop();
        if (curr->data==key) keyNode=curr;
        if (curr->left!=NULL) q.push(curr->left);
        if (curr->right!=NULL) q.push(curr->right);
    }
    if (keyNode!=NULL) {
        int x=curr->data;
        keyNode->data=x;
        deleteDeepest(root,curr);
    }
    return root;
}