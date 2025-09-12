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
Given two binary trees, the task is to find if both of them are identical or not. Two trees are identical when they have the same data and the arrangement of data is also the same.
*/

// Recursion -> DFS
bool isIdentical(Node *r1,Node *r2) {
    if (r1==NULL && r2==NULL) return true;
    if (r1==NULL || r2==NULL) return false;
    return ((r1->data==r2->data) && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right));
}
//time:O(n),space:O(h)

// BFS
bool isIdentical(Node *r1, Node *r2) {
    if (r1==NULL && r2==NULL) return true;
    if (r1==NULL || r2==NULL) return false;
    queue<Node*> q1,q2;
    q1.push(r1);
    q2.push(r2);
    while (!q1.empty() && !q2.empty()) {
        Node* node1=q1.front(); 
        q1.pop();
        Node* node2=q2.front();
        q2.pop();
        if (node1->data!=node2->data) return false;
        // Check left children
        if (node1->left && node2->left) {
            q1.push(node1->left);
            q2.push(node2->left);
        } else if (node1->left || node2->left) return false;
        // Check right children
        if (node1->right && node2->right) {
            q1.push(node1->right);
            q2.push(node2->right);
        } else if (node1->right || node2->right) return false;
    }

    return q1.empty() && q2.empty();
}
//time:O(n),space:O(w)