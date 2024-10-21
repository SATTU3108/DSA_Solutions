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

void leftAndRightView(Node *root,vector <int> &leftView,vector <int> &rightView) {
    if (root==NULL) return;
    queue <Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size=q.size();
        for (int i=0;i<size;i++) {
            Node *node=q.front();
            q.pop();
            if (i==0) leftView.push_back(node->data); // we push the first node of that level only in the left view array
            if (i==size-1) rightView.push_back(node->data); //push the last node of that particular level only in the right view array
            if (node->left!=NULL) q.push(node->left);
            if (node->right!=NULL) q.push(node->right);
        }
    }
}