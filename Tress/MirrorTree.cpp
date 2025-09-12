#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node (int val) {
        data=val;
        left=right=NULL;
    }
};

// DFS (Recursion)
bool areMirrors(Node *root1,Node *root2) {
    if (root1==NULL && root2==NULL) return true;
    if (root1==NULL || root2==NULL) return false;
    return ((root1->data==root2->data) && (areMirrors(root1->left,root2->right) && areMirrors(root1->right,root2->left)));
}
//time:O(n),space:O(h)

// Iterative Method - Stacks
bool areMirrors(Node *root1,Node *root2) {
    if (root1==NULL && root2==NULL) return true;
    if (root1==NULL || root2==NULL) return false;
    queue<Node*> q1,q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty()) {
        Node *curr1=q1.front();
        q1.pop();
        Node *curr2=q2.front();
        q2.pop();
        if (curr1->data!=curr2->data) return false;
        if (curr1->left!=NULL && curr2->right!=NULL) {
            q1.push(curr1->left);
            q2.push(curr2->right);
        }
        else if (curr1->left==NULL || curr2->right==NULL) return false;
        if (curr1->right!=NULL && curr2->left!=NULL) {
            q1.push(curr1->right);
            q2.push(curr2->left);
        }
        else if (curr1->right==NULL && curr2->left==NULL) return false;
    }
    return (q1.empty() && q2.empty());
}
//time:O(n),space:O(w)